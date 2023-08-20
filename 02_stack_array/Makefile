CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic -Werror -g -std=c++17

main: main.o 

main.o: main.cpp stack_array.inl stack_array.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main