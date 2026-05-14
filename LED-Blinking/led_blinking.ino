// C++ code
//
int Led=13;
void setup()
{
  pinMode(Led, OUTPUT);
}

void loop()
{
  digitalWrite(Led, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(Led, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
