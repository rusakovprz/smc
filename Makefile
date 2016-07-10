
CXX_AVR       = avr-g++ -mmcu=atmega328p
CXX           = g++
CXXFLAGS      = -pipe -O2 -Wall -W -std=c++11
INCPATH       = -I. -I./modules/
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = -lboost_unit_test_framework
DEL_FILE      = rm -f

OBJECTS       = phase.o phase_test.o test.o stepMotor_test.o
TARGET        = unit_tests


all: $(TARGET) test_avr_gcc

$(TARGET):  $(OBJECTS)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)


%.o: modules/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

%.o: modules_test/%.cpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<


phase.o: modules/phase.cpp modules/phase.h

phase_test.o: modules_test/phase_test.cpp modules/phase.cpp modules/phase.h

pinGPIO_test.o: modules_test/pinGPIO_test.cpp modules/pinGPIO.hpp

stepMotorPort_test.o: modules_test/stepMotorPort_test.cpp modules/stepMotorPort.hpp

stepMotor_test.o: modules_test/stepMotor_test.cpp modules/stepMotor.hpp

test.o: modules_test/test.cpp modules/phase.cpp modules/phase.h


test_avr_gcc: phase.o \
				modules/pinGPIO.hpp \
				modules/stepMotor.hpp \
				modules/stepMotorPort.hpp \
				issue16.cpp
	$(CXX_AVR) -c $(CXXFLAGS) $(INCPATH) -o issue16.o issue16.cpp


runtest: $(TARGET)
	./$(TARGET)
    

clean:
	-$(DEL_FILE) *.o

distclean: clean 
	-$(DEL_FILE) $(TARGET) 

cleanall: clean distclean
	
