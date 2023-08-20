CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Werror -std=c++17
#CXXFLAGS += -g3

CPPFLAGS = -I ./sound
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main: main.o $(LIBS)

main.o: main.cpp 

clean: 
	$(RM) *.o ./main */*.o