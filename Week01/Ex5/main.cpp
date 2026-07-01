#include <iostream>
#include "Student.h"
using namespace std;

int main() {
    Student s;
    s.input();
    cout << "Student Information" << endl;
    s.output();
    cout << "DOB valid: " << (s.isDobValid() ? "Yes" : "No") << endl;
    return 0;
}