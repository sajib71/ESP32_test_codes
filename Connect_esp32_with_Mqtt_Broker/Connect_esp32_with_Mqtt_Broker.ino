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
Const char* mqtt_server = "192.168.1.194";
Const int* mqtt_port = "1883";
Const char* mqtt_userName = "iotmate";
Const char* mqtt_password = "Test_password";
const char* mqtt_topic = "topic";

WiFiClient espClient;
PubSubClient client(espClient);

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

  // Set up MQTT client
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  
  // Attempt to connect to MQTT broker
  reconnect();
}

void loop() { // run over and over
  // put your main code here, to run repeatedly:
  if (!client.connected()){
    reconnect(); // Reconnect if connection is lost
  }
  client.loop();
}

void callback(char* topic, byte* payload, unsigned int length){
  // Callback function to handle incoming MQTT messages.
}
