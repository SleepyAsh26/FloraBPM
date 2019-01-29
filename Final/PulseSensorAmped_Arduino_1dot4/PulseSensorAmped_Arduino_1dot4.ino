#include <SoftwareSerial.h>
#include "Adafruit_FONA.h"

#define FONA_RX 1
#define FONA_TX 9
#define FONA_RST 0

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

//  Variables
int pulsePin = 10;                 // Pulse Sensor purple wire connected to analog pin 0
int callBtn = 6;                   //Button for testing fona

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.


void setup(){
Serial.begin(115200);             
  StartFona();                
  TCCR1A = 0x00;
  TCCR1B = 0x0C; // prescaler = 256
  OCR1A = 0x7C;  // count to 124  
  TIMSK1 = 0x02; 
  sei();
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
  //analogReference(EXTERNAL);   
}

void loop(){ 
   SendSms(); 
  if (QS == true){     // A Heartbeat Was Found            
        QS = false;    // reset the Quantified Self flag for next time    
  }
}








