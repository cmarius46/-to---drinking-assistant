#include "Servo.h"

#define LEFT 60
// reset pos is 90
#define MIDDLE 90
#define RIGHT 120

#define OFF 90
#define ON 0

Servo dir;

Servo tap1, tap2; // water taps

char inputByte;

const int dirPin = 5;
const int tap1Pin = 7;
const int tap2Pin = 8;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  dir.attach(dirPin);
  dir.write(MIDDLE);
  
  tap1.attach(tap1Pin);
  tap1.write(OFF);
  
  tap2.attach(tap2Pin);
  tap2.write(OFF);

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
      // tequila
      tap1.write(ON);
      delay(1500);
      tap1.write(OFF);
    }
    else if (inputByte=='j'){
      // jagermeister
      tap2.write(ON);
      delay(1500);
      tap2.write(OFF);
    }
    else if (inputByte=='A'){
      // Armagheddon
      tap1.write(ON);
      tap2.write(ON);
      delay(750);
      tap1.write(OFF);
      tap2.write(OFF);
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

    delay(1000);

  }
}
