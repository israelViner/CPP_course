#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "messenger.hpp"
#include "transform.hpp"
#include "upper.hpp"
#include "lower.hpp"
#include "encryption.hpp"
#include "atbash.hpp"
#include "vector_key.hpp"
#include "input.hpp"
#include "in_string.hpp"
#include "cin.hpp"
#include "fin.hpp"
#include "cout.hpp"
#include "fout.hpp"


using namespace st;

void lower_test()
{
    std::string tmp = "My TaSK";
    InString str(tmp);
    Cout c;
    Lower low;
    Transform* tr = &low;
    string_transform(str, *tr, c);
}

void upper_test()
{
    std::string tmp = "My TaSK";
    InString str(tmp);
    Cout c;
    Upper up;   
    string_transform(str, up, c);
}

void encrypted_test()
{
    std::string tmp = "aBcDeFg ZyXw";
    InString str(tmp);
    Cout c;
    Encryption up;   
    string_transform(str, up, c);
}

void atbash_test()
{
    std::string tmp = "abcdef-mn-zyxwvu";
    InString str(tmp);
    Cout c;
    Atbash at;   
    string_transform(str, at, c);
}

void vector_key_test()
{
    std::string tmp = "abcdefghijkLMNOPQRSTUVWXYZ";
    InString str(tmp);
    std::string a = "2b!A";
    Cout c;
    VectorKey key(a);   
    string_transform(str, key, c);
}

void edge_cases_test()
{
    std::cout << "Empty string:\n";
    std::string tmp = "";
    InString str(tmp);
    Cout c;
    Upper up;   
    string_transform(str, up, c);
}

void fin_test()
{
    std::string tmp = "string";  // The name of the file  
    Fin str(tmp); 
    Upper up;
    Cout c;
    string_transform(str, up, c);
    Lower low; 
    string_transform(str, low, c);
}

void fout_test()
{
    Fout fout;
    std::string tmp = "My biggest TaSK EVER";
    InString str(tmp);
    Lower low;
    string_transform(str, low, fout);    
}

void main_test()
{
    std::cout << "Enter the string that you want to transform: \n";
    Cin str;
    Fout c;
    std::cout << "Test the upper: \n";
    Upper up; 
    string_transform(str, up, c);
    std::cout << "Test the lower: \n";
    Lower low; 
    string_transform(str, low, c);
    std::cout << "Test the encryption: \n";
    Encryption en; 
    string_transform(str, en, c);
}

int main()
{
    std::cout << "Test the upper transformation on the string 'My TaSK':\n";
    lower_test();

    std::cout << "Test the lower transformation on the string 'My TaSK':\n";
    upper_test();

    std::cout << "Test edge cases:\n";
    edge_cases_test();
    
    std::cout << "Test receiving the string as input from the 'string' file (upper & lower):\n";
    fin_test();    

    std::cout << "Test the encription of the string 'aBcDeFg ZyXw':\n";
    encrypted_test(); 

    std::cout << "Test the atbash of the string 'abcdef-mn-zyxwvu':\n";
    atbash_test();

    std::cout << "Test the vector_key encription of the string 'abcdefghijkLMNOPQRSTUVWXYZ' and the key string '2bA':\n";
    vector_key_test();

    std::cout << "Test output the translated (lower) string into a file:\n";
    fout_test();   

    std::cout << "Test output the transfroing string into a chosen file:\n";
    main_test();

    return 0;
}

#endif
