int r = 1;

void setup()
{
  Serial.begin(9600);
}

int counton = 0;
int countoff = 0;

void loop()
{
  if(Serial.available())
  {
    int r = Serial.read();
    if(r==0)
    {
      Serial.print("OFF");
      Serial.println(r);
      digitalWrite(12, HIGH);
      delay(500);
    }
    else
    {
      Serial.println(r);
      digitalWrite(12, LOW);
      delay(500);
    }
  }
}
