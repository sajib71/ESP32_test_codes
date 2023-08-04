// Follow the Diagram
// Connect "SDA" to pin "D21" and "SCL" to pin "D22"
// #include < Wire .h> we are removing this because it is already added in liquid crystal library
#include <LiquidCrystal_I2C.h>
 
// Create the lcd object address 0x27 and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2);  //
 
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
