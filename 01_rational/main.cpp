#include <iostream>
#include "rational.hpp"


int main()
{
    /* Create 4 Rational objects using all the constructors */
    Rational a(1, 2);
    Rational b(2);
    Rational c(250, 510);
    Rational d = b - a;
    //Rational e(1, 0);


    /* Print the objects */
    std::cout << "The 4 fractions a, b, c, d:\n";
    std::cout << a;
    std::cout << b;
    std::cout << c;
    std::cout << d;

    /* Check the bool operatoros ==, !=, >=, <=, >, < */
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl; 
    std::cout << "a > c: " << (a > c) << std::endl; 
    std::cout << "a < c: " << (a < c) << std::endl; 

    /* Check the operator += */
    std::cout << "a += b (2/1 + 1/2): \n";
    a+=b;
    std::cout << a;

    /* Check the operator *= */
    std::cout << "d *= a (3/2 * 1/2): \n";
    d*=a;
    std::cout << d;

    /* Check the operator /= */
    std::cout << "d /= a (3.75 / 2.5): \n";
    d/=a;
    std::cout << d;

    return 0;
}