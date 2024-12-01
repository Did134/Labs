#include <iostream>
#include <math.h>
#include "Fraction.h"
using std::cout;
using std::cin;

Fraction::Fraction()
{}

Fraction::Fraction(int numerator, int denominator) {
    setNumerator(numerator);
    setDenominator(denominator);
}

int Fraction::denominator() const
{
    return m_denominator;
}

int Fraction::numerator() const
{
    return m_numerator;
}

void Fraction::setNumerator(int numerator)
{
    m_numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    m_denominator = denominator;
    if (m_denominator == 0) {
        std::cerr << "Fraction::setDenominator: error: value is 0, won't assign.\n";
        m_numerator = 0;
        m_denominator = 1;
    }
}

void Fraction::input()
{
    cout << "Numerator = ";
    cin >> m_numerator;
    cout << "Denominator = ";
    cin >> m_denominator;
    if (m_denominator == 0) {
        cout << "Fraction::setDenominator: error: value is 0, won't assign.\n";
        m_numerator = 0;
        m_denominator = 1;
    }
}

void Fraction::output()
{
    cout << m_numerator << "/" << m_denominator;
}

int gcd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

void Fraction::reduce()
{
    int x;
    x = gcd(m_numerator, m_denominator);
    m_numerator /= x;
    m_denominator /= x;
    if (m_denominator < 0) {
        m_numerator *= -1;
        m_denominator *= -1;
    }
}

Fraction Fraction::operator+(Fraction const a) const
{
    Fraction c;
    c.setNumerator(m_numerator * a.m_denominator + a.m_numerator * m_denominator);
    c.setDenominator(m_denominator * a.m_denominator);
    c.reduce();
    return c;
}

Fraction Fraction::operator-(Fraction const a)const
{
    Fraction c;
    c.setNumerator(m_numerator * a.m_denominator - a.m_numerator * m_denominator);
    c.setDenominator(m_denominator * a.m_denominator);
    c.reduce();
    return c;
}

Fraction Fraction::operator*(Fraction const a)const
{
    Fraction c;
    c.setNumerator(m_numerator * a.m_numerator);
    c.setDenominator(m_denominator * a.m_denominator);
    c.reduce();
    return c;
}

Fraction Fraction::operator/(Fraction const a)const
{
    Fraction c;
    c.setNumerator(m_numerator * a.m_denominator);
    c.setDenominator(m_denominator * a.m_numerator);
    c.reduce();
    return c;
}

bool Fraction::operator>(Fraction const a)const
{
    if ((m_numerator * a.m_denominator) > (a.m_numerator * m_denominator)) {
        return true;
    }
    return false;
}

bool Fraction::operator<(Fraction const a)const
{
    if ((m_numerator * a.m_denominator) < (a.m_numerator * m_denominator)) {
        return true;
    }
    return false;
}

bool Fraction::operator==(Fraction const a)const
{
    if ((m_numerator * a.m_denominator) == (a.m_numerator * m_denominator)) {
        return true;
    }
    return false;
}

bool Fraction::operator!=(Fraction const a)const
{
    return !operator==(a);
}

Fraction Fraction::operator^(int k)
{
    Fraction c;
    if (k > 0) {
        c.setNumerator(pow(m_numerator, k));
        c.setDenominator(pow(m_denominator, k));
    }
    if (k < 0) {
        c.setDenominator(pow(m_numerator, -k));
        c.setNumerator(pow(m_denominator, -k));
    }
    if (k == 0) {
        c.setDenominator(1);
        c.setNumerator(1);
    }
    c.reduce();
    return c;
}

int Fraction::wholePart()
{
    int wholePart;
    if (m_numerator > m_denominator)
    {
        wholePart = m_numerator / m_denominator;
    }
    else {
        wholePart = 0;
    }
    return wholePart;
}