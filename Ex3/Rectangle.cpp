#include "Rectangle.h"
#include<iostream>
using namespace std;

Rectangle::Rectangle() {}
Rectangle::Rectangle(Point v0, Point v1, Point v2, Point v3) {
    vertices[0] = v0; vertices[1] = v1; vertices[2] = v2; vertices[3] = v3;
}

void Rectangle::input() {
    cout << "Input 4 vertices (clockwise, top-left first):" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Vertex " << i + 1 << ":" << endl;
        vertices[i].input();
    }
}

void Rectangle::output() const {
    for (int i = 0; i < 4; i++) {
        cout << "Vertex " << i + 1 << ": ";
        vertices[i].output();
    }
}

bool Rectangle::isValid() const {
    double d01 = vertices[0].distanceAB(vertices[1]);
    double d12 = vertices[1].distanceAB(vertices[2]);
    double d23 = vertices[2].distanceAB(vertices[3]);
    double d30 = vertices[3].distanceAB(vertices[0]);
    if (fabs(d01 - d23) > 1e-9 || fabs(d12 - d30) > 1e-9) return false;
    double ax = vertices[1].getX() - vertices[0].getX();
    double ay = vertices[1].getY() - vertices[0].getY();
    double bx = vertices[3].getX() - vertices[0].getX();
    double by = vertices[3].getY() - vertices[0].getY();
    return fabs(ax * bx + ay * by) < 1e-9;
}

double Rectangle::getLength() const {
    return vertices[0].distanceAB(vertices[1]);
}

double Rectangle::getWidth() const {
    return vertices[1].distanceAB(vertices[2]);
}

double Rectangle::perimeter() const {
    if (!isValid()) return 0;
    return 2 * (getLength() + getWidth());
}

double Rectangle::area() const {
    if (!isValid()) return 0;
    return getLength() * getWidth();
}