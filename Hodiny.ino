

include <Servo.h>

Servo NSA, NSB, NSC, NSD, NSE, NSF, NSG;
void setup() {
  Serial.begin(9600);
  NSA.attach(6);
  NSB.attach(7);
  NSC.attach(8);
  NSD.attach(9);
  NSE.attach(10);
  NSF.attach(11);
  NSG.attach(12); 
   
}

void loop() {
/*pozice = analogRead(A2);
pozice = map(pozice,0,1023,70,179);
 Serial.println(pozice);
*/

//Nula
NSA.write(90);
NSB.write(90);
NSC.write(90);
NSD.write(10);
NSE.write(90);
NSF.write(90);
NSG.write(90);
//jedna

delay(1000);
NSA.write(180);
NSB.write(90);
NSC.write(0);
NSD.write(10);
NSE.write(90);
NSF.write(180);
NSG.write(180);
//dva
delay(1000);
NSA.write(90);
NSB.write(180);
NSC.write(90);
NSD.write(90);
NSE.write(90);
NSF.write(180);
NSG.write(90);
//tři 
delay(1000);
NSA.write(90);
NSB.write(90);
NSC.write(0);
NSD.write(90);
NSE.write(90);
NSF.write(0);
NSG.write(90);

//čtyři
delay(1000);
NSA.write(180);
NSB.write(90);
NSC.write(0);
NSD.write(90);
NSE.write(90);
NSF.write(90);
NSG.write(180);
//pět
delay(1000);
NSA.write(90);
NSB.write(90);
NSC.write(0);
NSD.write(90);
NSE.write(0);
NSF.write(90);
NSG.write(90);
//šest 
delay(1000);
NSA.write(90);
NSB.write(90);
NSC.write(90);
NSD.write(90);
NSE.write(0);
NSF.write(90);
NSG.write(90);
//sedm
delay(1000);
NSA.write(180);
NSB.write(90);
NSC.write(0);
NSD.write(10);
NSE.write(90);
NSF.write(180);
NSG.write(90);
//osm
delay(1000);
NSA.write(90);
NSB.write(90);
NSC.write(90);
NSD.write(90);
NSE.write(90);
NSF.write(90);
NSG.write(90);
//devět
delay(1000);
NSA.write(180);
NSB.write(90);
NSC.write(0);
NSD.write(90);
NSE.write(90);
NSF.write(90);
NSG.write(90);
delay(1000);
 }
