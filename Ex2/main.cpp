#include<iostream>
#include"Point.h"
using namespace std;

int main() {
	Point a, b;
	cout << "Point A" << endl;
	a.input();
	cout << "Point A: "; a.output();
	cout << "Distance from A to O: "; a.distanceToO();
	cout << "Point B" << endl;
	b.input();
	cout << "Point B: "; b.output();
	cout << "Distance from B to O: ";b.distanceToO();
	cout << "Distance A to B: " << a.distanceAB(b) << endl;
	cout << "A and B are " << (a.isEqual(b) ? "identical" : "different") << endl;
	return 0;
}