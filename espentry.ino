#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

// WiFi credentials
#define WLAN_SSID       " " //your WIFI name 
#define WLAN_PASS       " "// Your WIFI password 

// Adafruit IO credentials
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883                   // Use 8883 for SSL
#define AIO_USERNAME    " " // Adfruit Username
#define AIO_KEY         " " // Adfruit key 

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
