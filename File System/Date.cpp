#include "Date.h"
#include <iomanip>

Date::Date()
{
	hour = 0;
	minute = 0;
	day = 1;
	month = 1;
	year = 2020;
}

Date::Date(int hour, int minute, int day, int month, int year)
{
	this->hour = hour;
	this->minute = minute;
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setHour(int hour)
{
	this->hour = hour;
}

void Date::setMinute(int minute)
{
	this->minute = minute;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

void Date::setDate(int hour, int minute, int day, int month, int year)
{
	this->hour = hour;
	this->minute = minute;
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getHour() const
{
	return hour;
}

int Date::getMinute() const
{
	return minute;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::printDate() const
{
	cout << setw(2) << setfill('0') << hour;
	cout << ':';
	cout << setw(2) << setfill('0') << minute;
	cout << ", ";
	cout << setw(2) << setfill('0') << day;
	cout << '.';
	cout << setw(2) << setfill('0') << month;
	cout << '.';
	cout << setw(2) << setfill('0') << year;
}

ostream& operator<<(ostream& out, const Date& obj)
{
	out << setw(2) << setfill('0') << obj.hour;
	out << ':';
	out << setw(2) << setfill('0') << obj.minute;
	out << ", ";
	out << setw(2) << setfill('0') << obj.day;
	out << '.';
	out << setw(2) << setfill('0') << obj.month;
	out << '.';
	out << setw(2) << setfill('0') << obj.year;
	return out;
}

istream& operator>>(istream& in, Date& obj)
{
	cout << "Enter hour: ";
	in >> obj.hour;
	cout << "Enter minute: ";
	in >> obj.minute;
	cout << "Enter day: ";
	in >> obj.day;
	cout << "Enter month: ";
	in >> obj.month;
	cout << "Enter year: ";
	in>> obj.year;
	return in;
}
