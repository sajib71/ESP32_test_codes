/*
 * ESP32 Button Controlled LED with LCD Feedback
 * This program demonstrates how to control an LED using a push button, with status displayed on a 16x2 I2C LCD.
 * When the button is pressed, the LED turns ON and the LCD displays "LED ON". 
 * When the button is released, the LED turns OFF and the LCD displays "LED OFF".
 * 
 * Hardware Requirements:
 * - ESP32 Development Board
 * - Push Button (connected to GPIO 5)
 * - LED (connected to GPIO 4)
 * - 16x2 I2C LCD Display (I2C Address: 0x27)
 * 
 * Circuit Connection:
 * - Button connected to GPIO 5 (input)
 * - LED connected to GPIO 4 (output)
 * - LCD connected via I2C (SDA to GPIO 21, SCL to GPIO 22)
 * 
 * Date: 04 February 2024
 * Author: Sanaullah Sajib
 */

#include <LiquidCrystal_I2C.h>  // Include the LiquidCrystal_I2C library to control the LCD display
// Initialize the LCD with I2C address 0x27 and display dimensions: 16 columns x 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the button pin (GPIO 5) and LED pin (GPIO 4)
int button = 5;            // Push button connected to GPIO 5
int led = 4;               // LED connected to GPIO 4

int button_state = 0;      // Variable to store the current button state

void setup() {
  // Initialize the LED pin as an output
  pinMode(led, OUTPUT);    // Set GPIO 4 as output for the LED
  
  // Initialize the button pin as an input
  pinMode(button, INPUT);  // Set GPIO 5 as input for the button
  
  // Initialize the LCD
  lcd.begin();             // Start the LCD
  lcd.backlight();         // Turn on the LCD backlight for visibility
}

void loop() {
  // Continuously check the state of the button
  button_state = digitalRead(button);  // Read the current button state (HIGH or LOW)

  // If the button is pressed (button_state == HIGH), turn the LED ON and display "LED ON" on the LCD
  if (button_state == HIGH) {
    digitalWrite(led, HIGH);   // Set LED pin HIGH to turn ON the LED
    lcd.clear();               // Clear the LCD screen
    lcd.setCursor(5, 0);       // Set the cursor position to row 0, column 5
    lcd.print("LED ON");       // Print "LED ON" on the LCD
  } 
  else {
    digitalWrite(led, LOW);    // Set LED pin LOW to turn OFF the LED
    lcd.clear();               // Clear the LCD screen
    lcd.setCursor(5, 1);       // Set the cursor position to row 1, column 5
    lcd.print("LED OFF");      // Print "LED OFF" on the LCD
  }
}
