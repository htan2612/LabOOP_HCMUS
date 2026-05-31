#include "Date.h"
using namespace std;

Date::Date() : day(1), month(1), year(2000) {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}

int Date::getDay() const {
	return day;
}

int Date::getMonth() const {
	return month;
}

int Date::getYear() const {
	return year;
}

void Date::setDay(int d) {
	this->day = day;
}

void Date::setMonth(int m) {
	this->month = month;
}

void Date::setYear(int y) {
	this->year = year;
}

void Date::input() {
	cout << "Input date: "; cin >> day;
	cout << "Input month: "; cin >> month;
	cout << "Input year: "; cin >> year;
}

void Date::output() const {
	cout << "Output a date in the form day / month / year: " << day << " / " << month << " / " << year << endl;
}

void Date::outputFull() const {
	const string months[] = { "January","February","March","April","May","June", "July","August","September","October","November","December" };
	cout << months[month - 1] << " " << day << ", " << year << endl;
}

bool Date::isLeap() const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Date::maxDaysInMonth() const {
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (month == 2 && isLeap()) return 29;
	return days[month - 1];
}

bool Date::isValid() const {
	if (month < 1 || month>12) return false;
	if (day<1 || day>maxDaysInMonth()) return false;
	return true;
}

Date Date::nextDate() const {
	Date next(day + 1, month, year);
	if (next.day > maxDaysInMonth()) {
		next.day = 1;
		next.month++;
		if (next.month > 12) { next.month = 1; next.year++; }
	}
	return next;
}

Date Date::prevDate() const {
	Date prev(day - 1, month, year);
	if (prev.day < 1) {
		prev.month--;
		if (prev.month < 1) { prev.month = 12; prev.year--; }
		prev.day = Date(1, prev.month, prev.year).maxDaysInMonth();
	}
	return prev;
}

int Date::compare(const Date& d) const {
	if (year != d.year) return year < d.year ? -1 : 1;
	if (month != d.month) return month < d.month ? -1 : 1;
	if (day != d.day) return day < d.day ? -1 : 1;
}