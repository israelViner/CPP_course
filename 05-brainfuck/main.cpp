#include <iostream>

#include "brainfuck.hpp"
#include "compiler.hpp"
#include "enums.hpp"

using bf::Error;
using bf::Brainfuck;
using bf::Code;
using bf::translate;

Error test_1()
{
    Error res;
    char hello_world[] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    Code compile = translate(hello_world);
    Brainfuck bf(compile); 
    res = bf.run();
    return res;
} 

Error test_2()
{
    Error res;
    char Sierpinski_triangle[] = "++++++++[>+>++++<<-]>++>>+<[-[>>+<<-]+>>]>+[-<<<[->[+[-]+>++>>>-<<]<[<]>>++++++[<<+++++>>-]+<<++.[-]<<]>.>+[>>]>+]";
    Code compile = translate(Sierpinski_triangle);
    Brainfuck bf(compile); 
    res = bf.run();
    return res;
} 

Error test_3()
{
    Error res;
    std::cout << "Enter the number of the layers of the tree (in ASCII): " << std::endl;
    char tree[] = ">>>--------<,[<[>++++++++++<-]>>[<------>>-<+]]++>>++<--[<++[+>]>+<<+++<]<<[>>+[[>>+<<-]<<]>>>>[[<<+>.>-]>>]<.<<<+<<-]>>[<.>--]>.>>.";
    Code compile = translate(tree);
    Brainfuck bf(compile);
    res = bf.run();
    return res;
}

Error test_4()
{
    Error res;
    char source[] = "++++[>++++++<-]>[>+++++>+++++++<<-]>>++++<[[>[[>>+<<-]<]>>>-]>-[>+>+<<-]>]+++++[>+++++++<<++>-]>.<<.";
    Code compile = translate(source);
    Brainfuck bf(compile); 
    res = bf.run();
    return res;
}

Error test_5()
{
    Error res;
    char problems[] = "[]++++++++++[>>+>+>++++++[<<+<+++>>>-]<<<<-]A*$;?@![#>>+<<]>[>>]<<<<[>++<[-]]>.>.";
    Code compile = translate(problems);
    Brainfuck bf(compile); 
    res = bf.run();
    return res;
} 


int main()
{
    Error res;
    //boolean ok = true;
    
    //ok &= test_1() == Error::Succeeded;
    //ok &= test_2() == Error::Succeeded;
    //const char result = ok ? "Pass" : "Fail";
    //std::cout << result;
    res = test_2();
    res = test_2();
    res = test_3();
    res = test_4();
    res = test_5();
    
    std::cout << static_cast<int>(res) << std::endl;

    return 0;
}


