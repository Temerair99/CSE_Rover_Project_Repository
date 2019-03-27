int r=1;
void setup(){
  Serial.begin(9600);
}
int counton=0;
int countoff=0;
void loop()
{
  if(Serial.available())
  {
    //r=(Serial.read()-'0');
    //Serial.println(r);
    //if(r == '1')//{
     int r = Serial.read();
     if(r==48)
      {
        //++counton;
        Serial.print("NOT ON ANYMORE ");
        Serial.println(r);
        digitalWrite(12, HIGH);
        delay(500);
        //digitalWrite(12, LOW);
        //delay(500);
      }
      else//(Serial.read()==49)
      {
        //++countoff;
        Serial.print("NOT OFF ANYMORE ");
        Serial.println(r);
        digitalWrite(12, LOW);
        delay(500);
      }
  }
}

