#define ir_led 3
#define led 13
#define buz 9
#include <Time.h>
#include <TimeLib.h>
#include<IRremote.h>
IRsend irsend;

int val=50, bks=0, k=0;
byte ey=1,iy=0;
void setup() 
{
  pinMode(ir_led,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);

  ind(led,100,2);
  ind(buz,100,2);
  irsend.sendSony(0xa92, 12);
}
void ind(int pin,int del,int tim)
{
  for(int i=0;i<tim;i++)
  {
    digitalWrite(pin,1);
    delay(del);
    digitalWrite(pin,0);
    delay(del);
  }
}
void cal(int bk)
{
    for(int i=0; i<3; i++)
    {
        if(bk<4)   
        {
          irsend.sendSony(0xa91, 12);
          ind(led,50,3);
        }
        else if(bk<7) 
        {
          irsend.sendSony(0xa92, 12);
          ind(led,50,2);
        }
        else if(bk<led) 
        {
          irsend.sendSony(0xa93, 12);
          ind(led,50,3);
        }
    }
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
  if(bks>=14) bks=0;
  if(bks==0&&k==1)
      {
        for(int j=0; j<500; j++)
        {
         irsend.sendSony(0xa95, 12);
         ind(led,50,1);
         ind(buz,500,10);
        }
      }
      if(bks==0&&k==0)
      {
        k=1;
        ind(led,100,1);
        ind(buz,500,2);
        ind(led,100,1);
        ind(buz,500,1);
      }
  bks/=2;
  cal(bks);
  bks=0;
}
