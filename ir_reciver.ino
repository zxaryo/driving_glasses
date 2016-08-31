#include <IRremote.h>

int RECV_PIN = 4; // IMPORTANT

IRrecv irrecv(RECV_PIN);
long int x;
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    x=results.value;
    Serial.println(x);
    irrecv.resume();
  }
}
