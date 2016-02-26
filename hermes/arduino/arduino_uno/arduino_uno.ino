/*
Arduino Servo Test sketch
*/
#include "MsTimer2.h"
#include <Servo.h>
Servo servoL1; // Define our Servo
Servo servoR1;
Servo servoL2; // Define our Servo
Servo servoR2;

int angle=30;
int cpL1=90;
int cpR1=90;
int cpL2=90;
int cpR2=90;
int angleL=30;
int angleR=30;
int ledCounter=0;

void setup()
{
   servoL1.attach(11); // servo on digital pin 10
   servoR1.attach(10); // servo on digital pin 11
   servoL2.attach(9); // servo on digital pin 12
   servoR2.attach(8); // servo on digital pin 13

   startPosition();

   pinMode(7, OUTPUT);
   digitalWrite(7, HIGH);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
//   Timer0.initialize(1000000/6);         // initialize timer1, and set a 1/2 second period
//   Timer0.attachInterrupt(callback1);  // attaches callback() as a timer overflow interrupt
    MsTimer2::set(500, callback1); // 500ms period
    MsTimer2::start();
}

void loop()
{

     go(10);
   
}

void startPosition(){
  servoR1.write(cpR1);
  servoL1.write(cpL1); 
  servoR2.write(cpR2);
  servoL2.write(cpL2); 
  delay(2000);
}

void firstStep(){
  
}

void go(int mDelay){
  

   // przechyl na lewo
    for(int i=0; i<angleL; i++){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
    delay(mDelay);
    }
    servoR2.write(cpR2);
    servoL2.write(cpL2); 
   
    // obroc na stopie
    for(int i=0; i<90; i++){
      servoL2.write(cpL2+i);
      servoR2.write(cpR2+i);
      delay(mDelay);
    }
    // wyprostuj sie
    for(int i=angleL; i>0; i--){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
      delay(mDelay);
    }
    // przechyl na prawo
    for(int i=0; i<angleR; i++){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
    delay(mDelay);
    } 
    // obroc na stopie
    for(int i=90; i>0; i--){
      servoL2.write(cpL2+i);
      servoR2.write(cpR2+i);
      delay(mDelay);
    }
     // wyprostuj sie
    for(int i=angleR; i>0; i--){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
      delay(mDelay);
    }  
}

void callback()
{     
  int a=7;
  if(digitalRead(a)==HIGH){
    digitalWrite(a, digitalRead(a) ^ 1);
    digitalWrite(a-1,HIGH);
  }else if (digitalRead(6)==HIGH){
    digitalWrite(6, digitalRead(6) ^ 1);
    digitalWrite(6-1,HIGH);
  }else if (digitalRead(5)==HIGH){
    digitalWrite(5, digitalRead(5) ^ 1);
    digitalWrite(5-1,HIGH);
  }
  else if (digitalRead(4)==HIGH){
    digitalWrite(4, digitalRead(4) ^ 1);
    digitalWrite(4-1,HIGH);
  }
  else if (digitalRead(3)==HIGH){
    digitalWrite(3, digitalRead(3) ^ 1);
    digitalWrite(3-1,HIGH);
  }
  else if (digitalRead(2)==HIGH){
    digitalWrite(2, digitalRead(2) ^ 1);
    digitalWrite(7,HIGH);
  }
}

void callback1(){
  ledCounter++;
  switch (ledCounter%6){
  case 1:
    digitalWrite(7, HIGH);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
    break;
   case 2:
    digitalWrite(6, HIGH);
    break;
    case 3:
    digitalWrite(5, HIGH);
    break;
   case 4:
    digitalWrite(4, HIGH);
    break;
    case 5:
    digitalWrite(3, HIGH);
    break;
   default:
    digitalWrite(2, HIGH);
    break;
  }
}
 
  

