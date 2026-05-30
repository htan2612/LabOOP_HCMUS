#include<iostream>
#include"Fraction.h"
using namespace std;

int main() {
    Fraction a, b;
    cout << "Fraction A" << endl;
    a.input();
    cout << "Fraction: "; a.outputFraction();
    cout << "Decimal: "; a.outputDecimal();
    cout << "Simplified: "; a.outputFractionSimplest();
    cout << "Fraction B" << endl;
    b.input();
    cout << "Fraction: "; b.outputFraction();
    cout << "Decimal: "; b.outputDecimal();
    cout << "Simplified: "; b.outputFractionSimplest();
    cout << "Operations"<< endl;
    cout << "A + B = "; a.add(b).outputFraction();
    cout << "A - B = "; a.subtract(b).outputFraction();
    cout << "A * B = "; a.multiply(b).outputFraction();
    cout << "A / B = "; a.divide(b).outputFraction();
    return 0;
}
