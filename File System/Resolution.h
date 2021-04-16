#pragma once
#include <iostream>

using namespace std;

//Primitive class for modeling resolution of image files
class Resolution
{
	int width, height;
public:
	//Constructors
	Resolution() : width(0), height(0) {}
	Resolution(int width, int height) : width(width), height(height) {}

	//Setters
	void setWidth(int width);
	void setHeight(int height);
	void setResolution(int width, int height);

	//Getters
	int getWidth() const;
	int getHeight() const;

	//Other
	void printResolution() const;

	friend ostream& operator<<(ostream& out, const Resolution& obj);
	friend istream& operator>>(istream& in, Resolution& obj);
};