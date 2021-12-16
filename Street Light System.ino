#include<ESP8266WiFi.h>

int start_light,end_light;
int LDR_Pin=A0;         //LDR - andhera aur ujala check karta hai ::  0-1023   /   2^10

void setup() {
  // put your setup code here, to run once:
  pinMode(D0,INPUT);    //start_light
  pinMode(D2,INPUT);    //end_light
  pinMode(D4,OUTPUT);   //LED
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  start_light=digitalRead(D0);
  if(start_light==0 && analogRead(LDR_Pin)<300){
    Serial.println("light on");
    digitalWrite(D4,HIGH);
    delay(100);
  }
  end_light=digitalRead(D2);
  if(end_light==0){
    Serial.println("light off");
    digitalWrite(D4,LOW);
    delay(100);
  }
}
