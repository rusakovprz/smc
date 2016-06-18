/*
  File: pinGPIO.hpp
  
  Контакт general-purpose input/output (GPIO)
  
*/


template<int PORT, int DDR, int PIN, int BIT>
class PinGPIO
{

public:

  /*  Конструктор.
      @arg inOut - направление вывода (вход/выход).
        0 - вход.
        1 -выход.
  */
  PinGPIO(bool inOut);
  
  ~PinGPIO();

  /*  Устанавливает состояние пина.
      @arg level - уровень состояния выхода (включено/выключено).
  */
  void setPin(bool level);

  /*  Читает состояние пина.
      @return - уровень состояния входа (включено/выключено).
  */
  bool getPin();

private:
  
  /*  Инициализирует пин порта ввода вывода МК.
      @arg inOut - направление вывода (вход/выход).
        0 - вход.
        1 -выход.
      @return значение отличное от 0 - код ошибки.   
  */
  int initPin(bool inOut);  

};


template<int PORT, int DDR, int PIN, int BIT>
PinGPIO<PORT, DDR, PIN, BIT>::PinGPIO(bool inOut)
{
    initPin(inOut);
};


template<int PORT, int DDR, int PIN, int BIT>
PinGPIO<PORT, DDR, PIN, BIT>::~PinGPIO()
{

};


template<int PORT, int DDR, int PIN, int BIT>
int PinGPIO<PORT, DDR, PIN, BIT>::initPin(bool inOut)
{
  // TODO: режим высокого входного сопротивления при рабте порта на вход.

  uint8_t* ptR;
  ptR = (uint8_t*) DDR; 
  
  if (inOut)
  {
    *ptR |= (1 << BIT);
  } 
  else
  {
     *ptR &= ~ (1 << BIT);
  }
  
  return 0;  
};


template<int PORT, int DDR, int PIN, int BIT>
void PinGPIO<PORT, DDR, PIN, BIT>::setPin(bool level)
{
  // TODO: ptR сделать членом класса.
  //       Инициализировать переменную в конструкторе объекта.
  uint8_t* ptR;
  ptR = (uint8_t*) PORT;
   
  if (level)
  {
    *ptR |= (1 << BIT);
  } 
  else
  {
     *ptR &= ~ (1 << BIT);
  }

};


template<int PORT, int DDR, int PIN, int BIT>
bool PinGPIO<PORT, DDR, PIN, BIT>::getPin()
{
  uint8_t* ptR;
  ptR = (uint8_t*) PIN;
  
  return  *ptR & (1 << BIT);
};


typedef PinGPIO<0x2B, 0x2A, 0x29, 2> PinD2;
typedef PinGPIO<0x2B, 0x2A, 0x29, 3> PinD3;
typedef PinGPIO<0x2B, 0x2A, 0x29, 4> PinD4;
typedef PinGPIO<0x2B, 0x2A, 0x29, 5> PinD5;
typedef PinGPIO<0x2B, 0x2A, 0x29, 6> PinD6;
typedef PinGPIO<0x2B, 0x2A, 0x29, 7> PinD7;


