// Follow Circuit Diagram
// Select esp32 and select port
// When the builtin LED is ON the display will show "LED ON"
// And When the builtin LED is OFF the display will show "LED OFF"
#include <LiquidCrystal_I2C.h> // I2C display Library
LiquidCrystal_I2C lcd (0x27,16,2); // I2C address

int LED_BUILTIN = 2; // blink built in led

void setup() {
  // put your setup code here, to run once:
  pinMode (LED_BUILTIN, OUTPUT);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite (LED_BUILTIN, HIGH);
  lcd.setCursor (5,0);
  lcd.print ("LED ON");
  delay (1500);
  lcd.clear(); // Clear Screen
  digitalWrite (LED_BUILTIN, LOW);
  lcd.setCursor (5,1);
  lcd.print ("LED OFF");
  delay (1500);
  lcd.clear();
}
