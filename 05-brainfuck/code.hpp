#ifndef CODE_H
#define CODE_H

#include "enums.hpp"
#include "byte_array.hpp"

namespace bf {

class Code
{
public:
    explicit Code(size_t size);
      
    OpCode operator[](size_t index);
    void operator++();
    void operator--();
    Error print(std::ostream& os);
    size_t get_size();
    bool is_end();
    OpCode get_current();
    void set_value(OpCode op, size_t index);

private:
    dv::Byte_array m_code;
    size_t m_index_ptr;
};

}

#endif