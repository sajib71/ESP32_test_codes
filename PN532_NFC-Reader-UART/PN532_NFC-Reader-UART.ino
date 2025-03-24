//#include <HardwareSerial.h>
#include <PN532_HSU.h>
#include <PN532.h>

// Use Serial2 for the PN532 connection (you can change these pins as needed)
#define RXD2 4  // Change these if you're using different pins
#define TXD2 5

HardwareSerial PN532Serial(2); // Using UART2 for PN532

PN532_HSU pn532hsu(PN532Serial);
PN532 nfc(pn532hsu);

String tagId = "None", dispTag = "None";
byte nuidPICC[4];

void setup(void)
{
  Serial.begin(115200);
  Serial.println("Hello Maker!");

  PN532Serial.begin(115200, SERIAL_8N1, RXD2, TXD2);
  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata)
  {
    Serial.print("Didn't Find PN53x Module");
    while (1); // Halt
  }

  // Got valid data, print it out!
  Serial.print("Found chip PN5");
  Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. ");
  Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.');
  Serial.println((versiondata >> 8) & 0xFF, DEC);

  // Configure board to read RFID tags
  nfc.SAMConfig();
}

void loop()
{
  readNFC();
}

void readNFC()
{
  boolean success;
  uint8_t uid[] = {0, 0, 0, 0, 0, 0, 0}; // Buffer to store the returned UID
  uint8_t uidLength;                     // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);
  if (success)
  {
    Serial.print("UID Length: ");
    Serial.print(uidLength, DEC);
    Serial.println(" bytes");

    Serial.print("UID Value: ");
    for (uint8_t i = 0; i < uidLength; i++)
    {
      nuidPICC[i] = uid[i];
      Serial.print(" ");
      Serial.print(uid[i], DEC);
    }
    Serial.println();

    tagId = tagToString(nuidPICC);
    dispTag = tagId;

    Serial.print(F("tagId is : "));
    Serial.println(tagId);
    Serial.println("");

    delay(1000); // 1 second halt
  }
  else
  {
    // PN532 probably timed out waiting for a card
    Serial.println("Timed out! Waiting for a card...");
  }
}

String tagToString(byte id[4])
{
  String tagId = "";
  for (byte i = 0; i < 4; i++)
  {
    if (i < 3)
      tagId += String(id[i]) + ".";
    else
      tagId += String(id[i]);
  }
  return tagId;
}
