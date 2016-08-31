/*Atmeaga 328- IC4511 connections 
 * Digital pin 3 - 1
 * Digital pin 4 - 2
 * Digital pin 5 - 7
 * Digital pin 6 - 6
 * Digital pin 2 acts as selector for 7seg 1 & 2 
 * source: https://zxaryo.tk
 */
int q=6,w=7,e=8,r=9,t=5, x=0,y=0;
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
void dis(int y,int x);
void dis(int y,int x)
{
  for(int a=0;a<100;a++)
  {
    digitalWrite(t,0);
    dd(x);
    delay(4);
    digitalWrite(t,1);
    dd(y);
    delay(4);
  }
}
void loop()
{ 
if(Serial.available( ) > 0)
{
delay(1);
x=cmap(Serial.read());
y=cmap(Serial.read());
int z=Serial.read();
z=Serial.read();
delay(1);
}
dis(x,y);
}
