
CXX           = g++
CXXFLAGS      = -pipe -O2 -Wall -W -std=c++11
INCPATH       = -I. -I./modules/
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = -lboost_unit_test_framework
DEL_FILE      = rm -f

SOURCES       = modules/phase.cpp \
                modules_test/phase_test.cpp \
                modules_test/test.cpp 
OBJECTS       = phase.o phase_test.o test.o 
TARGET        = unit_tests

all: $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

phase.o: modules/phase.cpp modules/phase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o phase.o modules/phase.cpp

phase_test.o: modules_test/phase_test.cpp modules/phase.cpp modules/phase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o phase_test.o modules_test/phase_test.cpp

test.o: modules_test/test.cpp modules/phase.cpp modules/phase.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o test.o modules_test/test.cpp


runtest: $(TARGET)
	./$(TARGET)
    

clean:
	-$(DEL_FILE) *.o

distclean: clean 
	-$(DEL_FILE) $(TARGET) 

cleanall: clean distclean
	
