#ifndef BF_MEMORY_H
#define BF_MEMORY_H

#include "byte_array.hpp"
#include "enums.hpp"


namespace bf
{

class Memory
{
public:
    explicit Memory();
    Memory(const Memory& memo) = default;
    Memory& operator=(const Memory& memo) = default;
    
    void realloc();
    void reset();

    void operator++(int);
    void operator--(int);
    void operator>>(int);
    void operator<<(int);
    Error operator()(); //  Write     
    void operator*(); // Ptinting (read)
    
    void set_value(int8_t v);
    int8_t get_value();
    Error print(std::ostream& os);

private:
    dv::Byte_array m_memory;
    size_t m_index_ptr;
};


}

#endif
