#include <iostream>
#include <cstring> // std::string
#include <optional> // std::optional
#include "list.hpp"
#include "../07-containers/containers.hpp" // for containers functions

using namespace ds;

void test_front()
{
    List<int> list_1;

    list_1.push_front(1);
    list_1.push_front(2);
    list_1.push_front(3);
    list_1.push_front(4);
    std::cout << "The list is: ";
    std::cout << list_1;

    bool e = list_1.find(4);
    std::cout << "4 is in the list? - " << (e? "true" : "false") << std::endl;

    int a = list_1.size();

    int b = list_1.pop_front();
    int c = list_1.pop_front();

    int d = list_1.size();

    std::cout << "The number of elements in the list before the removal out is: " << a << ", \nThe two element that was removed are: " << b << ", " << c << std::endl;
    std::cout << "And now " << d << " elements left in the list, which are: \n";
    std::cout << list_1;
}

void test_back()
{
    List<int> list_1;

    list_1.push_back(1);
    list_1.push_back(2);
    list_1.push_back(3);
    list_1.push_back(4);
    std::cout << "The list is: ";
    std::cout << list_1;

    int a = list_1.size();

    int b = list_1.pop_back();
    int c = list_1.pop_back();

    int d = list_1.size();

    std::cout << "The number of elements in the list before the removal is: " << a << ", \nThe two elements that were removed are: " << b << ", " << c << std::endl;
    std::cout << ", And now " << d << " elements left in the list, which are: \n";
    std::cout << list_1;
}

void test_string()
{
    List<std::string> list_1;

    list_1.push_front("dad");
    list_1.push_front("mom");
    list_1.push_front("son");
    list_1.push_front("brother");
    std::cout << "The list is: ";
    std::cout << list_1;

    bool e = list_1.find("baby");
    std::cout << "'baby' is in the list? - " << (e? "true" : "false") << std::endl;

    int a = list_1.size();

    std::string b = list_1.pop_front();
    std::string c = list_1.pop_front();

    int d = list_1.size();

    std::cout << "The number of elements in the list before the removal is: " << a << ", \nThe two elements that were removed are: " << b << ", " << c << std::endl;
    std::cout << ", And now " << d << " elements left in the list, which are: \n";
    std::cout << list_1;
}

void test_weave()
{
    List<int> list_1;

    list_1.push_back(1);
    list_1.push_back(2);
    list_1.push_back(3);
    list_1.push_back(4);
    list_1.push_back(5);
    std::cout << "The first list is: ";
    std::cout << list_1;

    List<int> list_2;

    list_2.push_back(9);
    list_2.push_back(8);
    list_2.push_back(7);
    std::cout << "The second list is: ";
    std::cout << list_2;

    list_1 = weave(list_1, list_2);

    std::cout << "The weave list is: \n";
    std::cout << list_1;
}

void test_concatenate()
{
    List<int> list_1;

    list_1.push_back(1);
    list_1.push_back(2);
    list_1.push_back(3);
    list_1.push_back(4);
    list_1.push_back(5);
    std::cout << "The first list is: ";
    std::cout << list_1;

    List<int> list_2;

    list_2.push_back(9);
    list_2.push_back(8);
    list_2.push_back(7);
    std::cout << "The second list is: ";
    std::cout << list_2;

    list_1 = concatenate(list_1, list_2);

    std::cout << "The concatenated list is: \n";
    std::cout << list_1;
}

void test_pop_by_index()
{
    List<int> list_1;

    list_1.push_front(1);
    list_1.push_front(2);
    list_1.push_front(3);
    list_1.push_front(4);
    std::cout << "The original list is: ";
    std::cout << list_1;

    list_1.pop_by_index(2);
    
    std::cout << "The list after removal of element of index 2 is: \n";
    std::cout << list_1;
}

void test_get_functions()
{
    List<int> list_1;

    list_1.push_front(1);
    list_1.push_front(2);
    list_1.push_front(3);
    list_1.push_front(4);
    std::cout << "The original list is: ";
    std::cout << list_1;

    int a = list_1.get_front();
    int b = list_1.get_back();
    int c = list_1.get_by_index(2);

    std::cout << "The first element in the list is: " << a << ", the last is: " << b << ", and the third element is: " << c << "\n";
    
    std::cout << "Now the list is: \n";
    std::cout << list_1;
}

void test_containers() 
{
    List<int> list_1;
    
    list_1.push_front(1);
    list_1.push_front(2);
    list_1.push_front(3);
    list_1.push_front(4); 
    list_1.push_front(3);

    std::cout << "The list is: ";
    std::cout << list_1;

    std::optional<typename ds::List<int>::iterator> res = tf::find_duplicates(list_1); 

    std::cout << "The duplicate element in the list is: " << *res.value() << std::endl;

    std::cout << "The list is sorted? - " << (tf::is_sorted(list_1)? "true" : "false") << std::endl; 
}

// A struct and a functions for the next test 
struct student 
{
    student(int age, std::string name) : m_age(age), m_name(name) {}
    int m_age;
    std::string m_name;
};

bool by_age(student a, student b)  {return a.m_age > b.m_age;}
bool by_name(student a, student b)  {return a.m_name > b.m_name;}
std::ostream& operator<<(std::ostream& os, student const& s) {os << "[name: " << s.m_name << ", age: " << s.m_age << "]"; return os;}


void test_pointer_functions()
{
    student a(15, "Israel");
    student b(20, "Moyshi");
    student c(25, "Baruch");
    student d(30, "Yair");

    List<student> students;
    
    students.push_back(a);
    students.push_back(b);
    students.push_back(c);
    students.push_back(d);

    std::cout << students;

    std::cout << "Lambda expressions: \n";
    std::cout << "The student list is sorted by name? - " << ((tf::is_sorted(students, [](student a, student b){return a.m_name > b.m_name;}))? "true" : "false" ) << std::endl;
    std::cout << "The student list is sorted by age? - " << ((tf::is_sorted(students, [](student a, student b){return a.m_age > b.m_age;}))? "true" : "false" ) << std::endl;

    std::cout << "Pointers functions: \n";
    std::cout << "The student list is sorted by name? - " << ((tf::is_sorted(students, by_name))? "true" : "false" ) << std::endl;
    std::cout << "The student list is sorted by age? - " << ((tf::is_sorted(students, by_age))? "true" : "false" ) << std::endl;
}

int main()
{
    std::cout << "\nTest the front functions: \n";
    test_front();

    std::cout << "\nTest the back functions: \n";
    test_back();
    
    std::cout << "\nTest list of strings: \n";
    test_string();

    std::cout << "\nTest the 'weave' function: \n";
    test_weave();

    std::cout << "\nTest the 'concatenate' function: \n";
    test_concatenate();

    std::cout << "\nTest the 'pop_by_index' function: \n";
    test_pop_by_index();

    std::cout << "\nTest the get functions: \n";
    test_get_functions();

    std::cout <<"\nTest the containers functions on a list: \n"; 
    test_containers();

    std::cout <<"\nTest the the pointers functions & lambda expressions: \n";
    test_pointer_functions();

    return 0;
}