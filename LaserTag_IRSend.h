#ifndef LaserTag_IRSend_h
#define LaserTag_IRSend_h
 
#include "Arduino.h"

class LTSend
{
  public:
    LTSend(int pin);
    void Command(long code, int codeLength);
    void Shot(String shot);
  private:
    int _pin;
    void sendPulse(int cycles);
};

#endif





