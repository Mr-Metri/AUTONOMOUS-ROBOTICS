
/* 
Designed and Developed by:
 "YOUNG INNOVATORS EDUCATIONAL SERVICES PVT. LTD."


NOTE:
 YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
 GO TO SKETCH >> INCLUDE LIBRARY >> MANAGE LIBRARIES >> SEARCH FOR AFMOTOR AND INSTALL IT 
 OR DOWNLOAD FROM GOOGLE
 GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //
*/

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
    // STOP : NO-HAND ON EITHER SIDE OF ROBOT
    if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1)) 
    {
      motor1.run(RELEASE);
      motor1.setSpeed(0);
      motor2.run(RELEASE);
      motor2.setSpeed(0);
    }

   // STOP : HAND ON BOTH SIDE OF ROBOT
    if((digitalRead(RS)== 0) && (digitalRead(MS)== 0) && (digitalRead(LS)== 0)) 
    {
      motor1.run(RELEASE);
      motor1.setSpeed(0);
      motor2.run(RELEASE);
      motor2.setSpeed(0);
    }
     
     //Forward : WHEN WE KEEP OUR HAND IN-FRONT OF BOTH LS & RS
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0)) 
     {
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
     }
   
     //Backward : WHEN WE KEEP OUR HAND ONLY IN-FRONT OF MS
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 0) && (digitalRead(LS)== 1)) 
     {
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
     }
   
     //Sharp Left: WHEN WE KEEP OUR HAND IN-FRONT LS 
     if((digitalRead(RS)== 1) && (digitalRead(MS)== 1) && (digitalRead(LS)== 0))   
     {
        motor1.run(BACKWARD);
        motor1.setSpeed(255);
        motor2.run(FORWARD);
        motor2.setSpeed(255);
     }
     
     //Sharp Right: WHEN WE KEEP OUR HAND IN-FRONT RS 
     if((digitalRead(RS)== 0) && (digitalRead(MS)== 1) && (digitalRead(LS)== 1))    
     {
        motor1.run(FORWARD);
        motor1.setSpeed(255);
        motor2.run(BACKWARD);
        motor2.setSpeed(255);
     } 
}
      
