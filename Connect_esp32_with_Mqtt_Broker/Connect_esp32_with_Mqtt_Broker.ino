/*
 * This code demonstrates how to connect an ESP32 to an MQTT broker using the Arduino IDE.
 * The ESP32 will connect to a specified Wi-Fi network and then establish a connection to 
 * an MQTT broker. Once connected, it can publish messages to a topic or subscribe to receive 
 * messages from a topic.
 *
 * Key functionalities:
 * 1. Connects to a Wi-Fi network with given SSID and password.
 * 2. Connects to an MQTT broker using the broker's URL and port.
 * 3. Provides functions to publish messages to a specified topic.
 * 4. Sets up a callback function to handle messages received from a subscribed topic.
 *
 * Libraries required:
 * 1. WiFi.h - for handling Wi-Fi connections.
 * 2. PubSubClient.h - for handling MQTT protocol.
 *
 * Instructions:
 * 1. Replace 'yourSSID' and 'yourPASSWORD' with your Wi-Fi credentials.
 * 2. Replace 'mqtt_ServerIP', 'mqtt_port', 'mqtt_username', 'mqtt_password' with the appropriate MQTT broker details.
 * 3. Upload the code to your ESP32 board.
 * 4. Open the Serial Monitor to view connection status and messages.
 * 
 * Author :  Sanaullah Sajib
 * Date   :  05 July 2024
 */
#include <WiFi.h>
#include<PubSubClient.h>

// WiFi Credential Here
Const char* ssid = "Test_Network";
Const char* password = "Test_password";
// Broker Credential Here
Const char* server = "192.168.1.194";
Const char* port = "1883";
Const char* userName = "iotmate";
Const char* password = "Test_password";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin (ssid, passward);
  while (WiFi.status != WL_CONNECTED()){
    delay (500);
    Serial.print (".");
  }
  Serial.println("Connected to the WiFi network");
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //show ip address when connected on serial monitor
}

void loop() { // run over and over
  // put your main code here, to run repeatedly:
}
