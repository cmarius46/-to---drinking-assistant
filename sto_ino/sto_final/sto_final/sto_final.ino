
#include <pcmRF.h>
#include <pcmConfig.h>
#include <TMRpcm.h>

#include "Servo.h"

#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>         //  also need to include this library...
#include <SPI.h>

#define LEFT 60
// reset pos is 90
#define MIDDLE 90
#define RIGHT 120

#define OFF 90
#define ON 0

Servo dir;

Servo tap1, tap2; // water taps

TMRpcm tmrpcm; 

char inputByte;

const int dirPin = 5;
const int tap1Pin = 7;
const int tap2Pin = 8;

const int eyesPin = 6;

const int eyesDrunkPin = 3; // 9 currently

const int mouthPin = A1;

void setup() {
  // put your setup code here, to run once:

  // servos
  dir.attach(dirPin);
  dir.write(MIDDLE);
  
  tap1.attach(tap1Pin);
  tap1.write(OFF);
  
  tap2.attach(tap2Pin);
  tap2.write(OFF);

  delay(200);

  dir.detach();
  tap1.detach();
  tap2.detach();
  

  // media
  pinMode(mouthPin, OUTPUT);
  pinMode(eyesPin, OUTPUT);
  pinMode(eyesDrunkPin, OUTPUT);

  digitalWrite(eyesPin, HIGH);
  
  tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  return;   // don't do anything more if not
  }
  tmrpcm.volume(1);
  
  
  // bluetooth
  Serial.begin(9600);

}

// commands 
// t - tequila
// j - jager
// A - armagheddon

// f - fw
// l - left
// r - right
// m - middle

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
    inputByte= Serial.read();
    Serial.println(inputByte);
    
    if (inputByte=='t'){


      tmrpcm.play("mus.wav"); // mus.wav ; be.wav
      mus();
//      delay(3000);

      tap1.attach(tap1Pin);
      //tap2.attach(tap2Pin);
      
      // tequila
      tap1.write(ON);
      delay(1500);
      tap1.write(OFF);

      delay(200);

      tap1.detach();
      //tap2.detach();

      delay(500);
      
      tmrpcm.play("be.wav"); // mus.wav ; be.wav
      be();
//      delay(3000); // now included in be()

      resetEyes();

      
    }
    else if (inputByte=='j'){

      tmrpcm.play("mus.wav"); // mus.wav ; be.wav
      mus();
//      delay(3000);

      //tap1.attach(tap1Pin);
      tap2.attach(tap2Pin);
      
      // jagermeister
      tap2.write(ON);
      delay(1500);
      tap2.write(OFF);

      delay(200);

      //tap1.detach();
      tap2.detach();

      delay(500);
      
      tmrpcm.play("be.wav"); // mus.wav ; be.wav
      be();
//      delay(3000); // now included in be()

      resetEyes();
      
      
    }
    else if (inputByte=='A'){

      tmrpcm.play("mus.wav"); // mus.wav ; be.wav
      mus();
//      delay(3000);

      tap1.attach(tap1Pin);
      tap2.attach(tap2Pin);
      
      // Armagheddon
      tap1.write(ON);
      tap2.write(ON);
      delay(750);
      tap1.write(OFF);
      tap2.write(OFF);

      delay(200);

      tap1.detach();
      tap2.detach();

      delay(500);
      
      tmrpcm.play("be.wav"); // mus.wav ; be.wav
      be();
//      delay(3000); // now included in be()

      resetEyes();
      
    }
    else if (inputByte=='f'){
      // forward
    }
    else if (inputByte=='l'){
      // left
      dir.write(LEFT);
    }
    else if (inputByte=='r'){
      // right
      dir.write(RIGHT);
    }
    else if (inputByte=='m'){
      // straight
      dir.write(MIDDLE);
    }
    else if(inputByte == 'p') {
      tmrpcm.play("be.wav"); // mus.wav ; be.wav
      be();
//      delay(3000); // now included in be()
    }
    else if(inputByte == 'q') {
      tmrpcm.play("mus.wav"); // mus.wav ; be.wav
      delay(3000);
    }

    delay(1000);

  }
}

void be() {
  digitalWrite(mouthPin, HIGH);
  delay(150);
  digitalWrite(mouthPin, LOW);
  delay(200);
  digitalWrite(mouthPin, HIGH);
  delay(150);
  digitalWrite(mouthPin, LOW);
  delay(200);
  digitalWrite(mouthPin, HIGH);
  delay(100);
  digitalWrite(mouthPin, LOW);
  delay(100);
  digitalWrite(mouthPin, HIGH);
  delay(100);
  digitalWrite(mouthPin, LOW);
  delay(3000);
}

void mus() {
  digitalWrite(eyesPin, LOW);
  digitalWrite(eyesDrunkPin, HIGH);
  delay(150);
  digitalWrite(eyesPin, HIGH);
  digitalWrite(eyesDrunkPin, LOW);
  delay(150);
  digitalWrite(eyesPin, LOW);
  digitalWrite(eyesDrunkPin, HIGH);
  delay(150);
  
  delay(3000);
}

void resetEyes() {
  digitalWrite(eyesDrunkPin, LOW);
  digitalWrite(eyesPin, HIGH);
}
