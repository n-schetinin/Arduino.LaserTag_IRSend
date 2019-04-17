#include <LaserTag_IRSend.h>

//If you use only this library, you can use any digital pin
//If you use it with IRRemote library in one sketch,
//dont use 3 and 11 pins (UNO).
//Besides you need write "enableIRIn()" after any pulse send
//to reenable IR Receive in IRRemote library

LTSend LT(12); // Init IR send on pin 12


void setup() {}

void loop() {
  //New Game pulse. 
  //First param is a value, second - length in bits
  LT.Command(0x8302E8, 24); 
  delay(2000);
  //Shot pulse. 
  //Param is string with binary coded shot due to Miles protocol. 
  //13 simbols without starting zero.
  //In this example: ID - 127, team - red, damage - 25
  LT.Shot("1000000001001"); 
  delay(2000);
}