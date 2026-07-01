#include "BigInteger.h"

BigInteger BigInteger::maxBI;

void BigInteger::normalize() {
    while (len > 1 && digits[len - 1] == 0) {
        len--;
    }
}

int BigInteger::compare(const BigInteger& b) const {
    if (len != b.len) {
        return (len > b.len) ? 1 : -1;
    }
    for (int i = len - 1; i >= 0; i--) {
        if (digits[i] != b.digits[i]) {
            return (digits[i] > b.digits[i]) ? 1 : -1;
        }
    }
    return 0;
}

void BigInteger::updateMax() {
    if (this->compare(maxBI) == 1) {
        maxBI = *this;
    }
}

BigInteger::BigInteger() {
    len = 1;
    for (int i = 0; i < 100; i++) digits[i] = 0;
}

BigInteger::BigInteger(long long n) {
    for (int i = 0; i < 100; i++) digits[i] = 0;
    if (n <= 0) {
        len = 1;
    } else {
        len = 0;
        while (n > 0) {
            digits[len++] = n % 10;
            n /= 10;
        }
    }
    updateMax();
}

BigInteger::BigInteger(int digit, int count) {
    for (int i = 0; i < 100; i++) digits[i] = 0;
    len = (count <= 0) ? 1 : count;
    for (int i = 0; i < len; i++) {
        digits[i] = digit;
    }
    normalize();
    updateMax();
}

void BigInteger::Print() const {
    for (int i = len - 1; i >= 0; i--) {
        cout << digits[i];
    }
    cout << endl;
}

BigInteger BigInteger::Subtract(const BigInteger& b) const {
    if (this->compare(b) == -1) {
        return BigInteger(0);
    }

    BigInteger result;
    result.len = len;
    int borrow = 0;

    for (int i = 0; i < len; i++) {
        int diff = digits[i] - b.digits[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.digits[i] = diff;
    }

    result.normalize();
    result.updateMax();
    return result;
}

BigInteger BigInteger::Subtract(BigInteger a, const BigInteger& b) {
    return a.Subtract(b);
}

BigInteger BigInteger::Add(long long n) const {
    BigInteger result;
    int i = 0;
    long long carry = n;

    while (i < len || carry > 0) {
        long long sum = carry;
        if (i < len) {
            sum += digits[i];
        }
        result.digits[i] = sum % 10;
        carry = sum / 10;
        i++;
    }
    result.len = i;
    result.normalize();
    result.updateMax();
    return result;
}

BigInteger BigInteger::GetMaxBigInteger() {
    return maxBI;
}