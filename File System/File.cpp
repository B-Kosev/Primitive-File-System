#include "File.h"

File::File()
{
	sizeMB = 0.0;
	ext = exe;
}

File::File(string name, Date dateCreated, double sizeMB, Extension ext)
{
	this->name = name;
	this->dateCreated = dateCreated;
	this->sizeMB = sizeMB;
	this->ext = ext;
}

void File::setName(string name)
{
	this->name = name;
}

void File::setDateCreated(Date dateCreated)
{
	this->dateCreated = dateCreated;
}

void File::setSizeMB(double sizeMB)
{
	this->sizeMB = sizeMB;
}

void File::setExtension(Extension ext)
{
	this->ext = ext;
}

void File::setFile(string name, Date dateCreated, double sizeMB,Extension ext)
{
	this->name = name;
	this->dateCreated = dateCreated;
	this->sizeMB = sizeMB;
	this->ext = ext;
}

string File::getName() const
{
	return name;
}

Date File::getDateCreated() const
{
	return dateCreated;
}

double File::getSizeMB() const
{
	return sizeMB;
}

Extension File::getExtension() const
{
	return ext;
}



string File::getExtensionString() const
{
	string extString;
	switch (ext)
	{
	case exe:
		extString = ".exe";
		break;
	case rar:
		extString = ".rar";
		break;
	case zip:
		extString = ".zip";
		break;
	case mp4:
		extString = ".mp4";
		break;
	case avi:
		extString = ".avi";
		break;
	case bat:
		extString = ".bat";
		break;
	case png:
		extString = ".png";
		break;
	case jpg:
		extString = ".jpg";
		break;
	case mp3:
		extString = ".mp3";
		break;
	case flac:
		extString = ".flac";
		break;
	default:
		extString = "ERROR 404 - EXTENSION NOT FOUND";
		break;
	}
	return extString;
}

void File::print() const
{
	cout << "Name: " << name << "\nDate created: " << dateCreated << "\nSize in MB: " << sizeMB << "\nExtension: " << getExtensionString() << endl;
}

void File::readFile()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter date of creation: ";
	cin >> dateCreated;
	cout << "Enter size in MB: ";
	cin >> sizeMB;

CHOICE:
	int n = 0;
	cout << "What is the extension?\n1) exe\n2) rar\n3) zip\n4) mp4\n5) avi\n6) bat";
	cin >> n;
	if (n<1 || n>6)
	{
		cout << "Invalid input.\n";
		goto CHOICE;
	}

	switch (n)
	{
	case 1:
		ext = exe;
		break;
	case 2:
		ext = rar;
		break;
	case 3:
		ext = zip;
		break;
	case 4:
		ext = mp4;
		break;
	case 5:
		ext = avi;
		break;
	case 6:
		ext = bat;
		break;
	default:
		ext = exe;
		break;
	}
}
