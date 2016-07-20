/**
    File: phase.h
    
    Реализация автомата управления фазами шагового двигателя.
    
*/

#ifndef SMC_PHASE_
#define SMC_PHASE_

#include <stdint.h>


struct PhaseState
{
  bool A;
  bool B;
  bool C;
  bool D;
};


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
  // FIXME: Проверить возможность динамического выделения памяти и переписать. 
  PhaseState phaseStates_[8];
  uint8_t phaseStatesLen_;

  uint8_t indexPhaseStates_;

  // Методы возвращают список фаз обмоток двигателя, для каждого "поддерживаемого"
  // способа управления.   
  void fabricPhaseStates(MODE mode, PhaseState *state, uint8_t &len);
  void fabricPhaseStatesWaveDriver(PhaseState *states, uint8_t &len);
  void fabricPhaseStatesFullStep(PhaseState *states, uint8_t &len);
  void fabricPhaseStatesHalfStep(PhaseState *states, uint8_t &len);
  
};

#endif //SMC_PHASE_

