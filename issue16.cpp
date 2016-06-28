/**
 *  File: issue16.cpp 

 */

#include "pinGPIO.hpp"
#include "stepMotorPort.hpp"
//#include "stepMotor.hpp"


int main()
{
  
  PinD2 pin(1);
  pin.setPin(true);

  StepMotorPort<PinD2, PinD3, PinD4, PinD5> port;
  port.setPinA(true);
  port.setPinA(false);

  return 0;
}

