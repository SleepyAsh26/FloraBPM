#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"

#define FONA_RX 1
#define FONA_TX 9
#define FONA_RST 0

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);


int callBtn = 6;


void setup() {
  pinMode(6, INPUT);
  Serial.begin(115200);
  fonaSS.begin(4800);
  if (! fona.begin(fonaSS)) {        
    Serial.println(F("Couldn't find FONA"));
    while (1);
  }
  Serial.println(F("FONA is OK"));
}

void loop() {
 if (callBtn=HIGH) {
    if (digitalRead(6) == HIGH) {
       if (!fona.sendSMS("599038320", "Hello")) {
        Serial.println(F("Failed"));
      } else {
        Serial.println(F("Sent!"));
      }
    }
  }

 
  }

