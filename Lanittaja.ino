#define AJOTILA

char suora[8] = {2, 3, 4, 5, 6, 7, 8, 9};
char risti[8] = {4, 7, 2, 5, 6, 3, 8, 9};

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(12, INPUT); // Normaali suora kaapeli tai ristiinkytketty kaapeli
  pinMode(13, OUTPUT); // LED hallinta
#ifdef AJOTILA
  Serial.begin(9600);
#endif
}

void loop() {
  if (digitalRead(12) == LOW) { // Ristiinkytketty kaapeli
#ifdef AJOTILA
    Serial.println("Ristiinkytketty");
#endif
    for (char n = 0;n < 8;n++) {
#ifdef AJOTILA
      Serial.print(n+1, DEC);
      Serial.print(": line ");
      Serial.print(risti[n]-1, DEC);
      Serial.print(" (pin ");
      Serial.print(risti[n], DEC);
      Serial.println(")");
#endif
      PulssiUlos(risti[n], 1000);
      PulssiUlos(13, 50);
    }
  } else { // Suora kaapeli
#ifdef AJOTILA
    Serial.println("Suora");
#endif
    for (char n = 0;n < 8;n++) {
 #ifdef AJOTILA
      Serial.print(n+1, DEC);
      Serial.print(": line ");
      Serial.print(suora[n]-1, DEC);
      Serial.print(" (pin ");
      Serial.print(suora[n], DEC);
      Serial.println(")");
#endif
      PulssiUlos(suora[n], 1000);
      PulssiUlos(13, 50);
    }
  }
}

void PulssiUlos(char pin, int ms)
{
  digitalWrite(pin, HIGH);
  delay(ms);
  digitalWrite(pin, LOW);
}
