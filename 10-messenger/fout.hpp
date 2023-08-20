#ifndef FOUT_H
#define FOUT_H

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
#include "output.hpp"

namespace st {

class Fout: public Output 
{
public:
    Fout(std::string const& str) : m_file(str) {}
    Fout() { std::cout << "Enter the the name of the file: \n"; std::string name; std::cin >> name; 
            std::cin.clear(); std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); m_file.open(name);}
    void output(std::string const& str) override { m_file << str << std::endl; }

private:
    std::ofstream m_file;
};

}

#endif