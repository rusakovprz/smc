/**
    File: phase.cpp
    
    Реализация автомата управления фазами шагового двигателя.
    
*/


#include "phase.h"

Phase::Phase(MODE mode)
{
  phaseStates_ = fabricPhaseStates(mode);
  iteratorPhaseStates_ = phaseStates_.begin();
}


Phase::~Phase()
{
}


// Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в лево.
PhaseState Phase::left()
{
  if (iteratorPhaseStates_ == phaseStates_.end())
  {
    iteratorPhaseStates_ = phaseStates_.begin(); 
  }
  
  return *iteratorPhaseStates_++;
}


// Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в право.
PhaseState Phase::right()
{
  if (iteratorPhaseStates_ == phaseStates_.begin())
  {
    iteratorPhaseStates_ = phaseStates_.end()-1;
    return *phaseStates_.begin(); 
  }
  
  return *iteratorPhaseStates_--;
}


std::vector<PhaseState> Phase::fabricPhaseStates(MODE mode)
{  
  switch (mode)
  {
    case WAVE_DRIVER_MODE: 
      return fabricPhaseStatesWaveDriver();
    case FULL_STEP_MODE:
      return fabricPhaseStatesFullStep();
    case HALF_STEP_MODE:
      return fabricPhaseStatesHalfStep();
    default: 
    {
      std::vector<PhaseState> sts;
      sts.push_back(std::make_tuple(false,  false, false, false)); // На обмотки двигателя не будет подаваться напряжение.
      return sts;  
    }
  }
}


std::vector<PhaseState> Phase::fabricPhaseStatesWaveDriver()
{
  std::vector<PhaseState> sts;

  sts.push_back(std::make_tuple(true,  false, false, false));
  sts.push_back(std::make_tuple(false, false, true,  false));
  sts.push_back(std::make_tuple(false, true,  false, false));
  sts.push_back(std::make_tuple(false, false, false, true ));

  return sts; 
}


std::vector<PhaseState> Phase::fabricPhaseStatesFullStep()
{ 
  std::vector<PhaseState> sts;
  sts.push_back(std::make_tuple(true,   false, true,  false));
  sts.push_back(std::make_tuple(false,  true,  true,  false));
  sts.push_back(std::make_tuple(false,  true,  false, true ));
  sts.push_back(std::make_tuple(true,  false, false, true));
  return sts;
}


std::vector<PhaseState> Phase::fabricPhaseStatesHalfStep()
{
  std::vector<PhaseState> sts;
  sts.push_back(std::make_tuple(true,   false, false, false));
  sts.push_back(std::make_tuple(true,   false, true,  false));
  sts.push_back(std::make_tuple(false,  false, true,  false));
  sts.push_back(std::make_tuple(false,  true,  true,  false));
  sts.push_back(std::make_tuple(false,  true,  false, false));
  sts.push_back(std::make_tuple(false,  true,  false, true ));
  sts.push_back(std::make_tuple(false,  false, false, true ));
  sts.push_back(std::make_tuple(true,   false, false, true ));
  return sts;
}

