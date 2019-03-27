#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

int r=1;
int input;
int delayCount = 5;
RF24 radio(7,8);
const byte address[6] = "00001";

void setup(){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe();
  
}
void loop()
{ 
  //priority code
  while(1){
    radio.startListening();
    if(radio.available()){//listen to controller
      while(radio.available()){
        r = radio.read();
        if(r != 0){
          //taking controller input that is not 0
          Serial.println(r);
          delayCount = 5;
        }
      }
    }
    //take pi input, if controller is available or not
    if(Serial.available())
    {
      if(delayCount > 0){
        //count down delay
        delay(3);
        delayCount = delayCount - 1;
      }else{
        //taking the pi input
        r = Serial.read()
        Serial.println(r);
        delay(500);
      }
    }
  }
  //0-10 conditions below
  
}

