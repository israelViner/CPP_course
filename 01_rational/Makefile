

CXX = g++
CC = g++

CFLAGS = -Wall -pedantic -Werror -g

main: main.o rational.o
	$(CC) $(CFLAGS) main.o rational.o -o main

main.o: main.cpp rational.cpp rational.hpp
	$(CC) $(CFLAGS) main.cpp -c

rational.o: rational.cpp rational.hpp
	$(CC) $(CFLAGS) rational.cpp -c


run: main
	./main
	
clean: 
	$(RM) *.o ./main
