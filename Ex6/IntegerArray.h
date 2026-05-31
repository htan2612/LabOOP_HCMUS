#pragma once
#include <iostream>
using namespace std;

class IntegerArray {
private:
    int* data;
    int size;
public:
    IntegerArray();
    IntegerArray(int size);
    IntegerArray(const IntegerArray& other);
    IntegerArray& operator=(const IntegerArray& other);
    ~IntegerArray();
    void input();
    void output() const;
    int max() const;
    int min() const;
    long long sum() const;
    double average() const;
    int countEven() const;
    int countOdd() const;
    void sortAscending();
};