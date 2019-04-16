#include "Arduino.h"
#include "LaserTag_IRSend.h"

#define IR_PIN  9
#define CARRIER_INTERVAL 6   
#define MLT_SPACE_INTERVAL 600
#define MLT_HEADER_CYCLES 128   
#define MLT_BIT0_CYCLES 32    
#define MLT_BIT1_CYCLES 64    


void LTSend::sendPulse(int cycles) {
  for (int i = 0; i < cycles; i++ ) {
    digitalWrite(_pin, HIGH);
    delayMicroseconds(CARRIER_INTERVAL);
    digitalWrite(_pin, LOW);
    delayMicroseconds(CARRIER_INTERVAL);
  }
  delayMicroseconds(MLT_SPACE_INTERVAL);
}

LTSend::LTSend(int pin)
{
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void LTSend::Command(long code, int codeLength){
  char packet[80];
  String packetStr;
  int i;

  ltoa(code, packet, 2);
  packetStr = packet;

  TIMSK2 = 0;

  sendPulse(MLT_HEADER_CYCLES);
  
  for (i = 0; i < codeLength; i++) {
    if (packetStr[i] == '1') {
      sendPulse(MLT_BIT1_CYCLES);
    } else {
      sendPulse(MLT_BIT0_CYCLES);
    }
  }
}

void LTSend::Shot(String shot){
  int i;

  TIMSK2 = 0;

  sendPulse(MLT_HEADER_CYCLES);
  sendPulse(MLT_BIT0_CYCLES);
  for (i = 0; i < 13; i++) {
    if (shot[i] == '1') {
      sendPulse(MLT_BIT1_CYCLES);
    } else {
      sendPulse(MLT_BIT0_CYCLES);
    }
  }

}
