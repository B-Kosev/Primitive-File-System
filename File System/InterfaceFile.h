#pragma once

#include "Date.h"
#include <string>

class InterfaceFile
{
protected:
	string name;
	Date dateCreated;
public:
	virtual void print() const = 0;
};