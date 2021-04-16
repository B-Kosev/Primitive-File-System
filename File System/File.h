#pragma once
#include "Date.h"
#include "InterfaceFile.h"

#include <string>

//Predefined extensions (the files are not real files, just class objects)
enum Extension {exe,rar,zip,mp4,avi,bat,png,jpg,mp3,flac};

//Base File class
class File : public InterfaceFile
{
protected:
	double sizeMB;
	Extension ext;
public:
	//Constructors
	File();
	File(string name, Date dateCreated, double sizeMB, Extension ext);

	//Setters
	void setName(string name);
	void setDateCreated(Date dateCreated);
	void setSizeMB(double sizeMB);
	void setExtension(Extension ext);
	void setFile(string name, Date dateCreated, double sizeMB, Extension ext);

	//Getters
	string getName() const;
	Date getDateCreated() const;
	double getSizeMB() const;
	Extension getExtension() const;

	//Other
	string getExtensionString() const;
	virtual void print() const; //override
	virtual void readFile(); //read file data from console


};
