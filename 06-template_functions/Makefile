CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Werror -g -std=c++17

main: main.o 

main.o: main.cpp template_functions.inl template_functions.hpp

clean: 
	$(RM) *.o ./main