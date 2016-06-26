/*
  File: stepMotorP.hpp
  
*/

#include "phase.h"

template<typename T>
class StepMotor
{

public:

  enum MODE
  {
    STOP = 0,
    LEFT,
    RIGHT
  };


  StepMotor(): 
        port_(),
        mode_(STOP),
        phase_(phase::WAVE_DRIVER_MODE)
  {  };
  
  ~StepMotor()  {};

  /**
   * @brief Установливает режим двигателя.
   * 
   * @param mode - режим.
   */
  void setMode(MODE mode) { mode_ = mode; };

  /**
   * @brief Устанавливает скорость вращения ротора двигателя.
   * 
   * @param speed - скорость вращения ротора двигателя [об/мин].
   */
  void setSpeed(unsigned int speed)
  {
    if (speed == 0 || speed > 128)
    {
      return;
    };

    // Полагаем, что таймвут таймера-счетчика 1 мс.
    passIntruptsTC_ = timeout_for_one_step(speed, 200);
  };

  /**
   * @brief Выполнение действия.
   * @details Предполагается, что этот метод будет вызываться обработчиком прерывания таймера-счетчика
   * например для очередного поворота двигателя на один шаг.
   */
  void action()
  {
    if(mode_ == STOP)
    {
      return;
    }

    if( --counterPassIntruptsTC_ == 0)
    {
      counterPassIntruptsTC_ = passIntruptsTC_;
    }
      else
      {
        return; 
      }  

    PhaseState state;

    if(mode_ == LEFT)
    {
      state = phase_.left();      
    }

    if(mode_ == RIGHT)
    {
      state = phase_.right();      
    }

    port_.setPinA(std::get<0>(state));
    port_.setPinB(std::get<1>(state));
    port_.setPinC(std::get<2>(state));
    port_.setPinD(std::get<3>(state));

  };


  /*  Вычисляет тайм-аут одного шага двигателя.
      @arg S - скорость вращения двигателя двигателя.
      @arg N - число шагов полного оборота двигателя.
      @return - таймаут одного шага.
  */
  static uint16_t timeout_for_one_step(uint16_t S, uint16_t N)  { return 60000/(S*N); };
  
  /*  Вычисляет количество шагов полного оборота двигателя для известного 
      значения угла поворота на один шаг.
      @arg l - угол поворота на один шаг.
      @return - количество шагов полного оборота.
  */
  static uint16_t matchSteps(float l)  { return 360/l; };
  
  /*  Вычисляет значение перепонения 8-и битного таймера-счетчика, для отсчета
      времени t, для тактовой частоты МК=16 МГц и коэффициента деления=8.
      
      _8_16_8 - в названии кодирует значения:
        8 - ибитный таймерсчетчик;
        16 - тактовая частота МК [МГц];
        8 - коэффициен деления таймера-счетчика. 
      
      @arg t - время в диапазоне значений 1-128 [мс].
      @return - значение перепонения 8-и битного таймера-счетчика.
  */
  static uint8_t getOverflow_8_16_8(int t)  { return (t-0.5)*2; };

private:

  T port_;
  MODE mode_;
  Phase phase_;

  int passIntruptsTC_; // Число  пропусков прерваний ТС.
  int counterPassIntruptsTC_; // Счетчик числа  пропусков прерваний ТС.
};

