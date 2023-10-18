#include <Arduino.h>
#include "TinyIRSender.hpp"

#define IR_SEND_PIN         3
#define MICROSWITCH_PIN     8 // Pin waarop de microswitch is aangesloten

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(MICROSWITCH_PIN, INPUT); // Zet de pin van de microswitch als invoer
    Serial.begin(9600);
    Serial.print(F("Waiting for microswitch press to send IR signal..."));
}

void loop() {
    // Controleer of de microswitch is ingedrukt
    if (digitalRead(MICROSWITCH_PIN) == HIGH) {
        Serial.println("Shoot!");
        // Verstuur het NEC IR-signaal
        sendNEC(IR_SEND_PIN, 0x02, 0x34, 0);
        
    } else {
      digitalRead(MICROSWITCH_PIN);
      Serial.println(digitalRead(MICROSWITCH_PIN));
    }

}
