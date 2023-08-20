# Brainfuck Compiler and Interpreter
This project implements a compiler and interpreter for the Brainfuck programming language. The project contains several files that work together to provide a complete solution for Brainfuck:

main.cpp: This file contains the unit tests for the project.
compiler.hpp / cpp: These files contains the code for compiling a string of Brainfuck code into an array of commands. The commands are represented as an 'OpCode' enumeration.

brainfuck.hpp / cpp: These files contains the code for executing the compiled Brainfuck code. The code is executed one command at a time.

byte_array.hpp /  cpp: These files defines the 'Byte_array' class, which is used to store arrays of int8_t values. The 'Byte_array' class provides the necessary operators to manage the stored array.

bf_memory.hpp / cpp: These files defines the 'Memory' class, which is a wrapper around the 'Byte_array' class that provides a convenient interface for working with the virtual memory. The 'Memory' class uses a sophisticated reallocation of memory to allow the interpreter unlimited memory. This means that the memory will grow dynamically as necessary to accommodate the changing needs of the Brainfuck code being executed. The 'bf_memory' class stores its data in an object of byte_array that is stored as a data member of the class.

code.hpp / cpp: These files defines the 'Code' class, which is used to store the compiled Brainfuck code. The code is stored as an array of int8_t values, which are cast to the OpCode command type. The 'Code' class stores its data in an object of Byte_array that is stored as a data member of the class.

The project uses the C++ programming language and requires a C++ compiler to build. To build and run the project, follow these steps:

1. Clone or download the project to your local machine.
2. Open a terminal and navigate to the directory containing the project.
3. Type make to build the project.
4. Type ./main to run the unit tests.

You can also use the provided code as a starting point for your own Brainfuck projects. If you have any questions or feedback, please feel free to reach out.



