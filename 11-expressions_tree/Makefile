CXX = g++
CC = $(CXX)

CXXFLAGS = -Wall -pedantic -Werror -std=c++17
CXXFLAGS += -g3

CPPFLAGS = -I ./token -I ./lexer -I ./expression -I ./tools -I ./rpn

main: main.o expressions_tree.o rpn/rpn.o lexer/lexer.o token/derive_token.o \
expression/binary_operator_node.o expression/unary_operator.o

main.o: main.cpp expressions_tree.hpp rpn/rpn.hpp \
lexer/lexer.hpp expression/operand.hpp expression/binary_operator_node.hpp \
tools/tree.hpp expression/expression.hpp token/token.hpp token/derive_token.hpp \
tools/groups_enum.hpp tools/Stack.hpp expression/unary_operator.hpp

expressions_tree.o : expressions_tree.cpp expressions_tree.hpp

rpn/rpn.o : rpn/rpn.cpp rpn/rpn.hpp

lexer/lexer.o : lexer/lexer.cpp lexer/lexer.hpp

token/derive_token.o : token/derive_token.cpp token/derive_token.hpp

expression/binary_operator_node.o : expression/binary_operator_node.cpp expression/binary_operator_node.hpp

expression/unary_operator.o :expression/unary_operator.cpp expression/unary_operator.hpp

clean: 
	$(RM) *.o ./main */*.o