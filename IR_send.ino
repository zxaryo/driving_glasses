#include<IRremote.h>
IRsend irsend;
void setup() 
{
  Serial.begin(9600);
}
void loop() 
{
  if (Serial.read() !=-1)
  {
   //for (int i=0; i<3; i++)
    {
      irsend.sendNEC(0x00ff01fe, 32);
      delay(400);
    }
  }
}
