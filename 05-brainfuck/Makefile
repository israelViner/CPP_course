CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic 
CXXFLAGS += -Werror -g -std=c++17

main: main.o brainfuck.o bf_memory.o code.o compiler.o byte_array.o

main.o: main.cpp brainfuck.hpp 

brainfuck.o: brainfuck.cpp brainfuck.hpp

code.o: code.cpp code.hpp 

compiler.o: compiler.hpp compiler.cpp

bf_memory.o: bf_memory.cpp bf_memory.hpp 

byte_array.o: byte_array.cpp byte_array.hpp

run: main
	./main
	
clean: 
	$(RM) *.o ./main ../01_rational/*.gch
