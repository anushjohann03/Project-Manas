/* 1 HC-SR04 & 6 LEDs.
 Get the reading from the ultrasonic sensor and display it as a fraction of the max sensing range on the LED.
1st LED glows for 0 to 1/n fraction,
2nd LED glows for 1/n to 2/n fraction, and so on.
*/


int led_1  = 12;
int led_2  =11;
int led_3  =10;
int led_4   = 9;
int led_5  =8;
int led_6  =7;
int trig =4;
int echo =2;
long distance;
long duration;



void setup()
{
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(led_3,OUTPUT);
  pinMode(led_4,OUTPUT);
  pinMode(led_5,OUTPUT);
  pinMode(led_6,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  digitalWrite(trig , LOW);
  Serial.begin(9600);
  
}



void loop()
{
    digitalWrite(trig , HIGH);
    delayMicroseconds(10);
    digitalWrite(trig , LOW);
    
    duration = pulseIn(echo, HIGH );

    distance = (duration*.0343)/2;
    Serial.println( duration);

     if ( distance <= 75 && distance >= 2 )
  {
    digitalWrite(led_1,HIGH);
  }
  else
  {
    digitalWrite(led_1,LOW);
  }
  if(distance <= 150 && distance >= 75 )
  {
    digitalWrite(led_2,HIGH);
  }
  else
  {
    digitalWrite(led_2,LOW);
  }
  if( distance <= 225 && distance >=150 )
  {
    digitalWrite(led_3,HIGH);
  }
  else
  {
    digitalWrite(led_3,LOW);
  }
   if( distance <= 300 && distance >= 225)
  {
    digitalWrite(led_4,HIGH);
  }
  else
  {
    digitalWrite(led_4,LOW);
  }
  if( distance <= 375 && distance >= 300 )
  {
    digitalWrite(led_5,HIGH);
  }
  else
  {
    digitalWrite(led_5,LOW);
  }
  if( distance <= 450 && distance >=375)
  {
    digitalWrite(led_6,HIGH);
  }
  else
  {
    digitalWrite(led_6,LOW);
  }
  delayMicroseconds(60);
}