/* Arduino 1 code
*/


#include <SoftwareSerial.h>

int button = 4;
int led    = 2;

void setup() 
{
  pinMode(button, INPUT_PULLUP); // set push button pin as input
  pinMode(led, OUTPUT);      // set LED pin as output
  digitalWrite(led, LOW);    // switch off LED pin

  Serial.begin(9600);       // initialize UART with baud rate of 9600 bps
}

void loop() 
{
  if(Serial.available()) 
  {
    char data = Serial.read();   
    if(data == '1') digitalWrite(led, HIGH);  // switch LED On
    if(data == '0') digitalWrite(led, LOW);   // switch LED Off
  }
}