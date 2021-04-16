#include "Resolution.h"

void Resolution::setWidth(int width)
{
	this->width = width;
}

void Resolution::setHeight(int height)
{
	this->height = height;
}

void Resolution::setResolution(int width, int height)
{
	this->width = width;
	this->height = height;
}

int Resolution::getWidth() const
{
	return width;
}

int Resolution::getHeight() const
{
	return height;
}

void Resolution::printResolution() const
{
	cout << width << '/' << height;
}

ostream& operator<<(ostream& out, const Resolution& obj)
{
	out << obj.width << '/' << obj.height;
	return out;
}

istream& operator>>(istream& in, Resolution& obj)
{
	cout << "Enter width: ";
	in >> obj.width;
	cout << "Enter height: ";
	in >> obj.height;
	return in;
}
