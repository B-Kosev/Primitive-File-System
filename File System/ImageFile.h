#pragma once

#include "File.h"
#include "Resolution.h"

using namespace std;

//Extends File
class ImageFile : public File
{
	string device;
	Resolution res;

	//verify that the extension is correct for image file
	Extension verify(Extension ext) const;
public:
	//Constructors
	ImageFile() : device(), res() {}
	ImageFile(string name, Date dateCreated, double sizeMB, Extension ext, string device, Resolution res);

	//Setters
	void setDevice(string device);
	void setResolution(Resolution res);
	void setImageFile(string name, Date dateCreated, double sizeMB, Extension ext, string device, Resolution res);

	//Getters
	string getName() const;
	string getDevice() const;
	Resolution getResolution() const;

	//Other
	void readImageFile(); //read from console
	void print() const; //override
};