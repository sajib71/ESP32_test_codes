/*
 * ESP32 LCD Display Example (I2C)
 * This program demonstrates how to use an I2C LCD display with the ESP32.
 * It initializes a 16x2 LCD and displays three messages: "Hello!", "Welcome to", and "DHAKA".
 * The messages are shown for 2 seconds each, with the display cleared between them.
 * 
 * Hardware Requirements:
 * - ESP32 Development Board
 * - 16x2 I2C LCD Display (I2C Address: 0x27)
 * - Connect the LCD as follows:
 *   * SDA -> GPIO21
 *   * SCL -> GPIO22
 * 
 * Library Requirements:
 * - LiquidCrystal_I2C (for controlling the LCD)
 * 
 * Note:
 * The Wire library is automatically included by the LiquidCrystal_I2C library, so it is not required to be explicitly included.
 * Date: 04 February 2024
 * Author: Sanaullah Sajib
 */
#include <LiquidCrystal_I2C.h>
 
// Create the lcd object address 0x27 and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2); 
 
void  setup () {
  // Initialize the LCD connected 
  lcd. begin (); //or you can use "lcd.init ();"
  
  // Turn on the backlight on LCD. 
  lcd. backlight (); 
}
 
void  loop () {
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("Hello !");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Welcome to");
  delay(2000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("DHAKA");
  delay(2000);
}
