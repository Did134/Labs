#pragma once

class Fraction
{
public:
	Fraction();
	Fraction(int, int);
	int numerator() const;
	int denominator() const;
	void input();
	void output();
	void setNumerator(int);
	void setDenominator(int);
	Fraction operator+(Fraction const a) const;
	Fraction operator-(Fraction const a) const;
	Fraction operator*(Fraction const a) const;
	Fraction operator/(Fraction const a) const;
	bool operator>(Fraction const a)const;
	bool operator<(Fraction const a)const;
	bool operator==(Fraction const a)const;
	bool operator!=(Fraction const a)const;
	Fraction operator^(int k);
	void reduce();
	int wholePart();

private:
	int m_numerator = 1;
	int m_denominator = 1;
};
