include <SoftwareSerial.h>
#include <Servo.h>

/* 
1 Servo motor, 1 DC motor, 2 Push Buttons & 1 Potentiometer.
Servo sweeps from 0 to 180 and 180 to 0 degrees.
Speed is decided by the potentiometer.
On pressing the button, servo motor stops and the DC motor starts.
Speed of DC motor is decided by the potentiometer.
Direction of the motor is decided by the 2nd push button.
*/

#define BUTTON1	3
#define BUTTON2	5
#define POT		A0
#define MOTOR1	9
#define MOTOR2	7
#define SERVO	10

       bool button1Val;
       bool button2Val;
static int  potValue;
static int 	pos;
static bool motorSel;            // seletion between servo and dc motor
static bool motorDir;             //chande in direction
static int  delayValue;          //it is used to control the speed of motor by varying the delay
static bool lastButton1;
static bool lastButton2;

Servo servo_1;

void setup()
{
  servo_1.attach(SERVO);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(MOTOR1, OUTPUT);
  pinMode(MOTOR2, OUTPUT);
  Serial.begin(9600);
  button1Val	= 0;
  button2Val	= 0;
  potValue		= 0;
  motorSel		= 0;
  motorDir		= 0;
  delayValue 	= 0;
  lastButton1	= 0;
  lastButton2	= 0;
}

void loop()
{
  button1Val = digitalRead(BUTTON1);
  delay(5);

  if(button1Val)
  	if(button1Val != lastButton1)
  {
    	motorSel = !motorSel;
  }
        lastButton1 = button1Val;
  

  switch (motorSel)
  {
  case 0:
        digitalWrite(MOTOR1, HIGH);
        digitalWrite(MOTOR2, HIGH);
        potValue 	= analogRead(POT);
        delayValue	= map(potValue, 0, 1023, 20, 500);
        pos++;                     //increases the angle of servo
        if(pos == 180)             
           pos = -180;
        servo_1.write(abs(pos));    //abs is used to get a absolute value as the angles goes in the negative side
        delay(delayValue);
        break;
  case 1:
         pos = 0;
         servo_1.write(pos);
         button2Val = digitalRead(BUTTON2);
         delay(5);
    
         if(button2Val)
    	    if(button2Val != lastButton2)
         {
    		    motorDir = !motorDir;
         }
         lastButton2 = button2Val;
    
         potValue 	= analogRead(POT);
         delayValue  = map(potValue, 0, 1023, 20, 1000);
  	
         if(motorDir)
         {
            digitalWrite(MOTOR1, LOW);
            digitalWrite(MOTOR2, HIGH);
          }
         else{
              digitalWrite(MOTOR1, HIGH);
              digitalWrite(MOTOR2, LOW);
         }
          delay(delayValue);
          break;
  }
}