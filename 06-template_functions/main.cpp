#include <optional>
#include <array>
#include <iostream>
#include <cstddef>
#include <cstring>
#include <vector> 
#include "template_functions.hpp"

void test_1()
{
    std::vector arr_1{8,2,6,3,4,5,3,5,2,8};
    std::array<double, 10> arr_2{1.5,2.0,1.5,3.2,4.6,0.5,3.0,5,2.0,8};
        
    std::cout << "The first container is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::cout << "The second container is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_2[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<int> a = te::first_unique_element(arr_1);
    std::optional<double> b = te::first_unique_element(arr_2);    
    int c = te::min_element(arr_1);
    double d = te::min_element(arr_2);

    std::cout <<  "The first unique element in the first container (std::vector<int>) is: " << a.value() << std::endl; 
    std::cout <<  "The first unique element in the second container (std::array<double, 10>) is: " << b.value() << std::endl;
    std::cout <<  "The min element of arr_1 is: " << c << std::endl;
    std::cout <<  "The min element of arr_2 is: " << d << std::endl; 
}

void test_2()
{
    std::vector arr_1{'u','a','v','a','s','y','u','j','u','v'};

    std::cout << "The container is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<char> a = te::first_unique_element(arr_1);
    char c = te::min_element(arr_1);

    std::cout <<  "The first unique element in the container (std::vector<char>) is: " << a.value() << std::endl; 
    std::cout <<  "The min element of arr_1 is: " << c << std::endl;
}

void test_3()
{
    std::array<std::string, 5> arr_1 {"dad","mom","dad","son","brother"};

    std::cout << "The container is: ";
    for(int i = 0; i < 5; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<std::string> a  = te::first_unique_element(arr_1);
    std::string c = te::min_element(arr_1);

    std::cout <<  "The first unique element in the container (std::array<std::string, 5) is: " << a.value() << std::endl; 
    std::cout <<  "The min element of arr_1 is: " << c << std::endl;
}

int main()
{    
    std::cout << "Checking for std::vector<int> and for std::array<double, 10>: " << std::endl;
    test_1();

    std::cout << std::endl << "Checking for std::vector<char>: " << std::endl;
    test_2();

    std::cout << std::endl << "Checking for std::array<std::string, 5>: " << std::endl;
    test_3();

    return 0;
}

