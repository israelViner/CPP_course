#include "polynomial.hpp"
#include "cmath"
#include "cassert"

pl::Polynomial::Polynomial()
    : m_degree(0)
    , m_polynom(dv::Rationals_array())
{
}

pl::Polynomial::Polynomial(size_t degree)
    :  m_degree(degree)
    , m_polynom(dv::Rationals_array(degree + 1))
{
}

pl::Polynomial::Polynomial(dv::Rationals_array coef)
    : m_degree(coef.get_size() - 1)
    , m_polynom(coef)
{
}

pl::Polynomial::Polynomial(int matrix[][2], size_t size)
    : m_degree(size - 1)
    , m_polynom(matrix, size)
{
}

pl::Polynomial pl::Polynomial::operator+(const Polynomial& p)
{
    Polynomial res = (m_degree > p.m_degree) ? *this : p;
    
    /* If one of the polynomials is zero */
    if (!m_polynom.get_size() || !p.m_polynom.get_size()) {
        return res;
    }    

    /* Addition */
    size_t i = 0;
    for (; i <= m_degree && i <= p.m_degree; ++i) {
        res.m_polynom[i] = m_polynom[i] + p.m_polynom[i];
    }

    /* Handling with changing the length of the polynomial */
    if (p.m_degree == m_degree) {
        while (i > 0 && !res.m_polynom[--i].get_value()) {}

        if (i < res.m_degree) {
            if (i) {
                dv::Rationals_array temp(res.get_array(), i + 1);
                res.m_polynom = temp;
                res.m_degree = temp.get_size() -1;
            }
            else {
                res.m_polynom = dv::Rationals_array(0);
                res.m_degree = 0;
            }
        }
    }

    return res;
}

pl::Polynomial pl::Polynomial::operator-(const Polynomial& p)
{
    Polynomial res = (m_degree > p.m_degree) ? *this : p;
    
    /* If one of the polynomials is zero */
    if (!m_polynom.get_size()) {
        return res * -1;
    } 
    if (!p.m_polynom.get_size()) {
        return res;
    }    

    /* Subtruction */
    size_t i = 0;
    for (; i <= m_degree && i <= p.m_degree; ++i) {
        res.m_polynom[i] = m_polynom[i] - p.m_polynom[i];
    }

    /* Handling with subtructing a larger polynomial */
    if (p.m_degree > m_degree) {
        for (; i <= res.m_degree; ++i) {
            res.m_polynom[i] *= 0;
        }
    }

    /* Handling with changing the length of the polynomial */
    else if (p.m_degree == m_degree) {
        while (i > 0 && !res.m_polynom[--i].get_value()) {}

        if (i < res.m_degree) {
            if (i) {
                dv::Rationals_array temp(res.get_array(), i + 1);
                res.m_polynom = temp;
                res.m_degree = temp.get_size() -1;
            }
            else {
                res.m_polynom = dv::Rationals_array(0);
                res.m_degree = 0;
            }
        }
    }

    return res;
}

pl::Polynomial pl::Polynomial::operator*(const Polynomial& poly)
{
    size_t new_size = m_degree + poly.m_degree + 1;
    dv::Rationals_array new_coef(new_size);

    for (size_t i(0); i <= m_degree; ++i) {
        for (size_t j(0); j <= poly.m_degree; ++j) {
            new_coef[i + j] += m_polynom[i] * poly.m_polynom[j];
        }
    }

    Polynomial res(new_coef);
    return res;
}

pl::Polynomial pl::Polynomial::operator/(const Polynomial& poly)
{
    assert(m_degree >= poly.m_degree);
    pl::Polynomial temp = *this;
    pl::Polynomial new_coef(m_degree - poly.m_degree);
    size_t loc = poly.m_degree;

    while (temp.m_degree >= poly.m_degree) {
        size_t i = temp.m_degree;
        new_coef.m_polynom[i - loc] = temp.m_polynom[i] / poly.m_polynom[loc];
        Polynomial t(i - loc);
        t.m_polynom[i - loc] = new_coef.m_polynom[i - loc];
        temp -= t * poly;
    }
    assert(!temp.m_polynom.get_size());
    return new_coef;
}

