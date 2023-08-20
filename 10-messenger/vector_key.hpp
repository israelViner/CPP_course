#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "transform.hpp"

namespace st {

class VectorKey: public Transform
{
public:
    VectorKey(std::vector<int32_t> const& key) : m_vector(key) {}
    VectorKey(std::string const& key);
    void transform(std::string& str) const override;

private:
    std::vector<int32_t> m_vector;
}; 

} // namespace st

#endif