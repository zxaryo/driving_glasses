#define led_red 3
#define led_org 2
#define d0 5
#define d1 6
#define d2 7
#define d3 8
#define d4 9
#define motor_a 12
#define motor_b 13

#include<IRremote.h>

int  spp=40, mdel;
byte a[10][4]={
   {0,0,0,0}
,  {0,0,0,1}
,  {0,0,1,0}
,  {0,0,1,1}
,  {0,1,0,0}
,  {0,1,0,1}
,  {0,1,1,0}
,  {0,1,1,1}
,  {1,0,0,0}
,  {1,0,0,1}};

int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() 
{
 pinMode(led_org, OUTPUT);
 pinMode(led_red, OUTPUT);
 pinMode(d1, OUTPUT);
 pinMode(d2, OUTPUT);
 pinMode(d3, OUTPUT);
 pinMode(d4, OUTPUT);
 pinMode(d0, OUTPUT);
 pinMode(motor_a,OUTPUT);
 pinMode(motor_b,OUTPUT);
 Serial.begin(9600);
 irrecv.enableIRIn();
 //setTime(0);
}
void indicator()
{ for(int i=0;i<5;i++)
 {
  digitalWrite(led_org,1);
  delay(500);
  digitalWrite(led_org,0);
  delay(500);
 }
   digitalWrite(led_red,1);
   delay(500);
}
void ds(int sped)
{   if(sped>0)
    digitalWrite(motor_a,1);
    digitalWrite(motor_b,0);
    int x=sped%10;
    int y=sped/10;
    digitalWrite(d0,0);
    dd(x);
    delay(4);
    digitalWrite(d0,1);
    dd(y);
    delay(4); 
    digitalWrite(motor_a,0);
    if(sped==60) mdel=4;
    else if(sped==40) mdel==6;
    else if(sped==20) mdel==8;
    delay(mdel);
}
int cmap(char zx)
{
  if(zx=='0') return(0);
  if(zx=='1') return(1);
  if(zx=='2') return(2);
  if(zx=='3') return(3);
  if(zx=='4') return(4);
  if(zx=='5') return(5);
  if(zx=='6') return(6);
  if(zx=='7') return(7);
  if(zx=='8') return(8);
  if(zx=='9') return(9);
  
}
void dd(int x)
{
  digitalWrite(d1,a[x][3]);
  digitalWrite(d2,a[x][2]);
  digitalWrite(d3,a[x][1]);
  digitalWrite(d4,a[x][0]);

}
void loop()
{ 
    if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);    
    if      (results.value==0xa91)  spp=60;
    else if (results.value==0xa92)  spp=40;
    else if (results.value==0xa93)  spp=20;
    else if (results.value==0xa95)  spp=0;
    Serial.print(spp);
    irrecv.resume(); 
  }
    ds(spp);
    if(spp==0) indicator();
}
