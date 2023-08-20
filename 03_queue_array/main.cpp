#include "queue_array.hpp"
#include "iostream"


int main()
{
    /* Create 4 queues - of differents data types */
    queue_array <int> a(10);
    queue_array <int> b;
    queue_array <int> e(10);
    queue_array <char> f(10);

    /* Enqueue elements into 3 of them  */
    for (int i(0); i < 10; ++i) {
        a.enqueue(i);
        e.enqueue(i * 2);
        f.enqueue('i');
    }

    /* Enqueue elements from 2 of them  */
    for (int i(0); i < 6; ++i) {
         a.dequeue();
         e.dequeue();
    }
       
    std::cout << "The size of a is: " << a.get_size() << std::endl;
    std::cout << "The size of b (different constructor) is: " << b.get_size() << std::endl;

    /* Use in the copy constructor */
    queue_array<int> c = a;
    std::cout << "The size of c (initialized by copy constructor from a) is: " << c.get_size() << std::endl;

    std::cout << "Pick 'c' (checking the pick function & the copy constructor): " << c.pick() << std::endl;
    std::cout << "Pick 'e' (checking the pick function): " << e.pick() << std::endl;

    /* use in the assignment operator */
    b = c;
    std::cout << "The size of b after the assignment from c is (checking the assignment operetor): " << b.get_size() << std::endl;
    std::cout << "Pick 'b' (checking the pick function & the assignment operetor): " << b.pick() << std::endl;
    
    /* Print the stacks elements: */
    std::cout << "The elements in stack <int> a: \n";
    a.print_queue_elements();
    
    std::cout << "The elements in stack <int> b: \n";
    b.print_queue_elements();
    
    std::cout << "The elements in stack <int> c: \n";
    c.print_queue_elements();

    std::cout << "The elements in stack <float> e: \n";
    e.print_queue_elements();

    std::cout << "The elements in stack <char> f: \n";
    f.print_queue_elements();
    
    return 0;
}