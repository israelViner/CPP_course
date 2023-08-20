#include "polynomial.hpp"
#include "iostream"

int main()
{
    int mat[][2] = {{1, 1},{2, 1},{3, 1},{4, 1},{5, 1},{6, 1}}; // {{0,1},{0,1},{1,1}};//
    int mat_1[][2] = {{1, 1},{1, 2},{1, 3}};

    pl::Polynomial A(mat, 6);    
    pl::Polynomial B(mat_1, 3);
    pl::Polynomial C = A - B;

    std::cout << "Polynom A is:" << std::endl;
    std::cout << A << std::endl;

    Rational test = Rational(1, 1);
    A.change_coef(2) = test;
    std::cout << "A.change_coef(2) == Rational(1, 1): " << (A.change_coef(2) == test) << std::endl << std::endl;
    
    std::cout << "Now polynom A is:" << std::endl;
    std::cout << A << std::endl;
    std::cout << "Polynom B is:" << std::endl;
    std::cout << B << std::endl;
    std::cout << "Polynom C equal to A - B:" << std::endl;
    std::cout << C << std::endl;
    C += B;
    std::cout << "C += B (that is - equal to A):" << std::endl;
    std::cout << C << std::endl;
    C = A.pow(2); 
    std::cout << "C = A.pow(2):" << std::endl;
    std::cout << C << std::endl; 
    C /= A; 
    std::cout << "C /= A (that is - equal to A):" << std::endl;
    std::cout << C << std::endl;    
    C *= 2; 
    std::cout << "C *= 2:" << std::endl;
    std::cout << C << std::endl;
    C = A - A + B; 
    std::cout << "C = A - A + B:" << std::endl;
    std::cout << C << std::endl;
    C = B * 2; 
    std::cout << "C = B * 2:" << std::endl;
    std::cout << C << std::endl;
    C = A.pow(3);
    std::cout << "C = A.pow(3):" << std::endl;
    std::cout << C << std::endl;
    C = A.derivation();
    std::cout << "C = A.derivation():" << std::endl;
    std::cout << C << std::endl;
    std::cout << "A(1/2) = ";
    std::cout << A.value_at(0.5) << std::endl << std::endl;
    std::cout << "B(2) = ";
    Rational b(2, 1);
    Rational c = B.value_at(b);
    std::cout << c << std::endl << std::endl;
    
    return 0;
}