pl::Polynomial& pl::Polynomial::operator+=(const Polynomial& poly)
{
    *this = *this + poly;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator-=(const Polynomial& poly)
{
    *this = *this - poly;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator*=(const Polynomial& poly)
{
    *this = *this * poly;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator/=(const Polynomial& poly)
{
    *this = *this / poly;
    return *this;
}

pl::Polynomial pl::Polynomial::operator+(int num)
{
    Polynomial res = *this;
    res.m_polynom[0] += num;
    return res;
}

pl::Polynomial pl::Polynomial::operator-(int num)
{
    Polynomial res = *this;
    res.m_polynom[0] -= num;
    return res;
}

pl::Polynomial pl::Polynomial::operator*(int num)
{
    Polynomial res = *this;
    for (size_t i(0); i <= res.m_degree; ++i) {
        res.m_polynom[i] *= num;
    }
    return res;
}

pl::Polynomial pl::Polynomial::operator/(int num)
{
    Polynomial res = *this;
    for (size_t i(0); i <= m_degree; ++i) {
        res.m_polynom[i] /= num;
    }
    return res;
}

pl::Polynomial& pl::Polynomial::operator+=(int num)
{
    m_polynom[0] += num;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator-=(int num)
{
    m_polynom[0] -= num;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator*=(int num)
{
    *this = *this * num;
    return *this;
}

pl::Polynomial& pl::Polynomial::operator/=(int num)
{
    *this = *this / num;
    return *this;
}

Rational& pl::Polynomial::change_coef(size_t loc)
{
    assert(loc <= m_degree);
    return m_polynom[loc];
}

bool pl::Polynomial::operator==(const Polynomial& p) const
{
    if(m_degree != p.m_degree) {
        return false;
    }

    if(!m_polynom.get_size()){
        return true;
    }
    
    for (size_t i(0); i <= m_degree; ++i) {
        if (m_polynom[i] != p.m_polynom[i]) {
            return false;
        }
    }
    return true;
}

bool pl::Polynomial::operator!=(const Polynomial& p) const
{
    if(m_degree != p.m_degree) {
        return false;
    }

     if(!m_polynom.get_size()){
        return false;
    }
        
    for (size_t i(0); i <= m_degree; ++i) {
        if (m_polynom[i] != p.m_polynom[i]) {
            return true;
        }
    }
    return false;
}

pl::Polynomial pl::Polynomial::pow(unsigned int degree) const
{
    Polynomial res = *this;
    for (unsigned int i(1); i < degree; ++i) {
        res = res * *this;
    }
    return res;
}

pl::Polynomial pl::Polynomial::derivation()
{
    dv::Rationals_array der(m_degree);
    for (size_t i(0); i < m_degree; ++i) {
        der[i] = m_polynom[i + 1] * (i + 1);
    }
    pl::Polynomial res(der);
    return res;
}

Rational pl::Polynomial::value_at(int nomerator, int denomerator)
{
    if (!m_polynom.get_size()) {
        return Rational();
    }
    Rational x(nomerator, denomerator);
    Rational res;
    for (size_t i(m_degree); i > 0; --i) {
        res += m_polynom[i];
        res *= x;
    }
    res += m_polynom[0];
    return res;
}

Rational pl::Polynomial::value_at(Rational fraction)
{
    return value_at(fraction.get_nomerator(), fraction.get_denomerator());
}

float pl::Polynomial::value_at(float num)
{
    float res = 0;
    for (size_t i(m_degree); i > 0; --i) {
        res += m_polynom[i].get_value();
        res *= num;
    }
    res += m_polynom[0].get_value();
    return res;
}


Rational *pl::Polynomial::get_array() const
{
    return m_polynom.get_array();
}

dv::Rationals_array pl::Polynomial::get_vector() const
{
    return m_polynom;
}

std::ostream& operator<<(std::ostream &os, const pl::Polynomial& poly)
{
    os << poly.get_vector();
    return os;
}
