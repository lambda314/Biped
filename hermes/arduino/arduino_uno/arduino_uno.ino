/*
Arduino Servo Test sketch
*/
#include "MsTimer2.h"
#include <Servo.h>

#define sensorR A1
#define sensorL A0

Servo servoL1; // Define our Servo
Servo servoR1;
Servo servoL2; // Define our Servo
Servo servoR2;

int oneStep=90;
int cpL1=90;
int cpR1=100;
int cpL2=90-oneStep/2;
int cpR2=90-oneStep/2;
int angleL=45;
int angleR=45;
int ledCounter=0;
int mDelay=8;

int d_oneStep=0;
float k=0.05;

void setup()
{
   servoL1.attach(11); // servo on digital pin 10
   servoR1.attach(10); // servo on digital pin 11
   servoL2.attach(9); // servo on digital pin 12
   servoR2.attach(8); // servo on digital pin 13

   pinMode(7, OUTPUT);
   digitalWrite(7, HIGH);
   pinMode(6, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(1, INPUT);
   Serial.begin(9600);
   
   MsTimer2::set(1000/6, callback); // 500ms period
   startPosition();

   while(digitalRead(1)==HIGH){ 
   }
   Serial.println("start");
   delay(2000);
   
   MsTimer2::start();
   firstStep(mDelay); 
}
void loop()
{
     go(mDelay);
}

void startPosition(){
  servoR1.write(cpR1);
  servoL1.write(cpL1); 
  servoR2.write(cpR2);
  servoL2.write(cpL2); 
  delay(2000);
}

void firstStep(int mDelay){
  // przechyl na lewo
    for(int i=0; i<angleL; i++){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
    delay(mDelay);
    }
    servoR2.write(cpR2);
    servoL2.write(cpL2); 
   
    // obroc na stopie
    for(int i=0; i<oneStep/2; i++){
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
    for(int i=0; i<angleL; i++){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
    delay(mDelay);
    }
    servoR2.write(cpR2);
    servoL2.write(cpL2); 
   
    // obroc na stopie
    for(int i=0; i<oneStep; i++){
      servoL2.write(cpL2+oneStep/2-i);
      servoR2.write(cpR2+oneStep/2-i);
      delay(mDelay);
    }
    // wyprostuj sie
    for(int i=angleL; i>0; i--){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
      delay(mDelay);
    }
}

void go(int mDelay){
  int d_maxL=analogRead(sensorL);
  int d_maxR=analogRead(sensorR);
  
   // przechyl na lewo
    for(int i=0; i<angleL; i++){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
    delay(mDelay);
    }
    servoR2.write(cpR2);
    servoL2.write(cpL2); 
   
    // obroc na stopie
    Serial.println(oneStep+d_oneStep);
    for(int i=0; i<oneStep+d_oneStep; i++){
      servoL2.write(cpL2-oneStep/2+i);
      servoR2.write(cpR2-oneStep/2+i);

      if(analogRead(sensorR)>d_maxR){
        d_maxR=analogRead(sensorR);
      }
      if(analogRead(sensorL)>d_maxL){
        d_maxL=analogRead(sensorL);
      }
      
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
    Serial.println(oneStep-d_oneStep);
    for(int i=0; i<oneStep-d_oneStep; i++){
      servoL2.write(cpL2+oneStep/2-i);
      servoR2.write(cpR2+oneStep/2-i);

      if(analogRead(sensorR)>d_maxR){
        d_maxR=analogRead(sensorR);
      }
      if(analogRead(sensorL)>d_maxL){
        d_maxL=analogRead(sensorL);
      }
      
      delay(mDelay);
    }
     // wyprostuj sie
    for(int i=angleR; i>0; i--){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
      delay(mDelay);
    }  

    d_oneStep=k*(d_maxL-d_maxR);
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
 
  

