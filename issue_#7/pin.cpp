/*

  Исследование - какой код генерит компилятор
  
  gcc -S -O1 -std=c++11 -I../ -o pin.s pin.cpp

*/

#include <stdint.h>
#include "modules/pinGPIO.hpp"


void function()
{

  PinGPIO<0x2B, 0x2A, 0x29, 2> pingpio(1);
  pingpio.setPin(true);

};

