#include "rational.hpp"
#include <iostream>
#include <cassert>

Rational::Rational()
    : nomerator(0), denomerator(1)
{
}

Rational::Rational(int n)
    : nomerator(n), denomerator(1)
{
}

Rational::Rational(int n, int d)
{
    int den = (d != 0) ? d : 1;
    int gcd = Rational::gcd(n, den);
    nomerator = n / gcd;
    denomerator = d / gcd;
}

Rational::Rational(const Rational &fraction)
    : nomerator(fraction.nomerator), denomerator(fraction.denomerator)
{
}

Rational &Rational::operator=(const Rational &fraction)
{
    int den = (fraction.denomerator != 0) ? fraction.denomerator : 1;
    int gcd = Rational::gcd(fraction.nomerator, den);
    nomerator = fraction.nomerator / gcd;
    denomerator = fraction.denomerator / gcd;
    return *this;
}

Rational Rational::operator+(const Rational &fraction) const
{
    int new_nom = (this->nomerator * fraction.denomerator) + (fraction.nomerator * this->denomerator);
    int new_denom = fraction.denomerator * this->denomerator;
    Rational res(new_nom, new_denom);
    return res;
}

Rational Rational::operator-(const Rational &fraction) const
{
    int new_nom = (this->nomerator * fraction.denomerator) - (fraction.nomerator * this->denomerator);
    int new_denom = fraction.denomerator * this->denomerator;
    Rational res(new_nom, new_denom);
    return res;
}

Rational Rational::operator*(const Rational &fraction) const
{
    int new_nom = this->nomerator * fraction.nomerator;
    int new_denom = fraction.denomerator * this->denomerator;
    Rational res(new_nom, new_denom);
    return res;
}

Rational Rational::operator/(const Rational &fraction) const
{
    int new_nom = this->nomerator * fraction.denomerator;
    int new_denom = fraction.nomerator * this->denomerator;
    Rational res(new_nom, new_denom);
    return res;
}

Rational Rational::operator+=(const Rational &fraction)
{
    *this = *this + fraction;
    return *this;
}

Rational Rational::operator-=(const Rational &fraction)
{
    *this = *this - fraction;
    return *this;
}

Rational Rational::operator*=(const Rational &fraction)
{
    *this = *this * fraction;
    return *this;
}

Rational Rational::operator/=(const Rational &fraction)
{
    *this = *this / fraction;
    return *this;
}

Rational Rational::operator +=(int num) 
{
   nomerator += num * denomerator; 
   return *this;
}

Rational Rational::operator -=(int num) 
{
   nomerator -= num * denomerator; 
   return *this;
}

Rational Rational::operator *=(int num) 
{
   nomerator = nomerator * num; 
   return *this;
}

Rational Rational::operator /=(int num) 
{
   denomerator = denomerator * num; 
   return *this;
}

Rational Rational::operator +(int num) 
{
   Rational res = *this;
   res += num; 
   return res;
}

Rational Rational::operator -(int num) 
{
   Rational res = *this;
   res -= num; 
   return res;
}

Rational Rational::operator *(int num) 
{
   Rational res = *this;
   res *= num; 
   return res;
}

Rational Rational::operator /(int num) 
{
   Rational res = *this;
   res /= num; 
   return res;
}

bool Rational::operator==(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) == ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator!=(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) != ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator>=(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) >= ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator<=(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) <= ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator>(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) > ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator<(const Rational &fraction) const
{
    return ((double)nomerator / denomerator) < ((double)fraction.nomerator / fraction.denomerator);
}

bool Rational::operator==(int) const
{
    return (nomerator != 0);
}

float Rational::get_value()
{
    return (double)nomerator / denomerator;
}

int Rational::get_nomerator()
{
    return nomerator;
}

int Rational::get_denomerator()
{
    return denomerator;
}

int Rational::gcd(int m, int n) const
{
    m = (m > 0) ? m : m * -1;
    n = (n > 0) ? n : n * -1;

    int a = (m > n) ? m : n;
    int b = (m > n) ? n : m;

    int temp = 0;
    while (b > 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

std::ostream &operator<<(std::ostream &os, Rational &fraction)
{
    os << fraction.get_value();
    return os;
}