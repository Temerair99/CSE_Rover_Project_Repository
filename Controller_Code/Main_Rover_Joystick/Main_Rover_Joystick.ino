/* Arduino Rover Project
  *  Jared Acosta:
  *      Programmed everything regarding the nRF24 transceiver module.
  *  Christian Mesina:
  *      Set all the declarations regarding the joystick modules.
  *      Programmed the Joystick() Function, conditions 0-8.
  *  Eugene Kim:
  *      Programmed the Joystick() Function, conditions 9-10.
  *      Combined the Left and Right Joystick Functions into one function.
 */

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

// Arduino pin numbers
const int XL_pin = 0; // analog pin connected to X output
const int YL_pin = 1; // analog pin connected to Y output
const int XR_pin = 2;

RF24 radio(7,8);   //CSn
const byte address[6] = "00001";

void setup() 
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  Serial.begin(115200);
}

void loop() 
{
  Serial.print("--------------------------------------\n");
  /*
  Serial.print("XL-axis: ");
  Serial.print(analogRead(XL_pin));
  Serial.print("\n");
  Serial.print("YL-axis: ");
  Serial.println(analogRead(YL_pin));
  Serial.print("\n");
  Serial.print("XR-axis: ");
  Serial.print(analogRead(XR_pin));
  Serial.print("\n");
  Serial.print("\n\n");
  */

  JoyStick();

  delay(500);
}

void JoyStick()
{
  int dir;

  int x = analogRead(XL_pin);
  int y = analogRead(YL_pin);
  int x2 = analogRead(XR_pin);

  if (400 < x && x < 600 && 400 < y && y < 600 && 400 < x2 && x2 < 600)   // Origin = (546, 532)
  {
    dir = 0;
    radio.write(&dir, sizeof(dir));
    Serial.println("Left Joystick Staying Still");   // Staying Still
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }
  else if(x > 600 && 400 < y && y < 600)    // Area 1 = (1023,533)
  {
    dir = 1;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Forward!");   // Forward Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }

   else if(x > 600 && y > 600)    // Area 2 = (1023,1023)
  {
    dir = 2;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Foward to the Right!");    // North East Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }
  
  else if(400 < x && x < 600 && y > 600)    // Area 3 = (545,1023)
  {
    dir = 3;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Right!");   // Right Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }

  else if(x < 400 && y > 600)   // Area 4 = (1023, 1023)
  {
    dir = 4;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Back to the Right!");    // South East Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }

  else if(x < 400 && 400 < y && y < 600)    // Area 5 = (30,1023)
  {
    dir = 5;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Backwards!");   // Backwards Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }
  
  else if(x < 400 && y < 400)   // Area 6 = (30,30)
  {
    dir = 6;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Back to the Left!");    // South West Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }
  
  else if(400 < x && x < 600 && y < 400)   // Area 7 = (545,30)
  {
    dir = 7;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Left!");    // Left Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }

  else if(x > 600 && y < 400)   // Area 8 = (1023,30)
  {
    dir = 8;
    radio.write(&dir, sizeof(dir));
    Serial.println("Going Forward to the Right!");    // North West Direction
    Serial.println(dir);
    Serial.println("\n");
    delay(500);
  }
  if(x2 < 400)
  {
    dir = 9;
    radio.write(&dir, sizeof(dir));
    Serial.println("Spinning Left!");   // Spin Left
    Serial.println(dir);
    Serial.print("\n");
    delay(500);
  }
  else if(x2 > 600)
  {
    dir = 10;
    radio.write(&dir, sizeof(dir));
    Serial.println("Spinning Right!");    // Spin Right
    Serial.println(dir);
    Serial.print("\n");
    delay(500);
  }
}
