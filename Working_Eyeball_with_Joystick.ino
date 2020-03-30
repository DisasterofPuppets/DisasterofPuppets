// letsarduino.com
// [Project 11] - 2 Servos Using a Joystick 
//  (thumbstick) + Arduino

#include <Servo.h>  

int ServoHorizontalPin = 9;   
int ServoVerticalPin =  10;   
int HorizontalPotPin = A0; // VRy
int VerticalPotPin = A1;  // VRx
int ServoH_Min = 0;  
int ServoH_Max = 180; 
int ServoV_Min = 0; 
int ServoV_Max = 180; 

Servo HorizontalServo;  
Servo VerticalServo;    

int HorizontalPotValue;         
int HorizontalServoPosition;    
int VerticalPotValue;         
int VerticalServoPosition;    

void setup()   
{
  HorizontalServo.attach(ServoHorizontalPin);   
  VerticalServo.attach(ServoVerticalPin);         
}

void loop()  
{
  HorizontalPotValue  = analogRead(HorizontalPotPin); 
  VerticalPotValue  = analogRead(VerticalPotPin);  
  HorizontalServoPosition  = map(HorizontalPotValue, 0, 1023, ServoH_Min , ServoH_Max); 
  VerticalServoPosition  = map(VerticalPotValue, 1023, 0, ServoH_Max , ServoH_Min);   
  HorizontalServo.write(HorizontalServoPosition);       
  VerticalServo.write(180-VerticalServoPosition);       
  delay(20);    
}
