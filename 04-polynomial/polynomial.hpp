#include "rationals_array.hpp"

namespace pl
{

class Polynomial
{
public:
    explicit Polynomial();
    explicit Polynomial(size_t size);
    explicit Polynomial(dv::Rationals_array coef);
    explicit Polynomial(int matrix[][2], size_t size);
    Polynomial(const Polynomial &p) = default;
    Polynomial &operator=(const Polynomial &p) = default;

    Polynomial operator+(const Polynomial &p);
    Polynomial operator-(const Polynomial &p);
    Polynomial operator*(const Polynomial &p);
    Polynomial operator/(const Polynomial& p);

    Polynomial& operator+=(const Polynomial &p);
    Polynomial& operator-=(const Polynomial &p);
    Polynomial& operator*=(const Polynomial &p);
    Polynomial& operator/=(const Polynomial& p);
    
    Polynomial operator+(int num);
    Polynomial operator-(int num);
    Polynomial operator*(int num);
    Polynomial operator/(int num);
    
    Polynomial& operator+=(int num);
    Polynomial& operator-=(int num);
    Polynomial& operator*=(int num);
    Polynomial& operator/=(int num);

    Rational& change_coef(size_t loc);

    bool operator==(const Polynomial &p) const;
    bool operator!=(const Polynomial &p) const;
    
    Polynomial pow(unsigned int degree) const;
    Polynomial derivation();
    
    Rational value_at(int nomerator, int denomerator);
    Rational value_at(Rational fraction);
    float value_at(float num);   

    Rational *get_array() const;
    dv::Rationals_array get_vector() const;    
    
private:
    size_t m_degree;
    dv::Rationals_array m_polynom;
};

}

std::ostream& operator<<(std::ostream &os, const pl::Polynomial &poly);
