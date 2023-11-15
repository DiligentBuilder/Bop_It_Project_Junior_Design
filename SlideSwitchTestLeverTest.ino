
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16,2);

void setup() {
  // put your setup code here, to run once:

  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(A0, INPUT);
  pinMode(8, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(A0);
  int leverValue = digitalRead(8);

  lcd.setCursor(0,0);

  //lcd.print("Slide switch value: ");
  lcd.print(sensorValue);


  lcd.setCursor(0,1);

  //lcd.print("Lever value: ");
  lcd.print(leverValue);

  //delay(500);

}
