/**
    File: stepMotorPort_test.cpp
    
    Модульный тест класса StepMotorPort.
*/


#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE SterMotorPort_Test

#include <string>
#include <list>

#include "stepMotorPort.hpp"
#include "pinGPIO.hpp"

BOOST_AUTO_TEST_SUITE(stepMotorPort)

struct TestObject_StepMotorPort
{ 

  TestObject_StepMotorPort()
  {
    
  }
    
  StepMotorPort<PinD2, PinD3, PinD4, PinD5> motor;

};


BOOST_FIXTURE_TEST_CASE(setPin, TestObject_StepMotorPort)
{	
	motor.setPinA(true);
}



BOOST_AUTO_TEST_SUITE_END() 

