#ifndef BYTE_ARRAY_H
#define BYTE_ARRAY_H

#include <cstddef>
#include <cstdint>
#include <iostream>
#include "errors.hpp"

namespace dv
{

class Byte_array
{
public:
    explicit Byte_array(size_t size);
    Byte_array(const Byte_array& arr);
    Byte_array& operator=(const Byte_array& arr);
    ~Byte_array();

    int8_t& operator[](size_t index);
    int8_t const& operator[](size_t index) const;
    
    size_t get_size() const;
    void reset();
    bf::Error print(std::ostream& os);
    
private:
    size_t m_size;
    int8_t *m_array;
};

}

#endif
