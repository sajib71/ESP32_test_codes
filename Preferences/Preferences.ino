#include <Preferences.h>
#include <WiFi.h>

// Create instance of the prefences library
Preferences preferences;

// Wi-Fi Credential
const char* ssid = "Sincos factory";
const char* password = "Sincos@1983#";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  preferences.begin ("wifi-config", false);
  preferences.putString("wifiSSID", ssid);
  preferences.putString("wifiPASSWORD", password);

  //Read from preferences
  String stored_ssid = preferences.getString("wifiSSID");
  String stored_password = preferences.getString("wifiPASSWORD");
  Serial.println(stored_ssid);
  Serial.println(stored_password);

  //Connect with Wi-Fi using stored credential
  WiFi.begin(stored_ssid, stored_password);
  while (WiFi.status () != WL_CONNECTED){
    delay(500);
    Serial.println ("Connecting to Wi-Fi Network");
  }
  Serial.print ("Connected to: ");
  Serial.print (ssid);
  
  // Close the preferences
  preferences.end();
}

void loop() {
  // put your main code here, to run repeatedly:
}
