/**
    File: stepMotor_test.cpp
    
    Модульный тест класса StepMotor.
*/


#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE SterMotorPort_Test

#include <string>
#include <list>

#include "stepMotor.h"

BOOST_AUTO_TEST_SUITE(stepMotor)

BOOST_AUTO_TEST_CASE (object_matchSteps_1_8)
{
  StepMotor motor;
  BOOST_CHECK(motor.matchSteps(1.8) == 200);
}
    
BOOST_AUTO_TEST_CASE (class_matchSteps_1_8)
{
  BOOST_CHECK(StepMotor::matchSteps(1.8) == 200);
}


BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_1_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(1, 200) == 300);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_2_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(2, 200) == 150);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_4_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(4, 200) == 75);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_5_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(5, 200) == 60);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_10_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(10, 200) == 30);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_20_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(20, 200) == 15);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_50_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(50, 200) == 6);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_100_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(100, 200) == 3);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_150_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(150, 200) == 2);
}

BOOST_AUTO_TEST_CASE (class_timeout_for_one_step_300_200)
{
  BOOST_CHECK(StepMotor::timeout_for_one_step(300, 200) == 1);
}


BOOST_AUTO_TEST_SUITE_END() 

