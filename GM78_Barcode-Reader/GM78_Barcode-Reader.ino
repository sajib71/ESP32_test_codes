// Define the hardware serial port for the GM78 barcode reader
#define GM78_RX 22  // Connect this pin to the TX of GM78
#define GM78_TX 21  // Connect this pin to the RX of GM78

// Initialize a serial port for the GM78
HardwareSerial GM78Serial(1);

void setup() {
  // Start the serial communication
  Serial.begin(115200);        // Debugging serial
  GM78Serial.begin(9600, SERIAL_8N1, GM78_RX, GM78_TX); // GM78 serial

  Serial.println("GM78 Barcode Reader Test");
}

void loop() {
  // Check if there's any data available from the GM78 barcode reader
  if (GM78Serial.available()) {
    // Read and print the barcode data
    String barcodeData = GM78Serial.readString();
    Serial.println("Barcode Data: " + barcodeData);
  }
}
