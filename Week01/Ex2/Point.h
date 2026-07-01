#pragma once
#include<iostream>
class Point
{
private:
	double x;
	double y;
public:
	Point();
	Point(double x, double y);
	double getX() const;
	double getY() const;
	void setX(double x);
	void setY(double y);
	void input();
	void output() const;
	double distanceAB(const Point& p) const;
	double distanceToO() const;
	bool isEqual(const Point& p) const;
};

