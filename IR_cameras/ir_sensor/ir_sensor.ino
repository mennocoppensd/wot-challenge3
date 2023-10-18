#include <IRremote.h>

const int RECV_PIN = 7;
const int led = 10;
const int buzzer = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
      Serial.println(results.value);
      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(300);
      digitalWrite(buzzer, LOW);
      digitalWrite(led, LOW);
      irrecv.resume();
  }
}
