#include <iostream>


class Rational 
{
public:
    /* Constructors */
    explicit Rational();
    explicit Rational(int n);
    explicit Rational(int n, int d);
    Rational(const Rational& fraction);
    Rational& operator=(const Rational& fraction);
        
    /* Operators overloading */
    Rational operator+(const Rational& fraction) const;
    Rational operator-(const Rational& fraction) const;
    Rational operator*(const Rational& fraction) const;
    Rational operator/(const Rational& fraction) const;

    Rational operator +=(const Rational& fraction);
    Rational operator -=(const Rational& fraction);
    Rational operator *=(const Rational& fraction);
    Rational operator /=(const Rational& fraction);

    bool operator ==(const Rational& fraction) const;
    bool operator !=(const Rational& fraction) const;
    bool operator >=(const Rational& fraction) const;
    bool operator <=(const Rational& fraction) const;
    bool operator <(const Rational& fraction) const;
    bool operator >(const Rational& fraction) const;
    bool operator ==(int) const;

    Rational operator +=(int num);
    Rational operator -=(int num);
    Rational operator *=(int num);
    Rational operator /=(int num);
    Rational operator +(int num);
    Rational operator -(int num);
    Rational operator *(int num);
    Rational operator /(int num);

   
    /* Get functions */
    float get_value();
    int get_nomerator();
    int get_denomerator();

private:
    /* Auxiliary function */
    int gcd(int m, int n) const;

private:
    /* Members */
    int nomerator;
    int denomerator;
};

/* Print function by overloading operator << */
std::ostream& operator<<(std::ostream& os, Rational& fraction);
