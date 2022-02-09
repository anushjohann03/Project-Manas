int button      = 11;           //connection of the switch
int LED         = 3;          //connection of the led
int buttonState = LOW;        // declaring the state of the button that is off

void setup()
{
pinMode(button,INPUT);   //initialize pin 11 as input
pinMode(LED,OUTPUT);     //intialize pin 3 as output
}


void loop()
{
  if (digitalRead(button) == HIGH)        //reading the state of the button
  {
     buttonState = ! buttonState;          //inverse the button state
    digitalWrite(LED, buttonState);
  }  
     else
  {
    while(digitalRead(button) == HIGH);
    delay(50);
   }
}