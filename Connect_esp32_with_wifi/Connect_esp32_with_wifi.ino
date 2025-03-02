/*
 * ESP32 WiFi Connection Example
 * This program demonstrates how to connect an ESP32 to a WiFi network.
 * It continuously attempts to connect to the specified WiFi network until a successful connection is established.
 * Once connected, it prints the local IP address of the ESP32 to the Serial Monitor.
 *
 * Date: 04 February 2024
 * Author: Sanaullah Sajib
 * 
 * Hardware Requirements:
 * - ESP32 Development Board
 * - WiFi network (SSID and Password)
 */
 
#include <WiFi.h>
const char* ssid = "Sincos factor";
const char* passward = "Sincos@1983#";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin (ssid, passward);
  while (WiFi.status () != WL_CONNECTED){
    delay (500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //show ip address when connected on serial monitor
}

void loop() {
  // put your main code here, to run repeatedly:
}
