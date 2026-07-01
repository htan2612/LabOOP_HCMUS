#pragma once
#include"Point.h"
class Rectangle
{
private:
	Point vertices[4];
public:
	Rectangle();
	Rectangle(Point v0, Point v1, Point v2, Point v3);
	void input();
	void output() const;
	bool isValid() const;
	double getLength() const;
	double getWidth() const;
	double perimeter() const;
	double area() const;
};