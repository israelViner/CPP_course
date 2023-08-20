CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Werror -std=c++17
CXXFLAGS += -g

main: main.o virtual_machine.o result.o firmware.o

main.o: main.cpp virtual_machine.hpp opCodes.hpp result.hpp result.cpp firmware.hpp firmware.cpp

clean: 
	$(RM) *.o ./main
