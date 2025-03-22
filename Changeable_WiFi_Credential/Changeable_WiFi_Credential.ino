#include <WiFi.h>
#include <PubSubClient.h>

// Default MQTT server credentials
const char* mqtt_server = "103.228.203.114";
int mqtt_port = 1883;
const char* mqtt_username = "pesdevices";
const char* mqtt_password = "rZJENY9FM2";

// Default WiFi credentials
const char* ssid = "Sincos factory";
const char* password = "Sincos@1983#";

String chipId;  // For isolating devices by Chip ID

WiFiClient espClient;
PubSubClient client(espClient);

// Function to configure WiFi
void config_wifi(const char* ssid, const char* password) {
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

// Function to reconnect to MQTT
void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    Serial.print("Connecting to MQTT server at: ");
    Serial.print(mqtt_server);
    Serial.print(":");
    if (client.connect(chipId.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Connected");
      // Subscribe to the topic with the chipId
      String topic = "devices/" + chipId;
      client.subscribe(topic.c_str());
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds");
      delay(5000);
    }
  }
}

// Function to process incoming MQTT commands
void processCommand(const char* command) {
  String commandStr = String(command);

  // Determine whether the command is for WiFi or MQTT
  if (commandStr.startsWith("wifi,")) {
    commandStr = commandStr.substring(5);  // Remove "wifi," from the command
    String values[6];  // Expecting 6 fields after "wifi,"
    int commaIndex = 0;
    for (int i = 0; i < 6; i++) {
      commaIndex = commandStr.indexOf(',');
      if (commaIndex == -1) {
        values[i] = commandStr;
        break;
      }
      values[i] = commandStr.substring(0, commaIndex);
      commandStr = commandStr.substring(commaIndex + 1);
    }

    // Extract WiFi credentials from the first two fields
    String newSSID = values[0];
    String newPassword = values[1];

    if (newSSID.length() > 0 && newPassword.length() > 0) {
      Serial.println("Received new WiFi credentials:");
      Serial.print("SSID: ");
      Serial.println(newSSID);
      Serial.print("Password: ");
      Serial.println(newPassword);

      // Update credentials and reconnect to WiFi
      ssid = newSSID.c_str();
      password = newPassword.c_str();
      config_wifi(ssid, password);
    } else {
      Serial.println("Invalid WiFi credentials");
    }

  } else if (commandStr.startsWith("mqtt,")) {
    commandStr = commandStr.substring(5);  // Remove "mqtt," from the command
    String values[7];  // Expecting 7 fields after "mqtt,"
    int commaIndex = 0;
    for (int i = 0; i < 7; i++) {
      commaIndex = commandStr.indexOf(',');
      if (commaIndex == -1) {
        values[i] = commandStr;
        break;
      }
      values[i] = commandStr.substring(0, commaIndex);
      commandStr = commandStr.substring(commaIndex + 1);
    }

    // Extract MQTT credentials
    String newMqttServer = values[2];
    String newMqttUsername = values[3];
    String newMqttPassword = values[4];
    String newMqttPort = values[5];

    if (newMqttServer.length() > 0 && newMqttPort.length() > 0) {
      Serial.println("Received new MQTT credentials:");
      Serial.print("MQTT Server: ");
      Serial.println(newMqttServer);
      Serial.print("MQTT Username: ");
      Serial.println(newMqttUsername);
      Serial.print("MQTT Password: ");
      Serial.println(newMqttPassword);
      Serial.print("MQTT Port: ");
      Serial.println(newMqttPort);

      // Update MQTT credentials
      mqtt_server = newMqttServer.c_str();
      mqtt_username = newMqttUsername.c_str();
      mqtt_password = newMqttPassword.c_str();
      mqtt_port = newMqttPort.toInt();

      // Show the new MQTT server IP
      Serial.print("New MQTT server IP: ");
      Serial.print(mqtt_server);
      Serial.print(":");
      Serial.println(mqtt_port);

      // Update the server address and reconnect to the new MQTT broker
      client.setServer(mqtt_server, mqtt_port);
      reconnect();
    } else {
      Serial.println("Invalid MQTT credentials");
    }
  } else {
    Serial.println("Invalid command format");
  }
}

// MQTT callback function
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  char message[length + 1];
  for (int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0'; // Null-terminate the message
  Serial.println(message);

  // Process the received command
  processCommand(message);
}

void setup() {
  Serial.begin(115200);
  chipId = String((uint32_t)ESP.getEfuseMac());  // Unique identifier for the ESP32
  config_wifi(ssid, password);
  client.setServer(mqtt_server, mqtt_port);
  Serial.print("Initial MQTT server IP: ");
  Serial.print(mqtt_server);
  Serial.print(":");
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publish a status message with retained flag to the topic "devices/{chipId}/status"
  String statusTopic = "devices/" + chipId + "/status";
  String statusMessage = "Online";
  client.publish(statusTopic.c_str(), statusMessage.c_str(), true); // 'true' sets the retained flag

  delay(5000); // Adjust the delay as needed
}
