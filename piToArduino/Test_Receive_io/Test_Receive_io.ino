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
  radio.openReadingPipe(0, address);
  
}
void loop()
{ 
  //priority code
  int dir;
  while(1){
    radio.startListening();
    if(radio.available()){//listen to controller
      while(radio.available()){
        radio.read(&dir, sizeof(dir));
        if(dir != 0){
          //taking controller input that is not 0
          Serial.println(dir);//input dirL here
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
        r = Serial.read();
        Serial.println(r);
        delay(500);
      }
    }
  }
  //0-10 conditions below
  
}
