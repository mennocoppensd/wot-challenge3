#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == 1) {
      Serial.println(results.value);
    }
    irrecv.resume(); // Ontvang het volgende waarde
  }
}
