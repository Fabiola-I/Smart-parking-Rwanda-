#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <ArduinoJson.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13 // Optional: Use an LED to indicate object detection
#define SERVO_PIN 8 // Servo motor pin
#define SS_PIN 10
#define RST_PIN 9

#define IR_SENSOR_1 4
#define IR_SENSOR_2 5
#define IR_SENSOR_3 6
#define IR_SENSOR_4 7

String validUIDs[] = {
  "77 B6 0E 17", 
  "33 7F 9E 1A", 
  "19 BC B2 D4", 
  "63 41 32 F8", 
  "3A 4B 5C 6D"
}; // Add your valid RFID card UIDs here

byte lock = 0;

long duration;
int distance;
int thresholdDistance = 10; // Distance threshold in centimeters
int gateOpenDistance = 5;  // Distance threshold to open gate in centimeters
unsigned long openTime = 0;
unsigned long closeDelay = 3000; // Close the gate after 3 seconds of no object detected

unsigned long previousMillis = 0;
const long interval = 2000; // Interval to refresh parking slot status

unsigned long entranceTimes[4] = {0, 0, 0, 0};
unsigned long exitTimes[4] = {0, 0, 0, 0};
bool statuses[4] = {false, false, false, false};

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT); // Optional: Set LED pin as output
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);
  pinMode(IR_SENSOR_3, INPUT);
  pinMode(IR_SENSOR_4, INPUT);

  myServo.attach(SERVO_PIN); // Attach the servo to the pin
  myServo.write(0); // Initial position of the servo (closed gate)

  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  SPI.begin();
  rfid.PCD_Init();
}

void loop() {
  unsigned long currentMillis = millis();
  
  // Clear the trigPin
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Check if the distance is within the threshold distance
  if (distance <= thresholdDistance) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED
    openTime = millis(); // Reset the timer when object detected
    
    // Check if parking is full
    if (countCarsParked() == 4) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Parking Full ");
      lcd.setCursor(0, 1);
      lcd.print(" Can not Enter  ");
      delay(2000); // Display message for 2 seconds
    } else {
      // Check if the distance is within the gate open distance
      if (distance <= gateOpenDistance && distance > 0) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  Welcome!!! ");
        lcd.setCursor(0, 1);
        lcd.print(" Tap Your Card  ");

        // Check if an RFID card is present
        if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
          String ID = "";
          for (byte i = 0; i < rfid.uid.size; i++) {
            ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
            ID.concat(String(rfid.uid.uidByte[i], HEX));
          }
          ID.toUpperCase();

          if (isValidUID(ID) && lock == 0) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" Thank You!!! ");
            servoOpenGate();
            delay(2000); // Display "Thank You!!!" for 2 seconds
            lock = 1;
          } else if (isValidUID(ID) && lock == 1) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" Thank You!!! ");
            servoCloseGate();
            delay(2000); // Display "Thank You!!!" for 2 seconds
            lock = 0;
          } else {
            lcd.clear();
            lcd.setCursor(0, 1);
            lcd.print("Invalid Card     ");
            delay(2000);
          }
          rfid.PICC_HaltA();
          rfid.PCD_StopCrypto1();
        }
      }
    }
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
    
    // Close the gate after a certain delay
    if (millis() - openTime > closeDelay && openTime != 0) {
      servoCloseGate();
      openTime = 0; // Reset the openTime to prevent continuous closing
    }
  }

  // Refresh the parking slot status every 2 seconds
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    updateParkingStatus();
    displayParkingSlots();
  }

  // Send JSON data to NodeMCU
  sendDataToNodeMCU();

  // Small delay before the next measurement
  delay(500);
}

void sendDataToNodeMCU() {
  DynamicJsonDocument doc(1024);

  doc["slot1"] = statuses[0] ? "Available" : "Not Available";
  doc["slot2"] = statuses[1] ? "Available" : "Not Available";
  doc["slot3"] = statuses[2] ? "Available" : "Not Available";
  doc["slot4"] = statuses[3] ? "Available" : "Not Available";

  int carsParked = countCarsParked();
  doc["cars_parked"] = carsParked;

  // Add parking times for each slot
  for (int i = 0; i < 4; i++) {
    char slotTimeKey[15];
    snprintf(slotTimeKey, sizeof(slotTimeKey), "slot%d_time", i + 1);
    doc[slotTimeKey] = getParkingTime(i);
  }

  String jsonData;
  serializeJson(doc, jsonData);

  Serial.println(jsonData); // Send JSON data to Arduino Serial Monitor
}

void servoOpenGate() {
  myServo.write(90); // Open gate (adjust the angle as needed)
  delay(5000); // Keep the gate open for 5 seconds (adjust as needed)
}

void servoCloseGate() {
  myServo.write(0); // Close gate
}

void displayParkingSlots() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("S1:");
  lcd.print(statuses[0] ? "P.AV" : "NO.P");
  lcd.setCursor(8, 0);
  lcd.print("S2:");
  lcd.print(statuses[1] ? "P.AV" : "NO.P");

  lcd.setCursor(0, 1);
  lcd.print("S3:");
  lcd.print(statuses[2] ? "P.AV" : "NO.P");
  lcd.setCursor(8, 1);
  lcd.print("S4:");
  lcd.print(statuses[3] ? "P.AV" : "NO.P");

  int carsParked = countCarsParked();
  lcd.setCursor(0, 2);
  lcd.print("Cars Parked: ");
  lcd.print(carsParked);

  // Print status to the Serial Monitor
  Serial.print("Slot 1: ");
  Serial.println(statuses[0] ? "Available" : "Not Available");
  Serial.print("Slot 2: ");
  Serial.println(statuses[1] ? "Available" : "Not Available");
  Serial.print("Slot 3: ");
  Serial.println(statuses[2] ? "Available" : "Not Available");
  Serial.print("Slot 4: ");
  Serial.println(statuses[3] ? "Available" : "Not Available");
  Serial.print("Cars Parked: ");
  Serial.println(carsParked);
}

bool isValidUID(String ID) {
  for (String validUID : validUIDs) {
    if (ID.substring(1) == validUID) {
      return true;
    }
  }
  return false;
}

void updateParkingStatus() {
  for (int i = 0; i < 4; i++) {
    int sensorPin = IR_SENSOR_1 + i;
    bool status = digitalRead(sensorPin);

    if (status && !statuses[i]) {
      entranceTimes[i] = millis();
    } else if (!status && statuses[i]) {
      exitTimes[i] = millis();
    }
    statuses[i] = status;
  }
}

int countCarsParked() {
  int count = 0;
  for (int i = 0; i < 4; i++) {
    if (!statuses[i]) {
      count++;
    }
  }
  return count;
}

String getParkingTime(int slot) {
  unsigned long currentMillis = millis();
  unsigned long elapsedTime = 0;

  if (!statuses[slot]) { // Slot is "Not Available"
    elapsedTime = currentMillis - entranceTimes[slot];
  } else if (entranceTimes[slot] != 0 && exitTimes[slot] != 0) {
    elapsedTime = exitTimes[slot] - entranceTimes[slot];
  }

  unsigned long hours = elapsedTime / 3600000;
  unsigned long minutes = (elapsedTime % 3600000) / 60000;
  unsigned long seconds = (elapsedTime % 60000) / 1000;

  char timeStr[20];
  snprintf(timeStr, sizeof(timeStr), "%02lu:%02lu:%02lu", hours, minutes, seconds);

  return String(timeStr);
}
