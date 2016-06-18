/*
  File: stepMotorPort.hpp
  
*/

template<typename TA, typename TB, typename TC, typename TD>
class StepMotorPort
{

public:

  enum PORT
  {
    PORT0 = 0,
    PORT1 = 1,
    PORT2 = 2  
  };

  StepMotorPort():
                pinA_(1), 
                pinB_(1),
                pinC_(1),
                pinD_(1)  
  {
    initPort();
  };
  
  ~StepMotorPort()  {};

  /*  Устанавливают состояния драйвера соответсвующей обмотки двигателя.
      @arg level - уровень фазы двигателя (включено/выключено).
  */
  void setPinA(bool level)  { pinA_.setPin(level); };
  void setPinB(bool level)  { pinB_.setPin(level); };
  void setPinC(bool level)  { pinC_.setPin(level); };
  void setPinD(bool level)  { pinD_.setPin(level); };

private:
  
  /*  Инициализирует порты ввода вывода МК к которым подключен драйвер двигателя.
      @arg port - порт, обединяющий 4 пина МК которыми управляется двигатель.
      @return значение отличное от 0 - код ошибки.   
  */
  int initPort()  { return 0; };
  
  TA pinA_;
  TB pinB_;
  TC pinC_;
  TD pinD_;  

};

