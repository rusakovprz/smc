/**
    File: phase.cpp
    
    Реализация автомата управления фазами шагового двигателя.
    
*/


#include "phase.h"

Phase::Phase(MODE mode): 
            indexPhaseStates_(0)
{
  fabricPhaseStates(mode, phaseStates_ , phaseStatesLen_);
}


Phase::~Phase()
{
}


// Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в лево.
PhaseState Phase::left()
{
  if (indexPhaseStates_ == phaseStatesLen_)
  {
    indexPhaseStates_ = 0; 
  }
  
  return phaseStates_[indexPhaseStates_++]; // TODO: подумать как использовать префиксную форму.
}


// Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в право.
PhaseState Phase::right()
{
  if (indexPhaseStates_ == 0)
  {
    indexPhaseStates_ = phaseStatesLen_-1;
    return phaseStates_[0]; 
  }
  
  return phaseStates_[indexPhaseStates_--];
}


void Phase::fabricPhaseStates(MODE mode, PhaseState *states, uint8_t &len)
{  
  switch (mode)
  {
    case WAVE_DRIVER_MODE: 
      fabricPhaseStatesWaveDriver(states, len);
      return;
    case FULL_STEP_MODE:
      return fabricPhaseStatesFullStep(states, len);
    case HALF_STEP_MODE:
      return fabricPhaseStatesHalfStep(states, len);
    default: 
    {
      states[0] = {false,  false, false, false}; // На обмотки двигателя не будет подаваться напряжение.
      len = 1;
    }
  }
}


void Phase::fabricPhaseStatesWaveDriver(PhaseState *states, uint8_t &len)
{
  states[0] = {true,  false, false, false};
  states[1] = {false, false, true,  false};
  states[2] = {false, true,  false, false};
  states[3] = {false, false, false, true };

  len = 4;
}


void Phase::fabricPhaseStatesFullStep(PhaseState *states, uint8_t &len)
{
  states[0] = {true,   false, true,  false};
  states[1] = {false,  true,  true,  false};
  states[2] = {false,  true,  false, true };
  states[3] = {true,  false, false, true};
  len = 4;
}


void Phase::fabricPhaseStatesHalfStep(PhaseState *states, uint8_t &len)
{
  states[0] = {true,   false, false, false};
  states[1] = {true,   false, true,  false};
  states[2] = {false,  false, true,  false};
  states[3] = {false,  true,  true,  false};
  states[4] = {false,  true,  false, false};
  states[5] = {false,  true,  false, true };
  states[6] = {false,  false, false, true };
  states[7] = {true,   false, false, true };
  len = 8;
}

