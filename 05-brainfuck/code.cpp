#include <iostream>
#include "code.hpp"

using namespace bf;

Code::Code(size_t size)
    : m_code(size)
    , m_index_ptr(0) 
{
}
  
OpCode Code::operator[](size_t index)
{
    return static_cast<OpCode>(m_code[index]);
}

void Code::set_value(OpCode op, size_t index)
{
    m_code[index] = static_cast<int8_t>(op);
}

void Code::operator++()
{
    ++m_index_ptr;
}

void Code::operator--()
{
    --m_index_ptr;
}

size_t Code::get_size()
{
    return m_code.get_size();
}

OpCode Code::get_current()
{
    return static_cast<OpCode>(m_code[m_index_ptr]);
}

bool Code::is_end()
{
    return (m_index_ptr >= m_code.get_size() - 1); 
}

Error Code::print(std::ostream& os)
{
    for (size_t i(0); i < m_code.get_size(); ++i) {
        os << static_cast<int>(m_code[i]) << ", ";
    }
    os << std::endl;
    return Error::Succeeded;
}

