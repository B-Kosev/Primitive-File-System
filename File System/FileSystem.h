#pragma once

#include "Folder.h"

//File System with main folder
class FileSystem
{
	Folder mainFolder;
public:
	FileSystem() : mainFolder("Main Folder", { 0,0,1,1,2020 }) {}

	Folder& getMainFolder() { return mainFolder; };
};