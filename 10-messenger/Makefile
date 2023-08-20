CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Werror -std=c++17
CXXFLAGS += -g

main: main.o upper.o lower.o messenger.o encryption.o atbash.o vector_key.o

main.o: main.cpp messenger.hpp transform.hpp upper.hpp lower.hpp encryption.hpp atbash.hpp vector_key.hpp

upper.o : upper.cpp upper.hpp

lower.o : lower.cpp lower.hpp

messenger.o : messenger.cpp messenger.hpp

encryption.o : encryption.cpp encryption.hpp

atbash.o : atbash.cpp atbash.hpp

vector_key.o : vector_key.cpp vector_key.hpp

clean: 
	$(RM) *.o ./main