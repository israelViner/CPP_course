CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic 
CXXFLAGS += -Werror -g -std=c++17

main: main.o polynomial.o rationals_array.o rational.o

main.o: main.cpp polynomial.hpp 

polynomial.o: polynomial.cpp polynomial.hpp rationals_array.hpp

rational.o: ../01_rational/rational.cpp ../01_rational/rational.hpp 
	$(CC) $(CXXFLAGS) ../01_rational/rational.cpp ../01_rational/rational.hpp -c rational.o

run: main
	./main
	
clean: 
	$(RM) *.o ./main ../01_rational/.gch
