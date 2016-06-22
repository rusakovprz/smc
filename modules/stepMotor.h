/*
  File: stepMotorP.h
  
*/


class StepMotor
{

public:

  StepMotor()  
  {  };
  
  ~StepMotor()  {};

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
   
};

