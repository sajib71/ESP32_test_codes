/*
 * Connect esp32 with WiFi
 * Date: 04 February 2024
 * Name: Sanaullah Sajib
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
