#include <iostream>
#include <cstddef> // std::size_t
#include <cstring> // std::string
#include <vector> // std::vector
#include <array> // std::array
#include <optional> // std::optional
#include "containers.hpp"

using namespace tf;

void test_1()
{
    std::vector arr_1 {1,2,3,4,5,6,7,8,8,10};

    std::cout << "The array is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;
      
    std::optional<typename std::vector<int>::const_iterator>  res_1 = find_duplicates(arr_1);

    bool c = is_sorted(arr_1);
    bool a = is_reverse_sorted(arr_1);

    if (res_1.has_value()) {
        std::cout <<  "The first duplicate element in arr_1 (int) is: " << *(res_1.value()) << std::endl; 
    }
    std::cout << "arr_1 is sorted? " << (c? "true" : "false") << std::endl;
    std::cout <<  "arr_1 is reversed sorted?: " << (a? "true" : "false") << std::endl << std::endl;
}

void test_2()
{
    std::array<double, 10> arr_2 {9.3,8.0,7.5,6.2,5.6,5.5,3.2,3.2,2.7,1.5};

    std::cout << "The array is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_2[i] << ", ";
    }
    std::cout << std::endl;
    
    std::optional<typename std::array<double, 10>::const_iterator>  res_2 = find_duplicates(arr_2);
    
    bool d = is_sorted(arr_2);
    bool b = is_reverse_sorted(arr_2);  
    
    if (res_2.has_value()) {
        std::cout <<  "The first duplicate elemen in arr_2 is: "  << *(res_2.value()) << std::endl;
    }
    std::cout <<  "arr_1 is sorted? " << (d? "true" : "false")  << std::endl;
    std::cout <<  "arr_1 is reversed sorted?: " << (b? "true" : "false") << std::endl;
}

void test_3()
{
    std::array<char, 10> arr_1{'a','b','c','d','e','f','g','h','i','i'};

    std::cout << "The array is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<typename std::array<char, 10>::const_iterator>  res_1 = find_duplicates(arr_1);
    
    bool c = is_sorted(arr_1);
  
    if (res_1.has_value()) {
        std::cout <<  "The first duplicate element in arr_1 is: " << *(res_1.value()) << std::endl; 
    }
    std::cout <<  "arr_1 is sorted? " << (c? "true" : "false") << std::endl;
}

void test_4()
{
    std::vector<std::string> arr_1 {"mom","dad","son","brother","dad"};

    std::cout << "The array is: ";
    for(int i = 0; i < 5; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;
    
    std::optional<typename std::vector<std::string>::const_iterator>  res_1 = find_duplicates(arr_1);
    
    bool c = is_sorted(arr_1);
  
    if (res_1.has_value()) {
        std::cout <<  "The first duplicate element in arr_1 is: " << *(res_1.value())<< std::endl; 
    }
    std::cout <<  "arr_1 is sorted? " << (c? "true" : "false") << std::endl;
}

void test_5()
{
    std::array<int, 0> arr_1;
  
    auto res_1 = find_duplicates(arr_1);
    
    bool c = is_sorted(arr_1);
    bool b = is_reverse_sorted(arr_1);  
  
    if (res_1.has_value()) {
        std::cout <<  "The first duplicate element in arr_1 is: " << *(res_1.value())<< std::endl; 
    }
    std::cout <<  "arr_1 is sorted? " << (c? "true" : "false") << std::endl;
    std::cout <<  "arr_1 is reversed sorted?: " << (b? "true" : "false") << std::endl;
}

void test_6()
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

    std::optional<int> a = first_unique_element(arr_1);
    std::optional<double> b = first_unique_element(arr_2);    
    int c = min_element(arr_1);
    double d = min_element(arr_2);

    std::cout <<  "The first unique element in the first container (std::vector<int>) is: " << a.value() << std::endl; 
    std::cout <<  "The first unique element in the second container (std::array<double, 10>) is: " << b.value() << std::endl;
    std::cout <<  "The min element of the first container is: " << c << std::endl;
    std::cout <<  "The min element of the second container is: " << d << std::endl; 
}

void test_7()
{
    std::vector arr_1{'u','a','v','a','s','y','u','j','u','v'};

    std::cout << "The container is: ";
    for(int i = 0; i < 10; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<char> a = first_unique_element(arr_1);
    char c = min_element(arr_1);

    std::cout <<  "The first unique element in the container (std::vector<char>) is: " << a.value() << std::endl; 
    std::cout <<  "The min element of the container is: " << c << std::endl;
}

void test_8()
{
    std::array<std::string, 5> arr_1 {"dad","mom","dad","son","brother"};

    std::cout << "The container is: ";
    for(int i = 0; i < 5; ++i) {
        std::cout << arr_1[i] << ", ";
    }
    std::cout << std::endl;

    std::optional<std::string> a  = first_unique_element(arr_1);
    std::string c = min_element(arr_1);

    std::cout <<  "The first unique element in the container (std::array<std::string, 5) is: " << a.value() << std::endl; 
    std::cout <<  "The min element of the container is: " << c << std::endl;
}

int main()
{    
    std::cout << "Checking for int: " << std::endl;
    test_1();

    std::cout << "Checking for double: " << std::endl;
    test_2();

    std::cout << std::endl << "Checking for char: " << std::endl;
    test_3();

    std::cout << std::endl << "Checking for string: " << std::endl;
    test_4();

    std::cout << std::endl << "Checking for an empty array: " << std::endl;
    test_5();

    std::cout << "\nTest the old functions (first_unique_element & min_element)\n\n";
    
    std::cout << "Checking for std::vector<int> and for std::array<double, 10>: " << std::endl;
    test_6();

    std::cout << std::endl << "Checking for std::vector<char>: " << std::endl;
    test_7();

    std::cout << std::endl << "Checking for std::array<std::string, 5>: " << std::endl;
    test_8();

    return 0;
}

