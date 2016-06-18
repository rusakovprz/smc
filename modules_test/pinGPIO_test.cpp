/**
    File: pinGPIO_test.cpp
    
    Модульный тест класса PinGPIO.
*/


#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE PinGPIO_Test

#include <string>
#include <list>

#include "pinGPIO.hpp"


BOOST_AUTO_TEST_SUITE(pin)

struct TestObject_PinGPIO
{ 

  // INFO: Запускать выполнение теста на "инструментаотной" платформе нельхя.
  // Выполнение теста вызовет ошибку (прямой доступ к памяти). 
  TestObject_PinGPIO(): pin(1)
  {
    
  }
  
  PinGPIO<0x2B, 0x2A, 0x29, 0> pin;

};


BOOST_FIXTURE_TEST_CASE(create_object, TestObject_PinGPIO)
{	
	
}



BOOST_AUTO_TEST_SUITE_END() 

