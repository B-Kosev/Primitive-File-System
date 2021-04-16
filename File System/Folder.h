#pragma once

#include "Date.h"
#include "File.h"
#include "ImageFile.h"
#include "MusicFile.h"
#include "InterfaceFile.h"
#include <vector>
#include <string>

//Extends InterfaceFile, models Folders
class Folder : public InterfaceFile
{
	vector<InterfaceFile*> arr; //can hold folders, files, music files, image files
public:
	//Constructors
	Folder() : arr() {}
	Folder(string name, Date dateCreated);
	Folder(const Folder& obj);
	Folder& operator=(const Folder& obj);

	//Setters
	void setName(string name);
	void setDateCreated(Date dateCreated);
	void setFolder(string name, Date dateCreated);

	//Getters
	string getName() const;
	Date getDateCreated() const;
	vector<InterfaceFile*> getArr() const;

	//Other
	void print() const; //override

	void createFile(); //create file from console
	void createFolder(); //create folder from console

	void create(InterfaceFile* fileptr); //create file in folder using existing file instance

	string search(string nameToSearch); //search for file name

	void createWithPath(string path, InterfaceFile* file); //create file with specific path using existing file instance

	void createFileWithPath(string path); //create file with specific path from console
	void createFolderWithPath(string path); //create folder with specific path from console
};