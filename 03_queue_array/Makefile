CXX = g++
CC = g++

CXXFLAGS = -Wall -pedantic 
CXXFLAGS += -Werror -g -std=c++17

main: main.o 

main.o: main.cpp queue_array.inl queue_array.hpp \
../02_stack_array/stack_array.hpp ../02_stack_array/stack_array.inl

run: main
	./main
	
clean: 
	$(RM) *.o ./main
