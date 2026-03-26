byte tlacitkoPin = 5;  //nastaveni tlačitka jako čtení byte
byte tlacitkoPin2 = 6; 
bool hodnotaTl;  //proměná 

//& and piše se pravý alt a C
//|| or a pše se pravý alt a W

void setup() {


  //pinMode(5, INPUT); take určeni pinu jako vstup
  //pinMode(6, INPUT);

  Serial.begin(9600);  //seriová komunikace vždy 9600

}

void loop() {
  
  hodnotaTl = digitalRead(tlacitkoPin); //čtení hodnoty tlacitko pin a ulozeni do hotnotaTl
  Serial.print("Hodnota tlačítka: ");
  Serial.println(hodnotaTl); //vypsani hodnoty hodnotyTl do serioveho monitoru 


}
