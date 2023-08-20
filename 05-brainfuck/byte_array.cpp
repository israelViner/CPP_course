#include "byte_array.hpp"
#include "errors.hpp"

dv::Byte_array::Byte_array(size_t size)
    : m_size(size)
    , m_array(new int8_t[m_size]())
{
}

dv::Byte_array::Byte_array(const Byte_array& arr)
    : m_size(arr.m_size)
    , m_array(new int8_t[m_size]())
{
    for(size_t i(0); i < m_size; ++i) {
        m_array[i] = arr.m_array[i];
    }
}

dv::Byte_array& dv::Byte_array::operator=(const Byte_array& arr) 
{
    if (this == &arr) {
        return *this;
    }
    m_size = arr.m_size;
    int8_t *new_arr = new int8_t[m_size];
    for(size_t i(0); i < m_size; ++i) {
        new_arr[i] = arr.m_array[i];
    }
    delete [] m_array;
    m_array = new_arr;
    return *this;
}

dv::Byte_array::~Byte_array()
{
    delete [] m_array;
}

int8_t& dv::Byte_array::operator[](size_t index)
{
    return m_array[index];
}

size_t dv::Byte_array::get_size() const
{
    return m_size;
}

void dv::Byte_array::reset()
{
    for (size_t i(0); i < m_size; ++i) {
        m_array[i] = 0;
    }
}

bf::Error dv::Byte_array::print(std::ostream& os)
{
    for (size_t i(0); i < m_size; ++i) {
        os << static_cast<int>(m_array[i]) << ", ";
    }
    os << std::endl;
    return bf::Error::Succeeded;
}