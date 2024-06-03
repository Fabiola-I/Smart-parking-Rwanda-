# Talent4_StartUp

Hello👋,Am Fabiola Ingabire,

A student at university of rwanda,college of science and technology  pursuing a degree in Electronics and Telecommunication Engineering,

# About Me

I am currently a university student at the College of Science and Technology, majoring in Electronics and Telecommunication Engineering. 
Passionate about the intersection of technology and innovation, I am dedicated to expanding my knowledge and skills in the field of electronics.

With a strong academic foundation and practical experience gained through coursework and personal projects,
I am equipped with the expertise to design and develop electronic systems. My education has provided me with a comprehensive understanding of circuit theory, signal processing, and telecommunications principles, which I apply to solve complex engineering challenges.

Driven by curiosity and a desire to make meaningful contributions to the field, I am constantly exploring new technologies and methodologies.
I am particularly interested in PCB design and programming, 
leveraging tools like EasyEDA for efficient PCB development and employing programming languages such as C, C++, and Python to program electronic devices.

## Skills and Expertise

### PCB Design:

I have extensive experience in designing printed circuit boards (PCBs) using EasyEDA, a user-friendly and powerful online PCB design tool. 
I am proficient in creating schematics, laying out PCBs, and optimizing designs for performance and manufacturability.

### Programming Skills:

I possess strong programming skills, particularly in programming electronic device hardware.
I am proficient in languages such as C, C++, and Python, which enables me to develop firmware and software solutions for electronic devices.
I have a deep understanding of embedded systems and can effectively program microcontrollers and other electronic components to meet project requirements.

 # My Journee At kLab

 The journey began with a rigorous application process for online courses with Ihuzo Academy, a challenge that tested my perseverance and determination. 
Despite the initial difficulties, I successfully completed the demanding curriculum, culminating in a final project presentation at Klab.

During the online courses, I delved into simulations of intricate circuits using ThinkerCAD, a new experience that pushed me beyond my comfort zone.
Despite being adept at hardware, mastering the simulation with ESP8266 modules posed unique challenges, particularly in transmitting data to ThingSpeak.
Nevertheless, with persistence and dedication, I overcame these hurdles to deliver a comprehensive project proposal on the "Itwararike" device—an innovative solution designed to aid visually impaired individuals those who are not familiar with trafiic sign in safely navigating zebra crossings.

Selected to proceed to the next phase, I transitioned to physical classes at Klab, where I immersed myself in the world of IoT. From understanding the fundamentals to exploring advanced concepts like machine-to-machine communication and data transmission protocols, I embraced every learning opportunity with enthusiasm.

One highlight of my journey was delving into PCB design, an area where I already had expertise using EasyEDA. 
However, the introduction to KiCAD presented a fresh challenge, one that I embraced wholeheartedly. 
Leveraging my existing skills and determination to adapt, I quickly became proficient in KiCAD, expanding my repertoire in PCB design.

My journey at Klab has not only honed my technical skills but also nurtured my resilience and adaptability. 
With a relentless pursuit of excellence and a passion for innovation, I am poised to make meaningful contributions in the field of Electronics and Telecommunication Engineering.

# THE PROJECT I WORKED ON
##
**1.Traffic light controller**(Itwararike device):This is for aid visual impared and unfamilliar with traffic individual to navigate through the zebra crossing safe 

**2.Smart agrilture system:** this is an  IoT-based smart agriculture system to optimize water 
usage, improve crop yield, and provide valuable insights to farmers.

**3.Smart parking system:** Our solution involves designing and implementing an IoT and embedded system device that accurately tracks parking space occupancy,
counts incoming and outgoing vehicles, and notifies users when parking spaces become available or when the parking lot reaches capacity. 

#  CURRENT PROJECT: Smart Parking System

**1. Introduction:**

Parking congestion is a common issue in urban areas, leading to wasted time, increased traffic congestion, and frustrated drivers. To address this challenge, we propose the development of an IoT-based parking management system that provides real-time parking availability information to drivers and optimizes parking resource utilization for parking lot operators.

**2. Project Overview:**

 Our solution involves designing and implementing an IoT and embedded system device that accurately tracks parking space occupancy, counts incoming and outgoing vehicles, and notifies users when parking spaces become available or when the parking lot reaches capacity. This system aims to improve the efficiency of parking facilities, enhance the user experience for drivers, and reduce traffic congestion in urban areas.
   
**3. Technical Details:**

**Hardware Requirement**:

  **1. Parking Space Sensors:**
   - Ultrasonic Sensor: HC-SR04 Ultrasonic Sensor
   - Magnetic Sensor: Reed Switch Sensor

**2. Microcontroller/Processor:**
   - Arduino Uno R3 (for each entry/exit point)(or other arduino)

**3. Communication Module:**
   - Wi-Fi Module: ESP8266 Wi-Fi Module (for each Arduino)
     
**4. Access Control System:**
   - Servo Motor (for door opening)
   - RFID Card Reader: RFID-RC522 Module (for identifying vehicles)
     
**5. LCD Displays:**
   - 16x2 LCD Display Module (for displaying available parking spaces)
     
**6. CCTV Cameras:**
   - Webcam or Raspberry Pi Camera Module (for monitoring)
    
**7. Power Supply:**
     
      - battery to power device 
     
**8. Enclosures and Mounting Hardware:**
     
   - 3D printed enclosures for Arduino and other components
   - Mounting brackets, screws
   - Other components: Jumper wires,
                       resistors 220(ohm),
                       red LED.
     
  **Software Development:**

   - Algorithms for processing sensor data and calculating parking space occupancy.
   - Notification system for alerting users via SMS, email, or mobile app.
   - User interface design for accessing parking availability information.
   - we used ARDUINO IDE
   - And ADFRUIT IO: To contorl parking over cloud
 
