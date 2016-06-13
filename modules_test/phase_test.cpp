/**
    File: phase_test.cpp
    
    Модульный тест класса phase - автомата управления фазами шагового двигателя.
*/

#define BOOST_TEST_MODULE Phase_Test

#include <boost/test/unit_test.hpp>

#include <string>
#include <list>

#include "phase.h"


const std::string boolToString(bool b)
{
  return b ? "t" : "f";
}

/*  INFO: Не получилось сравнить дтва std::tuple "штатными средствами boost".
    Реализовал через "строковое представление". 
*/
std::string PhaseStateToString(PhaseState phase)
{
  std::string rezult = "(";
  rezult += boolToString(std::get<0>(phase));
  rezult += " ";
  rezult += boolToString(std::get<1>(phase));
  rezult += " ";
  rezult += boolToString(std::get<2>(phase));
  rezult += " ";
  rezult += boolToString(std::get<3>(phase));
  rezult += ")";
  return rezult;
}


/*  Test wave driver mode.
*/

BOOST_AUTO_TEST_SUITE(phase)

struct TestObject_WDM
{ 
  TestObject_WDM(): phase(Phase::WAVE_DRIVER_MODE)
  {}
  
  Phase phase;
};


BOOST_FIXTURE_TEST_CASE(left_WDM, TestObject_WDM)
{	
  std::list<std::string> fixture;
  
  fixture.push_back("(t f f f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f f f t)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f f f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f f f t)");  
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.left()));
  }
}


BOOST_FIXTURE_TEST_CASE(right_WDM, TestObject_WDM)
{	
  std::list<std::string> fixture;
  
  fixture.push_back("(t f f f)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f f t f)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f f f)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f f t f)");
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.right()));
  }
}

/*  Test full step mode.  
*/

struct TestObject_FSM
{ 
  TestObject_FSM(): phase(Phase::FULL_STEP_MODE)
  {}
  
  Phase phase;
};


BOOST_FIXTURE_TEST_CASE(left_FSM, TestObject_FSM)
{	
  std::list<std::string> fixture;
  
  fixture.push_back("(t f t f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(t f f t)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f t f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(t f f t)");
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.left()));
  }
}

BOOST_FIXTURE_TEST_CASE(right_FSM, TestObject_FSM)
{	
  std::list<std::string> fixture;
   
  fixture.push_back("(t f t f)");
  fixture.push_back("(t f f t)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f t t f)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f t f)");
  fixture.push_back("(t f f t)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f t t f)");
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.right()));
  }
}


/*  Testet half step mode. 
*/

struct TestObject_HSM
{ 
  TestObject_HSM(): phase(Phase::HALF_STEP_MODE)
  {}
  
  Phase phase;
};


BOOST_FIXTURE_TEST_CASE(left_HSM, TestObject_HSM)
{	
  std::list<std::string> fixture;
  
  fixture.push_back("(t f f f)");
  fixture.push_back("(t f t f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(t f f t)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f f f)");
  fixture.push_back("(t f t f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(t f f t)");
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.left()));
  }
}


BOOST_FIXTURE_TEST_CASE(right_HSM, TestObject_HSM)
{	
  std::list<std::string> fixture;
  
  fixture.push_back("(t f f f)");
  fixture.push_back("(t f f t)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(t f t f)");
  // "второй оборот" комбинаций.
  fixture.push_back("(t f f f)");
  fixture.push_back("(t f f t)");
  fixture.push_back("(f f f t)");
  fixture.push_back("(f t f t)");
  fixture.push_back("(f t f f)");
  fixture.push_back("(f t t f)");
  fixture.push_back("(f f t f)");
  fixture.push_back("(t f t f)");
	
	for (auto expect : fixture)
	{
	  BOOST_CHECK_EQUAL(expect, PhaseStateToString(phase.right()));
  }
}

BOOST_AUTO_TEST_SUITE_END() 

