#include "stack_array.hpp"
#include "iostream"


int main()
{
    /* Create 4 stacks - of differents data types */
    stack_array <int> a(10);
    stack_array <int> b;
    stack_array <float> e(10);
    stack_array <char> f(10);

    /* Push elements into 3 of them  */
    for (int i(0); i < 10; ++i) {
        a.push(i);
        e.push((float)1/i);
        f.push('i');
    }
   
    std::cout << "The size of a is: " << a.get_size() << std::endl;
    std::cout << "The size of b (different constructor) is: " << b.get_size() << std::endl;

    /* Use in the copy constructor */
    stack_array<int> c = a;
    std::cout << "The size of c (initialized by copy constructor from a) is: " << c.get_size() << std::endl;

    std::cout << "Pick 'c' (checking the pick function & the copy constructor): " << c.pick() << std::endl;
    std::cout << "Pick 'e' (checking the pick function): " << e.pick() << std::endl;

    /* use in the assignment operator */
    b = c;
    std::cout << "The size of b after the assignment from c is (checking the assignment operetor): " << b.get_size() << std::endl;
    std::cout << "Pick 'b' (checking the pick function & the assignment operetor): " << b.pick() << std::endl;
    
    /* Print the stacks elements: */
    std::cout << "The elements in stack <int> a: \n";
    a.print_stack_elements();
    
    std::cout << "The elements in stack <int> b: \n";
    b.print_stack_elements();
    
    std::cout << "The elements in stack <int> c: \n";
    c.print_stack_elements();

    std::cout << "The elements in stack <float> e: \n";
    e.print_stack_elements();

    std::cout << "The elements in stack <char> f: \n";
    f.print_stack_elements();
    
    return 0;
}