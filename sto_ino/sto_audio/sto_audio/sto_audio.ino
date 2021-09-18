
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>         //  also need to include this library...
#include <SPI.h>

#include "Servo.h"

#define OFF 90
#define ON 0

Servo s;

const int sPin = 7;

TMRpcm tmrpcm;   // create an object for use in this sketch
 
void setup(){

  s.attach(sPin);
  s.write(OFF);
  s.detach();
 
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  return;   // don't do anything more if not
  }
 tmrpcm.volume(1);
 
}
 
void loop(){  


//      delay(1000);
      tmrpcm.play("be.wav"); // mus.wav ; be.wav
      delay(3000);

      s.attach(sPin);
      s.write(ON);
      delay(750);
      s.write(OFF);
      delay(200);
      s.detach();
      delay(2500);
}
  
