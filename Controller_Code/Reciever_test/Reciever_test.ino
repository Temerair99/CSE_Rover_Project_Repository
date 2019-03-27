#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <Servo.h>

RF24 radio(7,8);
const byte address[6] = "00001";


void setup()
{
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(115200);
}
void loop()
{
  delay(500);
  radio.startListening();
  if(radio.available())
  {
    while(radio.available())
    {
      int dir = 0;
      radio.read(&dir, sizeof(dir));
      
      if(dir == 0)
      {
        Serial.println("Not Moving");
        Serial.print("\n");
        delay(1000);
      }
      else if(dir == 1)
      {
        Serial.println("Going Forward!\n\n");
        Serial.print("\n");
        delay(1000);
      }
      else if(dir == 2)
      {
        Serial.println("Going Forward to the Right!\n\n");
        delay(1000);
      }
      else if(dir == 3)
      {
        Serial.println("Going Right!\n\n");
        delay(1000);
      }
      else if(dir == 4)
      {
        Serial.println("Going Backward to the Right!\n\n");
        delay(1000);
      }
      else if(dir == 5)
      {
        Serial.println("Going Backwards!\n\n");
        delay(1000);
      }
      else if(dir == 6)
      {
        Serial.println("Going Backward to the Left!\n\n");
        delay(1000);
      }
      else if(dir == 7)
      {
        Serial.println("Going Left!\n\n");
        delay(1000);
      }
      else if(dir == 8)
      {
        Serial.println("Going Forward to the Left!\n\n");
        delay(1000);
      }
      else if(dir == 9)
      {
        Serial.println("Spinning Left!\n\n");
        delay(1000);
      }
      else if(dir == 10)
      {
        Serial.println("Spinning Right!\n\n");
        delay(1000);
      }
      else
      {
        Serial.println("Not Connected");
      }
    }
  }
}
