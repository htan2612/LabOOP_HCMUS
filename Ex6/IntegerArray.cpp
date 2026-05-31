#include "IntegerArray.h"

IntegerArray::IntegerArray() : data(nullptr), size(0) {}

IntegerArray::IntegerArray(int size) : size(size) {
    data = new int[size]();
}

IntegerArray::IntegerArray(const IntegerArray& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

IntegerArray& IntegerArray::operator=(const IntegerArray& other) {
    if (this == &other) return *this;
    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

IntegerArray::~IntegerArray() {
    delete[] data;
}

void IntegerArray::input() {
    do {
        cout << "Input size (> 0): "; cin >> size;
    }
    while (size <= 0);
    delete[] data;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Element [" << i << "]: "; cin >> data[i];
    }
}

void IntegerArray::output() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

int IntegerArray::max() const {
    int m = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > m) m = data[i];
    }
    return m;
}

int IntegerArray::min() const {
    int m = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] < m) m = data[i];
    }
    return m;
}

long long IntegerArray::sum() const {
    long long s = 0;
    for (int i = 0; i < size; i++) {
        s += data[i];
    }
    return s;
}

double IntegerArray::average() const {
    return (double)sum() / size;
}

int IntegerArray::countEven() const {
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] % 2 == 0) c++;
    }
    return c;
}

int IntegerArray::countOdd() const {
    int c = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] % 2 != 0) c++;
    }
    return c;
}

void IntegerArray::sortAscending() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (data[i] > data[j]) {
                int tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }
}