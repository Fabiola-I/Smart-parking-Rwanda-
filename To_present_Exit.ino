#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define TRIG_PIN 2
#define ECHO_PIN 3
#define LED_PIN 13 // Optional: Use an LED to indicate object detection
#define SERVO_PIN 4 // Servo motor pin
#define SS_PIN 10
#define RST_PIN 9

String validUIDs[] = {
  "77 B6 0E 17", 
  "33 7F 9E 1A", 
  "19 BC B2 D4", // Example additional cards
  "63 41 32 F8", 
  "3A 4B 5C 6D"
}; // Add your valid RFID card UIDs here

unsigned long cardTimes[5] = {0, 0, 0, 0, 0}; // Store entrance times for cards
byte lock = 0;
long duration;
int distance;
int thresholdDistance = 5; // Distance threshold in centimeters
int gateOpenDistance = 3;  // Distance threshold to open gate in centimeters
unsigned long openTime = 0;
unsigned long closeDelay = 3000; // Close the gate after 3 seconds of no object detected

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;
MFRC522 rfid(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT); // Optional: Set LED pin as output

  myServo.attach(SERVO_PIN); // Attach the servo to the pin
  myServo.write(0); // Initial position of the servo (closed gate)

  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  SPI.begin();
  rfid.PCD_Init();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Welcome at exit");
  lcd.setCursor(0, 1);
  lcd.print("gate");
}

void loop() {
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

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Tap Your Card  ");
    lcd.setCursor(0, 1);
    lcd.print(" Verify Payment ");

    // Check if an RFID card is present
    if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
      String ID = "";
      for (byte i = 0; i < rfid.uid.size; i++) {
        ID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
        ID.concat(String(rfid.uid.uidByte[i], HEX));
      }
      ID.toUpperCase();

      if (isValidUID(ID)) {
        unsigned long entranceTime = getEntranceTime(ID);
        unsigned long exitTime = millis();
        unsigned long timeSpent = exitTime - entranceTime;

        float amount = calculateAmount(timeSpent);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(" Amount: $");
        lcd.print(amount);
        delay(5000);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Tap Card to Pay");

        if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
          String paymentID = "";
          for (byte i = 0; i < rfid.uid.size; i++) {
            paymentID.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
            paymentID.concat(String(rfid.uid.uidByte[i], HEX));
          }
          paymentID.toUpperCase();

          if (ID == paymentID) {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Payment Success");
            delay(2000);
            servoOpenGate();
            delay(5000); // Keep the gate open for 5 seconds (adjust as needed)
            servoCloseGate();
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("  Welcome at exit");
            lcd.setCursor(0, 1);
            lcd.print("   gate");
          } else {
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Payment Failed");
            delay(2000);
          }
        }
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Invalid Card");
        delay(2000);
      }
      rfid.PICC_HaltA();
      rfid.PCD_StopCrypto1();
    }
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED
    
    // Close the gate after a certain delay
    if (millis() - openTime > closeDelay && openTime != 0) {
      servoCloseGate();
      openTime = 0; // Reset the openTime to prevent continuous closing
    } else {
      // Display "Welcome at exit gate" message when no object is detected
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Welcome at exit");
      lcd.setCursor(0, 1);
      lcd.print("   gate");
    }
  }

  // Small delay before the next measurement
  delay(500);
}

void servoOpenGate() {
  myServo.write(90); // Open gate (adjust the angle as needed)
}

void servoCloseGate() {
  myServo.write(0); // Close gate
}

bool isValidUID(String ID) {
  for (String validUID : validUIDs) {
    if (ID.substring(1) == validUID) {
      return true;
    }
  }
  return false;
}

unsigned long getEntranceTime(String ID) {
  for (int i = 0; i < 5; i++) {
    if (ID.substring(1) == validUIDs[i]) {
      return cardTimes[i];
    }
  }
  return 0;
}

float calculateAmount(unsigned long timeSpent) {
  // Convert time spent from milliseconds to hours
  float hours = timeSpent / 3600000.0;
  float rate = 5.0; // Rate per hour
  return hours * rate;
}
