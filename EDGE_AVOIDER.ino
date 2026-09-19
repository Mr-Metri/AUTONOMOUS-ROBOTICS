#include <AFMotor.h>

//defining pins and variables
int LS = A0;     // Left Sensor
int MS = A1;    // Middle Sensor 
int RS = A2;   // Right Sensor


//defining motors
AF_DCMotor motor1(4);
AF_DCMotor motor2(3);


void setup()
{
   pinMode(LS, INPUT);
   pinMode(MS, INPUT);
   pinMode(RS, INPUT);
}

void loop()
{   
     //Forward: ALL Sensor's ARE ON NORMAL SURFACE
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 0) && (digitalRead(LS)== 0)) 
     {
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
     }
     
    // ON EDGE:STOP-BACKWARD-CHANGE DIRECTION
    if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1)) 
     {
        motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(2000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(2000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
      }

     //Sharp RIGHT: When Left and Middle Sensor on EDGE
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1))   
     {
         motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
      }
     
     //Sharp Left: When Left and Middle Sensor on EDGE
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0))   
     {
        motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
      }   

    //RIGHT: When LEFT Sensor IS ON EDGE
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 0) && (digitalRead(LS)== 1))   
      {
        motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
      }
     
     //LEFT: When RIGHT Sensor IS ON EDGE
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 0) && (digitalRead(LS)== 0))   
      {
        motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
        delay(1000);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
      }     
}
  
    
      
