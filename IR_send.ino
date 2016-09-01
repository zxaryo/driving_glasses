// Default IR Digital pin no 3
#include<IRremote.h>
IRsend irsend;
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
   for (int i=0; i<3; i++)
    {
      irsend.sendNEC(0x00ff01fe, 32);
      delay(400);
    }
}
