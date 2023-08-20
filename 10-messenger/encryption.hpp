#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <iostream>
#include <limits>
#include "transform.hpp"

namespace st {

class Encryption: public Transform
{
public:
    Encryption(int num) : m_jmp(num) {}
    Encryption() { std::cout << "Enter the number of letters that you want to skip: \n"; int num; std::cin >> num;
                    std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); m_jmp = num; }
    void transform(std::string& str) const override;

private:
    int m_jmp;
}; 

} // namespace st

#endif