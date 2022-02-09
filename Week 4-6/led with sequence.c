

 int led_1      = 12;
 int led_2      = 11;
 int led_3      = 10;
 int led_4      =  9;
 int button     =  7;
 int pot        = A1;
 int potvalue   =  0;
 int LED;
 int buttonVal;
static bool buttonstate =  LOW;


 void setup()
 {
   Serial.begin(115200);
   pinMode(led_1,OUTPUT);
   pinMode(led_2,OUTPUT);
   pinMode(led_3,OUTPUT);
   pinMode(led_4,OUTPUT);
   pinMode(button ,INPUT) ;
   LED = led_1;
 }

 void loop()
 {
     buttonVal = digitalRead(button);
     Serial.print("buttonVal : ");
     Serial.println(buttonVal);
     if(digitalRead(button) == HIGH)
       buttonstate = !buttonstate;
     delayMicroseconds(5000);

     if(buttonstate == true)
     {
        potvalue = analogRead(pot);

        if(LED < led_4)
          LED = led_1;

        digitalWrite(LED, HIGH);
        delay(potvalue);
        digitalWrite(LED, LOW);
        delay(potvalue);

        LED--;
    }
    else
    {
       digitalWrite(12,LOW);
       digitalWrite(11,LOW);
       digitalWrite(10,LOW);
       digitalWrite( 9,LOW);
    }
 }