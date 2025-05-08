#include <NewPing.h>
#include <Wire.h>
#include <math.h>
#include "rgb_lcd.h"
rgb_lcd lcd;
long time;
long lastevent;
NewPing S(A2, A1,20);  //Trigger, Echo

void setup()  {
    lcd.begin(16, 2);
    Serial.begin(9600);
    lcd.setRGB(255, 255, 255);
    
    lcd.setCursor(4, 0); lcd.print("Welcome to");
    delay(1000);
    lcd.setCursor(4, 1); lcd.print("SMART HOME");
    delay(2000);
    time=millis();
    lastevent=millis();

}

void loop() {
    lcd.clear();
    int a = analogRead(A0);
    int DIST = S.ping_cm();
    float R = (1023.0/a-1.0)* 100000;
    float T = 1.0/(log((1023.0/a-1.0))/4275+1/298.15)-273.15;
    lcd.setCursor(0, 0); lcd.print("Temp: "); lcd.print(T);

    if(!DIST)
      lcd.setCursor(0, 1), lcd.print("No Person");
    else  {
      lcd.setCursor(0, 1), lcd.print("Person Detected");
      if(millis()>lastevent+30000){
        Serial.print(T);
        Serial.print(" ");
        Serial.println(1);

        lastevent=millis();
      }
      
    }
    

    if (millis()>time+30000){
      time=millis();
      Serial.print(T);
      Serial.print(" ");
      Serial.println(0);
     
      
      }
      delay(200);      

  }
