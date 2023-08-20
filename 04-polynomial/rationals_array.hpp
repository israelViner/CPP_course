#include "../01_rational/rational.hpp"

namespace dv
{

class Rationals_array
{
public:
    explicit Rationals_array();
    explicit Rationals_array(size_t size);
    explicit Rationals_array(Rational *coef, size_t size);
    Rationals_array(int matrix[][2], size_t size);
    Rationals_array(const Rationals_array &p);
    Rationals_array& operator=(const Rationals_array &p);
    ~Rationals_array();

    const Rational& operator[](size_t i) const;
    Rational& operator[](size_t i);
    size_t get_size() const;
    Rational *get_array() const;

private:
    size_t m_size;
    Rational *m_coefficents;
};

}

std::ostream& operator<<(std::ostream &os, const dv::Rationals_array& poly);
