/*Arduino - IC4511 connections 
 * pin 1 - 7
 * pin 2 - 6
 * pin 6 - 2
 * pin 7 - 1
 * pin 3 acts as selector for 7seg 1 & 2 
 * source: https://zxaryo.tk
 */
 
int q=1,w=7,e=6,r=2,t=3;
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
    dd(x);
    digitalWrite(t,0);
    delay(4);
    dd(y);
    digitalWrite(t,1);
    delay(4);
  }
}
void loop()
{
  int x,y;
 for(int i=0; i<100 ;i++)
  {
   x=i/10;
   y=i%10;
   dis(x,y);
  } 
}
