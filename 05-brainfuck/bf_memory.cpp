#include <cstdlib>
#include <iostream>
#include "bf_memory.hpp"
#include "errors.hpp"

namespace bf {

Memory::Memory()
    : m_memory(2)
    , m_index_ptr(1) 
{
}
   
void Memory::realloc()
{
    dv::Byte_array new_memory(m_memory.get_size() * 2);
    for (size_t i(0); i < m_memory.get_size(); ++i) {
        new_memory[i + (m_memory.get_size() / 2)] = m_memory[i];
    }
    m_index_ptr += m_memory.get_size() / 2;
    m_memory = new_memory;    
}

void Memory::operator>>(int)
{
    if (m_index_ptr == m_memory.get_size() - 1) {
        realloc();
    }
    ++m_index_ptr;
}

void Memory::operator<<(int)
{
    if (m_index_ptr == 0) {
        realloc();
    }
    --m_index_ptr;
}

void Memory::operator++(int)
{
    ++m_memory[m_index_ptr];
}

void Memory::operator--(int)
{
    --m_memory[m_index_ptr];
}

void Memory::reset()
{
    m_memory.reset();
}

int8_t Memory::get_value()
{
    return m_memory[m_index_ptr];
}
    
void Memory::set_value(int8_t v)
{
    m_memory[m_index_ptr] = v;
}
    
// int8_t& Memory::opertaor*()
// {
//     return m_memory[m_index_ptr];
// }    

Error Memory::operator()()
{
    Error res = Error::Succeeded;
    
    int8_t in;
    std::cin >> in;
    if (!in) {
        res = Error::InputError;
    }
    m_memory[m_index_ptr] = in;

    return res;
}

void Memory::operator*()
{
    std::cout << m_memory[m_index_ptr] << std::flush;
}

Error Memory::print(std::ostream& os)
{
    Error res = m_memory.print(os);
    return res;
}

} // namespace bf
