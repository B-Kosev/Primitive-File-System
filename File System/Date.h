#pragma once
#include <iostream>

using namespace std;

//Primitive class for modeling Date object (date of creation)

class Date
{
	int hour, minute, day, month, year;
public:
	//Constructors
	Date();
	Date(int hour, int minute, int day, int month, int year);

	//Setters
	void setHour(int hour);
	void setMinute(int minute);
	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);
	void setDate(int hour, int minute, int day, int month, int year);

	//Getters
	int getHour() const;
	int getMinute() const;
	int getDay() const;
	int getMonth() const;
	int getYear() const;

	//Other
	void printDate() const;

	friend ostream& operator<<(ostream& out, const Date& obj);
	friend istream& operator>>(istream& in, Date& obj);
};