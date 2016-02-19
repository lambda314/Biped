/*
Arduino Servo Test sketch
*/

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


void setup()
{
   servoL1.attach(10); // servo on digital pin 10
   servoR1.attach(11); // servo on digital pin 11
   servoL2.attach(12); // servo on digital pin 12
   servoR2.attach(13); // servo on digital pin 13
   
   servoR1.write(cpR1);
     servoL1.write(cpL1); 
     servoR2.write(cpR2);
     servoL2.write(cpL2); 
    delay(2000);
}

void loop()
{

      go(); 
   
}

void kolyska(){
 
   
     servoR1.write(cpR1);
     servoL1.write(cpL1); 
     servoR2.write(cpR2);
     servoL2.write(cpL2); 
     delay(2000);

    for(int i=0; i<angleL; i++){
    servoR1.write(cpR1+i);
    servoL1.write(cpL1+i);
    delay(20);
    }

     servoR2.write(cpR2);
     servoL2.write(cpL2); 
     delay(2000);

    for(int i=angleL; i>0; i--){
    servoR1.write(cpR1+i);
    servoL1.write(cpL1+i);
    delay(20);
    }

     servoR2.write(cpR2);
     servoL2.write(cpL2); 
     delay(2000);

      for(int i=0; i<angleR; i++){
        servoR1.write(cpR1-i);
        servoL1.write(cpL1-i);
        delay(20);
      }
  
     servoR2.write(cpR2);
     servoL2.write(cpL2); 
     delay(2000);

     
      for(int i=angleR; i>0; i--){
        servoR1.write(cpR1-i);
        servoL1.write(cpL1-i);
        delay(20);
      }
  
     servoR2.write(cpR2);
     servoL2.write(cpL2); 
  
     delay(2000);
}

void go(){

   // przechyl na lewo
    for(int i=0; i<angleL; i++){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
    delay(20);
    }
    servoR2.write(cpR2);
    servoL2.write(cpL2); 
    //delay(2000);
    // obroc na stopie
    for(int i=0; i<90; i++){
      servoL2.write(cpL2+i);
      servoR2.write(cpR2+i);
      delay(20);
    }
    //delay(2000);
    // wyprostuj sie
    for(int i=angleL; i>0; i--){
      servoR1.write(cpR1+i);
      servoL1.write(cpL1+i);
      delay(20);
    }
    //delay(2000);

    // przechyl na prawo
    for(int i=0; i<angleR; i++){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
    delay(20);
    } 
    //delay(2000);
    // obroc na stopie
    for(int i=90; i>0; i--){
      servoL2.write(cpL2+i);
      servoR2.write(cpR2+i);
      delay(20);
    }
    //delay(2000);
     // wyprostuj sie
    for(int i=angleR; i>0; i--){
      servoR1.write(cpR1-i);
      servoL1.write(cpL1-i);
      delay(20);
    }
    //delay(2000);
    
   
    
}

