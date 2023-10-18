#include <IRremote.h>

const int RECV_PIN = 7;
const int led = 10;
const int buzzer = 4;
IRrecv irrecv(RECV_PIN);
decode_results results;

unsigned long lastSignalTime = 0;
const unsigned long signalTimeout1 = 3000;  // Tijdsperiode in milliseconden (hier 3 seconden)
const unsigned long signalTimeout2 = 3000;  // Tijdsperiode in milliseconden (hier 2 seconden)

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  bool secondSignalReceived = false;
  bool thirdSignalReceived = false;

  if (irrecv.decode(&results)) {
    // IR-signaal ontvangen
    Serial.println("IR-signaal ontvangen!");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(led, LOW);
    irrecv.resume();  // Ontvang het volgende IR-signaal
    lastSignalTime = currentTime;

    // Wacht tot het tweede signaal binnen de tijdslimiet wordt ontvangen
    while (currentTime - lastSignalTime <= signalTimeout1) {
      if (irrecv.decode(&results)) {
        // Tweede signaal ontvangen binnen de tijdslimiet
        Serial.println("Tweede signaal ontvangen!");
        secondSignalReceived = true;
        digitalWrite(led, HIGH);
        digitalWrite(buzzer, HIGH);
        delay(500);
        digitalWrite(buzzer, LOW);
        digitalWrite(led, LOW);
        irrecv.resume();  // Ontvang het volgende IR-signaal
        lastSignalTime = currentTime;  // Update de tijd voor het derde signaal

        // Wacht tot het derde signaal binnen de tijdslimiet wordt ontvangen
        while (currentTime - lastSignalTime <= signalTimeout2) {
          if (irrecv.decode(&results)) {
            // Derde signaal ontvangen binnen de tijdslimiet
            Serial.println("Derde signaal ontvangen!");
            thirdSignalReceived = true;
            break;
          }
          currentTime = millis();
        }
        break;
      }
      currentTime = millis();
    }

    if (secondSignalReceived && thirdSignalReceived) {
      // Tweede en derde signaal correct ontvangen
      Serial.println("Camera uitgeschakeld!");
      digitalWrite(led, HIGH);
      while (true) {
        // Hier blijft het programma wachten en zal het niet verder gaan
      }
    } else {
      // Tweede of derde signaal niet op tijd ontvangen
      Serial.println("Tweede of derde signaal niet ontvangen binnen de tijdslimiet!");
      // Doe hier wat je moet doen wanneer het tweede of derde signaal niet op tijd is ontvangen
    }
  }
}
