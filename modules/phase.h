/**
    File: phase.h
    
    Реализация автомата управления фазами шагового двигателя.
    
*/

#ifndef SMC_PHASE_
#define SMC_PHASE_

#include <tuple>
#include <vector>


typedef std::tuple<bool, bool, bool,bool> PhaseState;

class Phase
{

public:

  /*
    Способы управления фазами шагового двигателя.

      ”one phase on” full step или wave drive mode
      ”two-phase-on” full step или просто full step mode
      ”one and two-phase-on” half step или просто half step mode
  */
  enum MODE
  {
    WAVE_DRIVER_MODE,
    FULL_STEP_MODE,
    HALF_STEP_MODE
  };

  Phase(MODE mode = WAVE_DRIVER_MODE);
  ~Phase();

  // Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в лево.
  PhaseState left();

  // Возвращает "следующее" состояние фаз двигателя, необходимое для поворота в право.
  PhaseState right();


private:

  // Фазы обмоток двигателя, для выбранного способа управления. 
  std::vector<PhaseState> phaseStates_;
  
  std::vector<PhaseState>::iterator iteratorPhaseStates_;

  // Методы возвращают список фаз обмоток двигателя, для каждого "поддерживаемого"
  // способа управления.   
  static std::vector<PhaseState> fabricPhaseStates(MODE mode);
  static std::vector<PhaseState> fabricPhaseStatesWaveDriver();
  static std::vector<PhaseState> fabricPhaseStatesFullStep();
  static std::vector<PhaseState> fabricPhaseStatesHalfStep();
  
};

#endif //SMC_PHASE_

