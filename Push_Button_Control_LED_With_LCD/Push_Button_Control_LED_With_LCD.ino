/// #include < Wire .h> we are removing this because it is already added in liquid crystal library
#include <LiquidCrystal_I2C.h> // for i2c library
LiquidCrystal_I2C lcd (0x27,16,2); // address
int button = 5; // input button
int led = 4; // output led
int button_state = 0; // read button state
void setup() {
  // put your setup code here, to run once:
  pinMode (led,OUTPUT);
  pinMode (button,INPUT);
  lcd.begin ();
  lcd.backlight ();
}

void loop() {
  // put your main code here, to run repeatedly:
  button_state = digitalRead(button);

  if(button_state == HIGH){
    digitalWrite(led,HIGH);
    lcd.clear ();
    lcd.setCursor (5,0);
    lcd.print ("LED ON");
  }
  else{
    digitalWrite(led,LOW);
    lcd.clear ();
    lcd.setCursor (5,1);
    lcd.print ("LED OFF");
    
  }
}
