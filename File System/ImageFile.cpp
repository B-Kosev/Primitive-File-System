#include "ImageFile.h"

Extension ImageFile::verify(Extension ext) const
{
	if (ext != png && ext != jpg) {
		cout << "Invalid extension. Setting extension to jpg.\n";
		ext = jpg;
	}
	return ext;
}

ImageFile::ImageFile(string name, Date dateCreated, double sizeMB, Extension ext, string device, Resolution res) : File(name, dateCreated, sizeMB, verify(ext))
{
	this->device = device;
	this->res = res;
}

void ImageFile::setDevice(string device)
{
	this->device = device;
}

void ImageFile::setResolution(Resolution res)
{
	this->res = res;
}

void ImageFile::setImageFile(string name, Date dateCreated, double sizeMB, Extension ext, string device, Resolution res)
{
	setFile(name, dateCreated, sizeMB, verify(ext));
	this->device = device;
	this->res = res;
}

void ImageFile::readImageFile()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter date of creation: ";
	cin >> dateCreated;
	cout << "Enter size in MB: ";
	cin >> sizeMB;

CHOICE:
	int n = 0;
	cout << "What is the extension?\n1) jpg\n2) png\n";
	cin >> n;
	if (n != 1 && n != 2)
	{
		cout << "Invalid input.\n";
		goto CHOICE;
	}
	if (n == 1) ext = jpg;
	else ext = png;

	cout << "Enter name of device: ";
	cin >> device;
	cout << "Enter resolution: ";
	cin >> res;
}

string ImageFile::getName() const
{
	return name;
}

string ImageFile::getDevice() const
{
	return device;
}

Resolution ImageFile::getResolution() const
{
	return res;
}

void ImageFile::print() const
{
	File::print();
	cout << "Device captured on: " << device << "\nResolution: " << res << endl;
}
