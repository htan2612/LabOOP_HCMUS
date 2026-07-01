#include "Fraction.h"
#include<iostream>
using namespace std;

Fraction::Fraction() : numerator(0), denominator(1) {}
Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {}

void Fraction::input() {
	cout << "Input numerator: ";
	cin >> this->numerator;
	do {
		cout << "Input denominator (#0): ";
		cin >> this->denominator; if (denominator == 0) cout << "Invalid denominator value." << endl;
	} while (this->denominator == 0);
}

void Fraction::outputFraction() const {
	cout << "Output a fraction in the form numerator / denominator: " << this->numerator << "/" << this->denominator << endl;
}

void Fraction::outputDecimal() const {
	cout << "Output a fraction as a decimal number : " << (double)this->numerator / (double)this->denominator << endl;
}

bool Fraction::isValid() const {
	return denominator != 0;
}

int Fraction::myAbs(int x) {
	return (x < 0) ? -x : x;
}

int Fraction::gcd(int a, int b) {
	a = myAbs(a); b = myAbs(b);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void Fraction::reduce() {
	if (!isValid()) return;
	int g = gcd(myAbs(numerator), myAbs(denominator));
	numerator /= g;
	denominator /= g;
	if (denominator < 0) {
		numerator = -numerator;
		denominator = -denominator;
	}
}

void Fraction::outputFractionSimplest() {
	Fraction tmp(numerator, denominator);
	tmp.reduce();
	cout << tmp.numerator << "/" << tmp.denominator << endl;
}

Fraction Fraction::add(Fraction p) const {
	Fraction tmp(numerator * p.denominator + denominator * p.numerator, denominator * p.denominator);
	tmp.reduce();
	return tmp;
}

Fraction Fraction::subtract(Fraction p) const {
	Fraction tmp(numerator * p.denominator - denominator * p.numerator, denominator * p.denominator);
	tmp.reduce();
	return tmp;
}

Fraction Fraction::multiply(Fraction p) const {
	Fraction tmp(numerator * p.numerator, denominator * p.denominator);
	tmp.reduce();
	return tmp;
}

Fraction Fraction::divide(Fraction p) const {
	if (p.numerator == 0) {
		cout << "Cannot divide by zero fraction" << endl;
		return Fraction(0, 1);
	}
	Fraction tmp(numerator * p.denominator, denominator * p.numerator);
	tmp.reduce();
	return tmp;
}