#include <Arduino.h>

#define MAX_BLINKS 4
int g_iteration = 0;

void blink(int count) {
  for(int i=0;i<max(0,count);i++) {
    digitalWrite(LED_BUILTIN,LOW);    delay(100);
    digitalWrite(LED_BUILTIN,HIGH);   delay(100);
  }
  return;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("\n\nWake Up");

  pinMode(LED_BUILTIN,OUTPUT);  
  pinMode(D0, WAKEUP_PULLUP);  // interesting, maybe alsway needed?   
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("%d) %ld\n",g_iteration, millis());
  g_iteration++;
  blink(1 + g_iteration%MAX_BLINKS);
  delay(1000);
}