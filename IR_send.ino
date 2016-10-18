#include <Time.h>
#include <TimeLib.h>
#include<IRremote.h>
IRsend irsend;

int val=50, bks=0, k=0;
byte ey=1,iy=0;
void setup() 
{
  pinMode(3,OUTPUT);  //IR_LED
  pinMode(9,OUTPUT);  //BUZZER
  pinMode(13,OUTPUT); //LED
  Serial.begin(9600);
  
{  digitalWrite(13,1);
  digitalWrite(9,1);
  delay(100);
  digitalWrite(13,0);
  digitalWrite(9,0);
  delay(75);
  digitalWrite(13,1);
  digitalWrite(9,0);
  delay(250);
  digitalWrite(9,0);
  digitalWrite(13,0);
  irsend.sendSony(0xa92, 12);
}
}
void cal(int bk)
{
  digitalWrite(13,1);
  for(int i=0; i<3; i++)
  {
    if(bk<4)      irsend.sendSony(0xa91, 12);
    else if(bk<7) irsend.sendSony(0xa92, 12);
    else if(bk<13) irsend.sendSony(0xa93, 12);
  }
  delay(50);
  digitalWrite(13,0);
}
void loop() 
{
  delay(1000);
  while(second()%15!=0)
  { 
     if(analogRead(A5)<val)
      ey=0;
     else ey=1;
     
     if(ey!=iy) 
     {
        bks++;
        Serial.println(bks);
     }
     iy=ey;
  }
    if(bks==0&&k==1)
  {
    for(int j=0; j<500; j++)
    {
     irsend.sendSony(0xa95, 12);
     digitalWrite(9,1);
     digitalWrite(13,0);
     delay(1000);
     digitalWrite(9,0);
     digitalWrite(13,0); 
     delay(1000);
    }
  }
  if(bks==0&&k==0)
  {
    k=1;
    digitalWrite(9,1);
    digitalWrite(13,1);
    delay(3000);
    digitalWrite(9,0);
    digitalWrite(13,0);
  }

  bks/=2;
  cal(bks);
  bks=0;
}
