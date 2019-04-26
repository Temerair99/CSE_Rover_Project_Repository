#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>

int delayCount = 5;
int dir;
// Ce: 9, CSN: 53, SCK: 52, MOSI: 51, MISO: 50
RF24 radio(9,53);
const byte address[5] = {'R','O','V','E','R'};

//Stepper Motor 1
#define STEPPER_PIN_1 35
#define STEPPER_PIN_2 37
#define STEPPER_PIN_3 39
#define STEPPER_PIN_4 41

//Stepper Motor 2
#define StepPin21 40
#define StepPin22 38
#define StepPin23 36
#define StepPin24 34

//Stepper Motor 3
#define StepPin31 28
#define StepPin32 26
#define StepPin33 24
#define StepPin34 22


void setup()
{
  //Pi to Arduino connection
  Serial.begin(9600);
  //Stepper Motor 1
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);
  //Stepper Motor 2
  pinMode(StepPin21, OUTPUT);
  pinMode(StepPin22, OUTPUT);
  pinMode(StepPin23, OUTPUT);
  pinMode(StepPin24, OUTPUT);
  //Stepper Motor 3
  pinMode(StepPin31, OUTPUT);
  pinMode(StepPin32, OUTPUT);
  pinMode(StepPin33, OUTPUT);
  pinMode(StepPin34, OUTPUT);

  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.startListening();
}

int inputnumb;
void loop()
{

 //COLLECT INPUT NUMBER HERE
 //Mike Cheng_godinez
 //Rick B
  if(radio.available()) //listen to controller
  {
    Serial.println("radio available");
    //while(radio.available())
    //{
      radio.read(&dir, sizeof(dir));
      inputnumb = dir;
      //rovernumb(dir);
        Serial.println(dir);  //input dir here
        delayCount = 5;
        //delay(500);
    //}
  }
  Serial.println(delayCount);
  if(Serial.available())
  {
    Serial.println("Serial available");
    if(delayCount > 0){
      Serial.println("delaying");
      delay(3);
      delayCount = delayCount - 1;
    }else{
      inputnumb = Serial.read();
      //Serial.println(inputnumb);
    }
  }
 //------------------------------------------------------------------------
 if(inputnumb == 0)
   //Do nothing
  ;
 else if(inputnumb == 1)//Forward
 {
    TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
    TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
    TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn left for motor 4
 }
 else if(inputnumb == 2)//up, right
 {
    TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
    TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
 }
 else if(inputnumb == 3)//strafe right
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
  //Add turnright for M4
 }
 else if(inputnumb == 4)//down,right
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  //turn right M4
 }
 else if(inputnumb == 5)//backwards
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
  //Turn right M4
 }
 else if(inputnumb == 6)//down, left
 {
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
 }
 else if(inputnumb == 7)//left
 {
  TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
  //Turn left M4
 }
 else if(inputnumb==8) //left, up
{
   TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
   //turn left M4
}
else if(inputnumb == 9)//rotate counter clockwise
{
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn left for motor 4
}
else if(inputnumb == 10)
{
  TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn Right for motor 4
}
 
 
 
 /*
  for(int i = 0; i<512; i++)
    TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  delay(1000);
  for(int i = 0; i<512; i++)
    TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  delay(1000);
  
  for(int i = 0; i<512; i++)
    TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
  delay(1000);
  for(int i = 0; i<512; i++)
    TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  delay(1000);
  
  for(int i = 0; i<512; i++)
    TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
  delay(1000);
  for(int i = 0; i<512; i++)
    TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
  delay(1000);
  */
}

void rovernumb(int inputnumb){
  //------------------------------------------------------------------------
 if(inputnumb == 0)
   //Do nothing
  ;
 else if(inputnumb == 1)//Forward
 {
    TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
    TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
    TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn left for motor 4
 }
 else if(inputnumb == 2)//up, right
 {
    TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
    TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
 }
 else if(inputnumb == 3)//strafe right
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
  //Add turnright for M4
 }
 else if(inputnumb == 4)//down,right
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  //turn right M4
 }
 else if(inputnumb == 5)//backwards
 {
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
  //Turn right M4
 }
 else if(inputnumb == 6)//down, left
 {
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
 }
 else if(inputnumb == 7)//left
 {
  TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
  //Turn left M4
 }
 else if(inputnumb==8) //left, up
{
   TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
   //turn left M4
}
else if(inputnumb == 9)//rotate counter clockwise
{
  TurnLeft(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnLeft(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnLeft(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn left for motor 4
}
else if(inputnumb == 10)
{
  TurnRight(STEPPER_PIN_1, STEPPER_PIN_2, STEPPER_PIN_3, STEPPER_PIN_4);
  TurnRight(StepPin21, StepPin22, StepPin23, StepPin24);
  TurnRight(StepPin31, StepPin32, StepPin33, StepPin34);
    //Add turn Right for motor 4
}
}

void TurnRight(int a, int b, int c, int d)
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  delay(2);
      
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  delay(2);
      
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  delay(2);
      
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  delay(2);
     
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  delay(2);
  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  delay(2);
   
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  delay(2);
   
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  delay(2);
}

void TurnLeft(int a, int b, int c, int d)
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  delay(2);
  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  delay(2);
  
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  delay(2);
  
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  delay(2);
  
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  delay(2);
  
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  delay(2);
  
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW); 
  delay(2);
  
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH); 
  delay(2);
}
