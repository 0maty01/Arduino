// --- 1. HLAVNÍ SILNICE (Rovně) ---
byte hlCervena = 13;
byte hlZluta = 12;
byte hlZelena = 11;

// --- 2. PROTIJEDOUCÍ SILNICE (Rovně) ---
byte protiCervena = 10;
byte protiZluta = 9;
byte protiZelena = 8;

// --- 3. ODBOČOVACÍ PRUH (Doleva) ---
byte odCervena = 7;
byte odZluta = 6;
byte odZelena = 5;

// --- 4. CHODCI ---
byte chodciCervena = 4;
byte chodciZelena = 3;
byte tlacitkoChodci = 2; // Tlačítko (musí být na pinu 2)

void setup() {
  // Rychlé nastavení všech LED pinů jako VÝSTUP (piny 3 až 13)
  for (int pin = 3; pin <= 13; pin++) {
    pinMode(pin, OUTPUT);
  }
  
  // Tlačítko jako VSTUP s odporem
  pinMode(tlacitkoChodci, INPUT_PULLUP);

  // --- VÝCHOZÍ STAV ---
  // Hlavní a protisměr jedou, odbočovák a chodci stojí
  digitalWrite(hlZelena, HIGH);
  digitalWrite(protiZelena, HIGH);
  digitalWrite(odCervena, HIGH);
  digitalWrite(chodciCervena, HIGH);
}

void loop() {
  // Proměnná, která si pamatuje, jestli chodec zmáčkl tlačítko
  bool chodecCeka = false;

  // FÁZE 1: Hlavní a protisměr mají zelenou (cca 5 vteřin)
  // TRIK K MATURITĚ: Místo delay(5000), které by Arduino "uspalo",
  // uděláme rychlý cyklus. Každých 0.1s zkontrolujeme tlačítko.
  for (int i = 0; i < 50; i++) {
    if (digitalRead(tlacitkoChodci) == LOW) {
      chodecCeka = true; // Chodec zmáčkl tlačítko! Zapamatujeme si to.
    }
    delay(100); 
  }

  // --- FÁZE 2: Hlavní a protisměr zastavují ---
  digitalWrite(hlZelena, LOW); digitalWrite(protiZelena, LOW);
  digitalWrite(hlZluta, HIGH); digitalWrite(protiZluta, HIGH);
  delay(2000); 
  
  digitalWrite(hlZluta, LOW);  digitalWrite(protiZluta, LOW);
  digitalWrite(hlCervena, HIGH); digitalWrite(protiCervena, HIGH);
  delay(1000); // Všude červená (bezpečnostní pauza)

  // --- FÁZE 3: CHODCI (Pustí se jen, pokud někdo zmáčkl tlačítko) ---
  if (chodecCeka == true) {
    digitalWrite(chodciCervena, LOW);
    digitalWrite(chodciZelena, HIGH);
    delay(5000); // Chodci přecházejí

    // Blikající zelená pro chodce před koncem
    for (int i = 0; i < 4; i++) {
      digitalWrite(chodciZelena, LOW); delay(400);
      digitalWrite(chodciZelena, HIGH); delay(400);
    }

    digitalWrite(chodciZelena, LOW);
    digitalWrite(chodciCervena, HIGH);
    delay(1000); // Chodci opustili přechod, všude je červená
  }

  // --- FÁZE 4: Odbočovák dostává zelenou ---
  digitalWrite(odZluta, HIGH);
  delay(1000);
  
  digitalWrite(odCervena, LOW); digitalWrite(odZluta, LOW);
  digitalWrite(odZelena, HIGH);
  delay(4000); // Odbočovák projíždí

  // --- FÁZE 5: Odbočovák zastavuje ---
  digitalWrite(odZelena, LOW); digitalWrite(odZluta, HIGH);
  delay(2000);
  
  digitalWrite(odZluta, LOW); digitalWrite(odCervena, HIGH);
  delay(1000); // Zase bezpečnostní pauza

  // --- FÁZE 6: Návrat k výchozímu stavu (Hlavní a protisměr se rozjíždí) ---
  digitalWrite(hlZluta, HIGH); digitalWrite(protiZluta, HIGH);
  delay(1000);
  
  digitalWrite(hlCervena, LOW); digitalWrite(protiCervena, LOW);
  digitalWrite(hlZluta, LOW); digitalWrite(protiZluta, LOW);
  digitalWrite(hlZelena, HIGH); digitalWrite(protiZelena, HIGH);

  // Konec cyklu, program se vrací na začátek a zase 5 vteřin hlídá tlačítko.
}