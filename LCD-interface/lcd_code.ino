#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

const int PIR_PIN = 2; // PIR signal pin
int lastState = -1;    // Force initial display update

// Initialize LCD via I2C. Default address is 0 (which maps to 0x20-0x27 depending on chip)
Adafruit_LiquidCrystal lcd(0);

void setup() {
  pinMode(PIR_PIN, INPUT);
  
  lcd.begin(16, 2);  // Define 16 columns and 2 rows
  lcd.setBacklight(HIGH); // Turn screen backlight on
  
  lcd.setCursor(0, 0);
  lcd.print("System Ready...");
}

void loop() {
  int currentState = digitalRead(PIR_PIN);
  
  // Only update screen on state changes to prevent lag and flicker
  if (currentState != lastState) {
    lcd.clear(); 
    
    if (currentState == HIGH) {
      lcd.setCursor(0, 0);
      lcd.print("!! ALERT !!");
      lcd.setCursor(0, 1);
      lcd.print("Motion Detected");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Status: Clear");
      lcd.setCursor(0, 1);
      lcd.print("Monitoring...");
    }
    
    lastState = currentState; // Store state
  }
  delay(100); 
}
