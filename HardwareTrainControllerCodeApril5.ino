#include <ezButton.h>
#include <LiquidCrystal_I2C.h>

#include "t3serialserver.hpp"

// set up lcd screen object
  LiquidCrystal_I2C lcd(0x27, 16, 2);
  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  // create object of T3SerialServer class
  T3SerialServer tss;


  
  bool b = false;
  bool l = false;
  bool r = false;
  bool t = false;
  bool bo = false;
  bool o = false;
  
  bool *back = new bool;
  bool *left = new bool;
  bool *right = new bool;
  bool *top = new bool;
  bool *bottom = new bool;
  bool *ok = new bool;

  back = &b;
  left = &l;
  right = &r;
  top = &t;
  bottom = &bo;
  ok = &o;

  char ft;
  char fb;
  char *ftop = new char;
  char *fbottom = new char;
  ftop = &ft;
  fbottom = &fb;

  ezButton backButton(2); // Back button is pin 2
  ezButton leftButton(3); // Left button is pin 3
  ezButton rightButton(4); // Right button is pin 4
  ezButton topButton(5); // Top button is pin 5
  ezButton bottomButton(6); // Bottom button is pin 6
  ezButton okButton(7); // OK button is pin 7
  
  
  
  
  
  
  

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // Check if backbutton is pressed
  backButton.loop();

  if (backButton.isPressed()) {
    b = true;
    tss.event(back, left, right, top, bottom, ok);
    b = false;
    tss.flush(ftop, fbottom);
        lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
      
  }


  // check if leftbutton is pressed
  leftButton.loop();
  
  if (leftButton.isPressed()) {
    l = true;
    tss.event(back, left, right, top, bottom, ok);
    l = false;
    tss.flush(ftop, fbottom);
        lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
  }


  // check if rightbutton is pressed
  rightButton.loop();
  
  if (rightButton.isPressed()) {
    r = true;
    tss.event(back, left, right, top, bottom, ok);
    r = false;
    tss.flush(ftop, fbottom);
        lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
  }



  // check if topbutton is pressed
  topButton.loop();
  
  if (topButton.isPressed()) {
    t = true;
    tss.event(back, left, right, top, bottom, ok);
    t = false;
    tss.flush(ftop, fbottom);
    lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
  }


  // check if bottombutton is pressed
  bottomButton.loop();
  
  if (bottomButton.isPressed()) {
    bo = true;
    tss.event(back, left, right, top, bottom, ok);
    bo = false;
    tss.flush(ftop, fbottom);
    lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
  }



  // check if okbutton is pressed
  okButton.loop();
  
  if (okButton.isPressed()) {
    o = true;
    tss.event(back, left, right, top, bottom, ok);
    o = false;
    tss.flush(ftop, fbottom);
    lcd.setCursor(0,0);
    lcd.print(ftop);
    lcd.setCursor(0,1);
    lcd.print(fbottom);
  }

  // delete pointers after they are used
  delete back;
  delete left;
  delete right;
  delete top;
  delete bottom;
  delete ok;

  delete ftop;
  delete fbottom;

}
