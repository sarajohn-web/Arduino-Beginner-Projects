#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

const int sigPin = 7;

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
}

void loop() {

  long duration;
  float distance;

  pinMode(sigPin, OUTPUT);

  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(sigPin, LOW);

  pinMode(sigPin, INPUT);

  duration = pulseIn(sigPin, HIGH);

  distance = duration * 0.0343 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance:     ");

  lcd.setCursor(0, 1);
  lcd.print("                ");

  lcd.setCursor(0, 1);
  lcd.print(distance);
  lcd.print(" cm");

  delay(500);
}
