#include <iostream>
#include "Date.h"
using namespace std;

int main() {
    Date a, b;
    cout << "Date A" << endl;
    a.input();
    cout << "Output: "; a.output();
    cout << "Output Full: "; a.outputFull();
    cout << "Valid: " << (a.isValid() ? "Yes" : "No") << endl;
    cout << "Leap year: " << (a.isLeap() ? "Yes" : "No") << endl;
    cout << "Next date: "; a.nextDate().output();
    cout << "Prev date: "; a.prevDate().output();
    cout << "Date B" << endl;
    b.input();
    int cmp = a.compare(b);
    if (cmp < 0) cout << "A is earlier than B" << endl;
    else if (cmp > 0) cout << "A is later than B" << endl;
    else cout << "A and B are equal" << endl;
    return 0;
}