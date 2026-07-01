#pragma once

#include <iostream>
#include <string>
using namespace std;

class BigInteger {
private:
    int digits[100];
    int len;
    static BigInteger maxBI;
    void normalize();
    int compare(const BigInteger& b) const;
    void updateMax();
public:
    BigInteger();
    BigInteger(long long n);
    BigInteger(int digit, int count);
    void Print() const;
    BigInteger Subtract(const BigInteger& b) const;
    static BigInteger Subtract(BigInteger a, const BigInteger& b);
    BigInteger Add(long long n) const;
    static BigInteger GetMaxBigInteger();
};