void StartFona() {
  pinMode(6, INPUT);
  fonaSS.begin(4800);
  if (! fona.begin(fonaSS)) {        
    Serial.println(F("Couldn't find FONA"));
  }
  else {
    Serial.println(F("FONA is OK"));}
  fona.enableGPS(true);

}

void SendSms() {
    if (digitalRead(6) == HIGH) {
      if (!fona.sendSMS("599038320", "hi" ) ){
        Serial.println(F("Failed"));
      } else {
        Serial.println(F("Sent!"));
      }
     }
     
}
 
 
