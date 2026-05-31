#include <iostream>
#include "IntegerArray.h"
using namespace std;

int main() {
    IntegerArray arr;
    arr.input();
    cout << "Array: "; 
    arr.output();
    cout << "Max: " << arr.max() << endl;
    cout << "Min: " << arr.min() << endl;
    cout << "Sum: " << arr.sum() << endl;
    cout << "Average: " << arr.average() << endl;
    cout << "Even: " << arr.countEven() << endl;
    cout << "Odd: " << arr.countOdd() << endl;
    arr.sortAscending();
    cout << "Sorted: "; arr.output();
    return 0;
}