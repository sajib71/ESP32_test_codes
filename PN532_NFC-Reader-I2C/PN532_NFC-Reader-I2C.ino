#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>

// I2C Configuration
#define SDApin 33
#define SCLpin 32

PN532_I2C pn532_i2c(Wire);
PN532 nfc(pn532_i2c);

String nfcTagID = "empty";  // Stores the current NFC tag ID
byte nuidPICC[4];

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("System initialized");

  // Initialize I2C communication
  Wire.begin(SDApin, SCLpin);
  nfc.begin();

  // Check if the PN532 is connected
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("Didn't find PN53x module");
    while (1);  // Halt the program
  }

  // Print firmware details
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata >> 8) & 0xFF, DEC);

  // Configure the board to read RFID/NFC tags
  nfc.SAMConfig();
  Serial.println("Waiting for an NFC card...");
}

void loop() {
  readNFC();
}

void readNFC() {
  if (nfc.inListPassiveTarget()) {  // Check if a tag is detected
    if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, nuidPICC, &nuidPICC[4])) {  // Corrected: pass size as 4
      String newTagID = tagToString(nuidPICC);  // Convert UID to string

      if (newTagID != nfcTagID) {  // If the tag is new, update and print
        nfcTagID = newTagID;
        Serial.println("NFC Tag: " + nfcTagID);
      }
    }
  }
}

// Helper function to convert NFC tag ID to string
String tagToString(byte id[4]) {
  String tagString = "";
  for (byte i = 0; i < 4; i++) {
    tagString += String(id[i], HEX);
    if (i < 3) tagString += ":";  // Add colon between bytes
  }
  tagString.toUpperCase();  // Convert to uppercase
  return tagString;
}