**4. Integration with IoT Platform:**
     
   - Connect the device to an IoT platform for remote monitoring and management.
   - Utilize cloud services for data storage, analytics, and device management.
     
**5. User Experience:**
     
   - Develop a user-friendly mobile app or web portal for drivers to access parking availability information and receive notifications.
   - Design intuitive interfaces for seamless interaction with the system.
     
**6. Benefits and Impact:**
     
   - Reduced traffic congestion and emissions by enabling drivers to quickly find parking spaces.
   - Improved efficiency of parking facilities, leading to faster turnover of parking spaces.
   - Enhanced user experience and reduced frustration for drivers searching for parking.
   - Data-driven insights for urban planners to optimize parking infrastructure and transportation policies.
   - Revenue generation opportunities for parking lot operators through premium services and dynamic pricing.
     
**Conclusion:**

 Our IoT-based parking management system offers a innovative solution to address parking congestion in urban areas.
 By providing real-time parking availability information 
 to drivers and optimizing parking resource utilization for parking lot operators, our system has the potential to improve urban mobility,
 enhance the user experience, and reduce environmental impact.
 We believe that this project has significant value and is well-positioned to make a positive impact in urban communities.

 # PROPOSED SMART PARKING STATION
   ![SMART CITY - pic](https://github.com/Fabi-starr/Talent4_StartUp/assets/168666815/bf4b58c4-499f-4996-a101-4bcb014f32dc)
 # HARDWARE USED IN PROJECT 
 ![Hardware](https://github.com/Fabi-starr/Talent4_StartUp/assets/168666815/3941fe5b-71ac-41ae-9092-e6993a84862e)
 # PROTOTYPE DEMONSTRATION 
 ![parki](https://github.com/Fabi-starr/Talent4_StartUp/assets/168666815/e6a38482-7cc3-424c-9f05-720275aa2ec7)
 # CODE TO RUN ENTRANCE GATE
 ```arduino

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
// Sensor pin declaration to symbols status inside the parking.
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

 # CODE FOR ESP8266 TO CONNECT WITH THE ARDUINO AND SEND THE STATUS OF INFRARED SENSOR INSIDE THE PARKING TO THE CLOUD(ADFRUIT DASHBOARD)

## With this code we will be able to track real time status of parking lot based on infrared sensor on each lot,and be able to know time spended in the lot and the number of car parked this will provide realtime information based on each change occured inside the parking


 ```ESP8266 (NODE MCU)
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// WiFi credentials
#define WLAN_SSID       "Pixel 3"
#define WLAN_PASS       "fabiola@"

// Adafruit IO credentials
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // Use 8883 for SSL
#define AIO_USERNAME    " " //make change by using your adfruit username 
#define AIO_KEY         " " //make change by using your adfruit key.

// Create an ESP8266 WiFiClient class to connect to the MQTT server.
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Setup feeds for parking slots, parking times, and car count
Adafruit_MQTT_Publish parking_slot_1 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_1");
Adafruit_MQTT_Publish parking_slot_2 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_2");
Adafruit_MQTT_Publish parking_slot_3 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_3");
Adafruit_MQTT_Publish parking_slot_4 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_4");

Adafruit_MQTT_Publish parking_slot_1_time = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_1_Time");
Adafruit_MQTT_Publish parking_slot_2_time = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_2_Time");
Adafruit_MQTT_Publish parking_slot_3_time = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_3_Time");
Adafruit_MQTT_Publish parking_slot_4_time = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/parking_slot_4_Time");

Adafruit_MQTT_Publish cars_parked = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Number of car parked");

void connectToWiFi() {
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);
  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
  }
  Serial.println("MQTT Connected!");
}

void setup() {
  Serial.begin(115200); // Start serial communication at 115200 baud rate
  connectToWiFi();      // Connect to WiFi
}

void loop() {
  MQTT_connect();  // Ensure MQTT connection
  
  if (Serial.available()) {
    // Read data from Arduino
    String jsonData = Serial.readStringUntil('\n');

    // Parse JSON data
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, jsonData);

    if (error) {
      Serial.print("Error parsing JSON: ");
      Serial.println(error.c_str());
    } else {
      // Print received data
      Serial.print("Received JSON data: ");
      serializeJsonPretty(doc, Serial);
      Serial.println();

      // Update Adafruit IO feeds
      parking_slot_1.publish(doc["slot1"].as<const char*>());
      parking_slot_2.publish(doc["slot2"].as<const char*>());
      parking_slot_3.publish(doc["slot3"].as<const char*>());
      parking_slot_4.publish(doc["slot4"].as<const char*>());
      cars_parked.publish(doc["cars_parked"].as<int>());

      // Publish parking times
      if (doc.containsKey("slot1_time")) {
        parking_slot_1_time.publish(doc["slot1_time"].as<const char*>());
      }
      if (doc.containsKey("slot2_time")) {
        parking_slot_2_time.publish(doc["slot2_time"].as<const char*>());
      }
      if (doc.containsKey("slot3_time")) {
        parking_slot_3_time.publish(doc["slot3_time"].as<const char*>());
      }
      if (doc.containsKey("slot4_time")) {
        parking_slot_4_time.publish(doc["slot4_time"].as<const char*>());
      }
    }
  }

  mqtt.processPackets(10);  // Process incoming packets, keep connection alive
  mqtt.ping();              // Send a ping to keep the connection alive
}

 
 


 
 
 


