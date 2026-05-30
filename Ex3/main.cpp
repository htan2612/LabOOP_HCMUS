#include <iostream>
#include "Rectangle.h"
using namespace std;

int main() {
    Rectangle r;
    r.input();
    cout << "Rectangle" << endl;
    r.output();
    if (r.isValid()) {
        cout << "Valid: Yes" << endl;
        cout << "Length: " << r.getLength() << endl;
        cout << "Width: " << r.getWidth() << endl;
        cout << "Perimeter: " << r.perimeter() << endl;
        cout << "Area: " << r.area() << endl;
    }
    else {
        cout << "Valid: No (not a rectangle)" << endl;
    }
    return 0;
}