# Maturita-Arduino-
Tento soubor shrnuje základy na arduino pro maturitu

# 🚀 Ultimátní tahák na Arduino - Maturita

## 1. Základní nastavení (Vstup / Výstup)
Předtím, než začneš cokoliv číst nebo zapisovat, musíš Arduinu říct, co ten pin vlastně dělá. Dělá se to ve funkci `setup()`.

* `pinMode(pin, OUTPUT);` -> Nastaví pin jako VÝSTUP (použiješ pro **LEDky na křižovatce**).
* `pinMode(pin, INPUT);` -> Nastaví pin jako VSTUP (čtení z obyčejného senzoru).
* `pinMode(pin, INPUT_PULLUP);` -> VSTUP se zabudovaným odporem (ideální pro **tlačítka pro chodce** - nepotřebuješ externí rezistor, tlačítko spojuješ se zemí/GND. Při stisku čteš LOW).

---

## 2. Zápis a Čtení (Digital)
Práce s digitálními piny (stavy 1/0, zapnuto/vypnuto, HIGH/LOW).

### Rozsvěcení a zhasínání (digitalWrite)
* `digitalWrite(pin, HIGH);` -> Pošle do pinu 5V (LEDka se **rozsvítí**).
* `digitalWrite(pin, LOW);` -> Pošle do pinu 0V (LEDka **zhasne**).

### Čtení tlačítek (digitalRead)
* `int stav = digitalRead(pin);` -> Přečte, jestli je na pinu napětí (HIGH) nebo ne (LOW).
* *Příklad použití:* `if (digitalRead(tlacitkoPin) == LOW) { ... }` (Pokud je tlačítko s INPUT_PULLUP zmáčknuté...)

---

## 3. Čtení ze senzorů (Analog)
Některé senzory (fotorezistor na měření tmy, potenciometr) nevrací jen 1/0, ale škálu hodnot. Zapojují se do pinů A0 až A5.

* `int hodnota = analogRead(A0);` -> Přečte hodnotu od `0` do `1023`.
* *(Poznámka: Analogové piny nepotřebují nastavovat přes pinMode).*

---

## 4. Podmínky (if / else)
Klíčové pro logiku. "Když se stane tohle, udělej tamto."

```cpp
if (digitalRead(tlacitkoChodci) == LOW) {
  // Tlačítko bylo zmáčknuto!
  // Tady spustíš sekvenci pro zastavení aut a puštění chodců
} else {
  // Tlačítko zmáčknuto NENÍ.
  // Svítí dál zelená pro auta.
}