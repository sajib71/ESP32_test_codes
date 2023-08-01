// #include < Wire .h> we are removing this because it is already added in liquid crystal library
#include <LiquidCrystal_I2C.h> // I2C library
 
// Create the lcd object address 0x27 and 16 columns x 2 rows 
LiquidCrystal_I2C lcd (0x27, 16,2);  // 16 Columns and 2 Rows
 
void  setup () {
   // Initialize the LCD connected 
  lcd. begin ();
  
  // Turn on the backlight on LCD. 
  lcd. backlight ();
  
  lcd.setCursor(3,0); // (col,row)Position
  lcd. print ( "it's Sajib" ); // print the Message on the LCD. 
  
  lcd.setCursor(3,1); // (col,row)Position
  lcd.print("Good Luck"); // print the Message on the LCD. 
}
 
void  loop () {
   
}
