/*
   ESP32 Built-in LED Control with I2C LCD Display

   Description:
   This program demonstrates how to control the built-in LED of an ESP32 
   while displaying its status on a 16x2 I2C LCD. When the LED is turned ON, 
   the LCD displays "LED ON"; when the LED is turned OFF, it displays "LED OFF". 
   The LED and display messages toggle every 1.5 seconds.

   Hardware Requirements:
   - ESP32 Development Board
   - 16x2 I2C LCD Display (I2C Address: 0x27)
   - Appropriate wiring for I2C communication:
     * SDA -> GPIO21
     * SCL -> GPIO22

   Implementation Details:
   - The built-in LED is connected to GPIO2.
   - The LCD communicates using the I2C protocol.
   - The LCD backlight remains ON throughout the operation.
   - A delay of 1.5 seconds is used between each toggle.

   Author: Sanaullah Sajib  
   Date: March 2, 2025  
*/

#include <LiquidCrystal_I2C.h>               // Include the I2C LCD library
LiquidCrystal_I2C lcd(0x27, 16, 2);          // Initialize LCD with I2C address 0x27, 16 columns, and 2 rows

int LED_BUILTIN = 2;                         // Define the built-in LED pin

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);              // Set the LED pin as an output
  lcd.begin();                               // Initialize the LCD
  lcd.backlight();                           // Turn on the LCD backlight
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);           // Turn ON the LED
  lcd.setCursor(5, 0);                       // Set cursor to the center of the first row
  lcd.print("LED ON");                       // Display "LED ON" on the LCD
  delay(1500);                               // Wait for 1.5 seconds
  lcd.clear();                               // Clear the LCD screen
  digitalWrite(LED_BUILTIN, LOW);            // Turn OFF the LED
  lcd.setCursor(5, 1);                       // Set cursor to the center of the second row
  lcd.print("LED OFF");                      // Display "LED OFF" on the LCD
  delay(1500);                               // Wait for 1.5 seconds
  lcd.clear();                               // Clear the LCD screen
}
