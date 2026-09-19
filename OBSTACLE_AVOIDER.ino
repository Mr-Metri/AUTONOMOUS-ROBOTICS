#include <AFMotor.h>

//defining pins and variables
int LS = A1;     // Left Sensor
int MS = A3;    // Middle Sensor 
int RS = A5;   // Right Sensor


//defining motors
AF_DCMotor motor1(1);
AF_DCMotor motor2(3);


void setup()
{
   pinMode(LS, INPUT);
   pinMode(MS, INPUT);
   pinMode(RS, INPUT);
}

void loop()
{   
     //Forward: NO OBSTACLE IN-FRONT OF ANY SENSOR
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1)) 
     {
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
     }
     
    // FRONT OBSTACLE: OBSTACLE IN-FRONT OF LS & RS
    if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0)) 
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

    // BACK OBSTACLE: OBSTACLE IN-FRONT OF MS
    if((digitalRead(RS)== 1) && (digitalRead(MS)== 0) && (digitalRead(LS)== 1)) 
     {
        motor1.run(RELEASE);
        motor1.setSpeed(0);
        motor2.run(RELEASE);
        motor2.setSpeed(0);
        delay(500);
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
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

     //RIGHT: OBSTACLE IN-FRONT OF LS ONLY
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
     
     //LEFT: OBSTACLE IN-FRONT OF RS
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
  
    
      
