/*
  File: stepMotorPort.h
  
*/


class StepMotorPort
{

public:

  enum PORT
  {
    PORT0 = 0,
    PORT1 = 1,
    PORT2 = 2  
  }

  StepMotorPort(PORT port)
  {
    initPort(port);
  };
  
  ~StepMotorPort()  {};

  /*  Устанавливают состояния драйвера соответсвующей обмотки двигателя.
      @arg level - уровень фазы двигателя (включено/выключено).
  */
  void setPinA(bool level)  {};
  void setPinB(bool level)  {};
  void setPinC(bool level)  {};
  void setPinD(bool level)  {};

private:
  
  /*  Инициализирует порты ввода вывода МК к которым подключен драйвер двигателя.
      @arg port - порт, обединяющий 4 пина МК которыми управляется двигатель.
      @return значение отличное от 0 - код ошибки.   
  */
  int initPort(PORT port)  {};  

};

