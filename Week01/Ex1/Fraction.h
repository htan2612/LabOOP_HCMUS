#pragma once
#include<iostream>
class Fraction
{
// thuoc tinh
private:
	int numerator, denominator;
	int gcd(int a, int b); // chi can goi ben trong lop phan so
	int myAbs(int x);
// method:
public:
	Fraction();
	Fraction(int num, int den);
	void input();
	void outputFraction() const;
	void outputDecimal() const;
	bool isValid() const;
	void reduce();
	void outputFractionSimplest();
	Fraction add(Fraction p) const;
	Fraction subtract(Fraction p) const;
	Fraction multiply(Fraction p) const;
	Fraction divide(Fraction p) const;
};

