#include "Point.h"
#include<iostream>
#include<cmath>
using namespace std;

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

void Point::setX(double x) {
	this->x = x;
}

void Point::setY(double y) {
	this->y = y;
}

void Point::input() {
	cout << "Input x: "; cin >> x;
	cout << "Input y: "; cin >> y;
}

void Point::output() const {
	cout << "Output a point to the console in the form (x, y): (" << x << ", " << y << ")" << endl;
}

double Point::distanceAB(const Point& p) const {
	return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
}

double Point::distanceToO() const {
	return sqrt(pow(x,2)+pow(y,2));
}

bool Point::isEqual(const Point& p) const {
	return x == p.x && y == p.y;
}