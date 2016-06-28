/*
  File: stepMotorP.hpp
  
*/

#include <stdlib.h>
#include "phase.h"

template<typename T>
class StepMotor
{

public:

  enum MODE
  {
    STOP = 0,
    LEFT,
    RIGHT,
    ANGLE
  };


  StepMotor(): 
        port_(),
        mode_(STOP),
        phase_(Phase::WAVE_DRIVER_MODE) // TODO: Добавить другие режимы.
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

    // Полагаем, что таймаут таймера-счетчика = 1 мс.
    passIntruptsTC_ = timeout_for_one_step(speed, 200);
  };


  void setAngle(long angle)
  {
    // FIXME: angle_ и angle разные типы.
    //        Проверить их размерность на целевой платформе.  
    angle_ = angle;    
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

    if(mode_ == ANGLE)
    {
      // FIXME: Смотри инициализацию phase_ в конструкторе. 
      // Используется только один режим.

      float angle_one_step = 1.8;

      // Устраняем ошибку округления.
      if(abs(angle_) < angle_one_step)
      {
        mode_ = STOP;
      }
      
      if(angle_ > 0)
      {
        state = phase_.left();
        angle_ -= angle_one_step;       
      }
      else
      {
        state = phase_.left();
        angle_ += angle_one_step;
      }
    }


    port_.setPinA(state.A);
    port_.setPinB(state.B);
    port_.setPinC(state.C);
    port_.setPinD(state.D);

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

  float angle_;
};

