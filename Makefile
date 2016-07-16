
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


include Makefile.dependencies

test_avr_gcc:
	$(CXX_AVR) -c $(CXXFLAGS) $(INCPATH) -o issue16.o issue16.cpp


runtest: $(TARGET)
	./$(TARGET)
    

clean:
	-$(DEL_FILE) *.o

distclean: clean 
	-$(DEL_FILE) $(TARGET) 

cleanall: clean distclean
	
