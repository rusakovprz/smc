/**
 *  File: issue16.cpp 

 */

#include "pinGPIO.hpp"
#include "stepMotorPort.hpp"
#include "stepMotor.hpp"


typedef StepMotorPort<PinD2, PinD3, PinD4, PinD5> MotorPort;

int main()
{
  
  PinD2 pin(1);
  pin.setPin(true);

  MotorPort port;
  port.setPinA(true);
  port.setPinA(false);

  StepMotor<MotorPort> motor;
  motor.action();

  return 0;
}

