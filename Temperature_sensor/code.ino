#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0); // Setup the screen

void setup() {
  lcd.begin(16, 2);      // Start the screen
  lcd.setBacklight(HIGH); // Turn on screen light
}

void loop() {
  // 1. Read sensor voltage
  int rawValue = analogRead(A0);
  float voltage = rawValue * (5.0 / 1024.0);
  
  // 2. Turn voltage into temperature Celsius
  float tempC = (voltage - 0.5) * 100.0;

  // 3. Show temperature on screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1); // Prints temperature with 1 decimal
  lcd.print(" C");

  delay(1000); // Wait 1 second before checking again
}
