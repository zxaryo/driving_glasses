#include <IRremote.h>

int RECV_PIN = 4;

IRrecv irrecv(RECV_PIN);
long int x;
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    x=results.value;
    Serial.println(x);
    irrecv.resume(); // Receive the next value
  }
}
