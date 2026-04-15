// funkčńi T křižovatka budějovická bez přechodu 

#include <Arduino.h>

const int s1_rovne_cervena = 2;
const int s1_rovne_zluta = 3;
const int s1_rovne_zelena = 4;

const int s1_levo_cervena = 5;
const int s1_levo_zluta = 6;
const int s1_levo_zelena = 7;

const int s2_cervena = 8;
const int s2_zluta = 9;
const int s2_zelena = 10;
const int s2_sipka = 11;

const int s3_cervena = 12;
const int s3_zluta = 13;
const int s3_zelena = 14; 
const int s3_sipka = 15;  


void setup() {

  for (int i = 2; i <= 15; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  

  digitalWrite(s1_rovne_cervena, HIGH);
  digitalWrite(s1_levo_cervena, HIGH);
  digitalWrite(s2_cervena, HIGH);
  digitalWrite(s3_cervena, HIGH);
}


void loop() {

  // FÁZE 1: S1 rovně + S2 rovně + S2 šipka doprava

   digitalWrite(s1_rovne_zluta, HIGH);
 
   digitalWrite(s2_zluta, HIGH);
  delay(1000);
  
  digitalWrite(s1_rovne_cervena, LOW);


   digitalWrite(s1_rovne_zluta, LOW);


  digitalWrite(s2_cervena, LOW);
  digitalWrite(s2_zluta, LOW);

  digitalWrite(s1_rovne_zelena, HIGH);

  digitalWrite(s2_zelena, HIGH);



  delay(5000); // Auta jedou
  
  digitalWrite(s1_rovne_zelena, LOW);
   digitalWrite(s1_levo_zelena, LOW);
  digitalWrite(s2_zelena, LOW);
  digitalWrite(s1_rovne_zluta, HIGH);
   digitalWrite(s1_levo_zluta, HIGH);
  digitalWrite(s2_zluta, HIGH);
  delay(1500);
  
  digitalWrite(s1_rovne_zluta, LOW);
  digitalWrite(s1_levo_zluta, LOW);
  digitalWrite(s2_zluta, LOW);
  digitalWrite(s1_rovne_cervena, HIGH);
  digitalWrite(s1_levo_cervena, HIGH);
  digitalWrite(s2_cervena, HIGH);
  digitalWrite(s2_sipka, LOW);
  delay(1000);


  // FÁZE 2: S1 doleva  + S3 šipka doprava

  digitalWrite(s1_levo_zluta, HIGH);
  digitalWrite(s1_rovne_zluta, HIGH);

  digitalWrite(s3_sipka, HIGH);
  delay(1000);
  
  digitalWrite(s1_levo_cervena, LOW);
  digitalWrite(s1_rovne_cervena, LOW);
  digitalWrite(s1_levo_zluta, LOW);
  digitalWrite(s1_rovne_zluta, LOW);

 
  digitalWrite(s1_levo_zelena, HIGH);
  digitalWrite(s1_rovne_zelena, HIGH);
  delay(5000); // Auta jedou
  
  digitalWrite(s1_levo_zelena, LOW);
  digitalWrite(s1_rovne_zelena, LOW);
  digitalWrite(s1_levo_zluta, HIGH);
  digitalWrite(s1_rovne_zluta, HIGH);
  delay(1500);
  
  digitalWrite(s1_levo_zluta, LOW);
  digitalWrite(s1_rovne_zluta, LOW);
  digitalWrite(s1_levo_cervena, HIGH);
  digitalWrite(s1_rovne_cervena, HIGH);
  delay(1000);
  digitalWrite(s2_sipka, LOW);
  digitalWrite(s3_sipka, LOW);
  delay(1000);


  
  // FÁZE 3: S1 doleva + S3 šipka doprava

  digitalWrite(s1_levo_zluta, HIGH);
  digitalWrite(s3_sipka, HIGH);
  delay(1000);
  
  digitalWrite(s1_levo_cervena, LOW);
  digitalWrite(s1_levo_zluta, LOW);
  digitalWrite(s1_levo_zelena, HIGH);
  delay(5000); // Auta jedou
  
  digitalWrite(s1_levo_zelena, LOW);
  digitalWrite(s1_levo_zluta, HIGH);
  delay(1500);
  
  digitalWrite(s1_levo_zluta, LOW);
  digitalWrite(s1_levo_cervena, HIGH);
  digitalWrite(s3_sipka, LOW);
  delay(1000);



  // FÁZE 4: S3 doleva a doprava + S2 šipka doprava

  digitalWrite(s3_zluta, HIGH);
  digitalWrite(s2_sipka, HIGH);
  delay(1000);
  
  digitalWrite(s3_cervena, LOW);
  digitalWrite(s3_zluta, LOW);
  digitalWrite(s3_zelena, HIGH);
  delay(5000); // Auta jedou
  
  digitalWrite(s3_zelena, LOW);
  digitalWrite(s3_zluta, HIGH);
  delay(1500);
  
  digitalWrite(s3_zluta, LOW);
  digitalWrite(s3_cervena, HIGH);
  digitalWrite(s3_sipka, LOW);
  digitalWrite(s2_sipka, LOW);
  delay(1000);

  
}
