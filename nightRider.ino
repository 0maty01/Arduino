#include <Arduino.h>

byte LED1 = 2;
byte LED2 = 3;
byte LED3 = 4;
byte LED4 = 5;
byte LED5 = 6;
byte LED6 = 8;
byte LED7 = 9;
byte LED8 = 10;

int rychlost = 40;

void setup() {

  Serial.begin(9600);	

for (int pin =2; pin <=10; pin++) {
  pinMode(pin, OUTPUT);
}

}

void loop() {

 for (int pin = 2; pin <= 10; pin++) {
  digitalWrite(pin, HIGH);
  delay(rychlost);
  
  if (pin > 2){
    digitalWrite(pin - 1, LOW);
  }
 }

 for (int pin =10; pin >=2; pin--) {
  digitalWrite(pin, HIGH);
  delay(rychlost);

 if (pin <10 ){
   digitalWrite(pin + 1, LOW);
 }
  
  
 }


}




//tohle je projekt night rider ledky běži z prava do leva. Je použita funkce for pro ciklus 