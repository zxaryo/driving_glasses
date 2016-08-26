/* Atmega 328 - Display module connections 
 * Digital pin 6 - 1 A
 * Digital pin 7 - 2 B
 * Digital pin 8 - 3 C
 * Digital pin 9 - 4 D
 * Digital pin 5 acts as selector for 7seg 1 & 2 
 * Motors connected to Digital Pin 12,13
 * Bluetooth module(or any other serial device) connected to Rx and Tx
 * source: https://zxaryo.tk
 */
int  q=6,w=7,e=8,r=9,t=5,x=0,y=0,aa=2,b=3,i,sped=0;
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
void setup() 
{
 pinMode(q, OUTPUT);
 pinMode(w, OUTPUT);
 pinMode(e, OUTPUT);
 pinMode(r, OUTPUT);
 pinMode(t, OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 Serial.begin(9600);
}
int cmap(char zx);
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
void dd(int x);
void dd(int x)
{
  digitalWrite(q,a[x][3]);
  digitalWrite(w,a[x][2]);
  digitalWrite(e,a[x][1]);
  digitalWrite(r,a[x][0]);

}
void ds(int y,int x);
void ds(int y,int x)
{
    digitalWrite(12,1);
    digitalWrite(13,0);
    sped=x*10+y;
   
    digitalWrite(t,0);
    dd(x);
    delay(4);
    digitalWrite(t,1);
    dd(y);
    delay(4);
 
    digitalWrite(12,0);
    delay(sped/5);
}
void loop()
{
    if(Serial.available()>0)
    {
      delay(1);
      x=cmap(Serial.read());
      y=cmap(Serial.read());
      int z=Serial.read();
          z=Serial.read();
      delay(1);
    }
    ds(x,y);
}

