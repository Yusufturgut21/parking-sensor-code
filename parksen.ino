#define echopin 6
#define trigpin 7
#define buzzerpin 8

int maximumRange = 50;
int minimumRange = 0;

void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzerpin, OUTPUT);
}

void loop() {
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum * 10);
}

int mesafe(int maxrange, int minrange) {
  long duration, distance;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);
  distance = duration / 58.2;
  delay(50);

  if (distance >= maxrange || distance <= minrange)
    return 0;
  return distance;
}

void melodi(int dly) {
  tone(buzzerpin, 440);
  delay(dly);
  noTone(buzzerpin);
  delay(dly);
}
