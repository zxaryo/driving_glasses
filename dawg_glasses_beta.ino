#define t 5
#define q 6
#define w 7
#define e 8
#define r 9
#include<IRremote.h>
//#include<Time.h>
//#include<TimeLib.h>
int  aa=2,a1=2,b=3,i,counter=0,tim,spp=40;
long int ml;
int sped=40,del;
int bc=0;
int mdel;
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
 pinMode(a, OUTPUT);
 pinMode(b, OUTPUT);
 pinMode(q, OUTPUT);
 pinMode(w, OUTPUT);
 pinMode(e, OUTPUT);
 pinMode(r, OUTPUT);
 pinMode(t, OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 Serial.begin(9600);
 irrecv.enableIRIn();
 //setTime(0);
}
void indicator()
{ for(i=0;i<5;i++)
 {
  digitalWrite(a1,1);
  delay(500);
  digitalWrite(a1,0);
  delay(500);
 }
   digitalWrite(b,1);
   delay(500);
}
void ds(int sped)
{   if(sped>0)
    digitalWrite(12,1);
    digitalWrite(13,0);
    int x=sped%10;
    int y=sped/10;
    digitalWrite(t,0);
    dd(x);
    delay(4);
    digitalWrite(t,1);
    dd(y);
    delay(4); 
    digitalWrite(12,0);
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
  digitalWrite(q,a[x][3]);
  digitalWrite(w,a[x][2]);
  digitalWrite(e,a[x][1]);
  digitalWrite(r,a[x][0]);

}
void alert()
{
  
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
