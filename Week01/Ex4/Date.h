#pragma once
#include<iostream>
#include<string>
class Date
{
private:
	int day, month, year;
public:
	Date();
	Date(int d, int m, int y);
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	void setDay(int d);
	void setMonth(int m);
	void setYear(int y);
	void input();
	void output() const;
	void outputFull() const;
	bool isLeap() const;
	int maxDaysInMonth() const;
	bool isValid() const;
	Date nextDate() const;
	Date prevDate() const;
	int compare(const Date& d) const;
};