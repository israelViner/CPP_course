#include "cassert"
#include "rationals_array.hpp"

dv::Rationals_array::Rationals_array()
    : m_size(1)
    , m_coefficents(new Rational[m_size])
{
}

dv::Rationals_array::Rationals_array(size_t size)
    : m_size(size)
    , m_coefficents(new Rational[m_size])
{
}

dv::Rationals_array::Rationals_array(Rational *coef, size_t size)
    : m_size(size)
    , m_coefficents(new Rational[m_size])
{
    assert(coef);
    for (size_t i(0); i < m_size; ++i) {
        m_coefficents[i] = coef[i];
    }
}

dv::Rationals_array::Rationals_array(int matrix[][2], size_t size)
    : m_size(size)
    , m_coefficents(new Rational[m_size])
{
    assert(matrix);
    for (size_t i(0); i < m_size; ++i) {
        Rational temp(matrix[i][0], matrix[i][1]);
        m_coefficents[i] = temp;
    }
}

dv::Rationals_array::Rationals_array(const Rationals_array &p)
    : m_size(p.m_size)
    , m_coefficents(new Rational[m_size])
{
    for (size_t i(0); i < m_size; ++i) {
        m_coefficents[i] = p.m_coefficents[i];
    }
}

dv::Rationals_array& dv::Rationals_array::operator=(const Rationals_array &p)
{
    if (this == &p) {
        return *this;
    }
    delete[] m_coefficents;
    m_size = p.m_size;
    m_coefficents = new Rational[m_size];
    for (size_t i(0); i < m_size; ++i) {
        m_coefficents[i] = p.m_coefficents[i];
    }
    return *this;
}

dv::Rationals_array::~Rationals_array()
{
    delete[] m_coefficents;
}

const Rational& dv::Rationals_array::operator[](size_t i) const
{
    assert(i < get_size());
    return m_coefficents[i];
}

Rational& dv::Rationals_array::operator[](size_t i)
{
    assert(i < get_size());
    return m_coefficents[i];
}

size_t dv::Rationals_array::get_size() const
{
    return m_size;
}

Rational *dv::Rationals_array::get_array() const
{
    return m_coefficents;
}

std::ostream& operator<<(std::ostream &os, const dv::Rationals_array& poly)
{
    dv::Rationals_array temp(poly.get_array(), poly.get_size());
    os << "p(x) = ";
    size_t i = 0;
    for (; i < temp.get_size(); ++i) {
        if (temp[i] == 0) {
            os << temp[i];
            if (i == 0) {
                os << " + ";
            }
            else if (i > 0 && i < temp.get_size() - 1) {
                os << " x^" << i << " + ";
            }
            else {
                os << " x^" << i << " ";
            }
        }
    }
    os << std::endl;
    return os;
}
