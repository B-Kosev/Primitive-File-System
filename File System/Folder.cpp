#include "Folder.h"

Folder::Folder(string name, Date dateCreated)
{
	this->name = name;
	this->dateCreated = dateCreated;
}

Folder::Folder(const Folder& obj)
{
	this->name = obj.name;
	this->dateCreated = obj.dateCreated;
	for (int i = 0;i < obj.arr.size();i++)
	{
		this->arr.push_back(obj.arr[i]);
	}
}

Folder& Folder::operator=(const Folder& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->dateCreated = obj.dateCreated;
		for (int i = 0;i < obj.arr.size();i++)
		{
			this->arr.push_back(obj.arr[i]);
		}
	}
	return *this;
}

void Folder::setName(string name)
{
	this->name = name;
}

void Folder::setDateCreated(Date dateCreated)
{
	this->dateCreated = dateCreated;
}

void Folder::setFolder(string name, Date dateCreated)
{
	this->name = name;
	this->dateCreated = dateCreated;
}

string Folder::getName() const
{
	return name;
}

Date Folder::getDateCreated() const
{
	return dateCreated;
}

vector<InterfaceFile*> Folder::getArr() const
{
	return arr;
}

void Folder::print() const
{
	cout << "Folder name: " << name << "\nFolder date of creation: " << dateCreated << "\nFolder contents: \n";
	cout << "-----------------------\n\n";

	for (int i = 0;i < arr.size();i++)
	{
		arr[i]->print();
		cout << endl;
	}
	cout << "End of " << name << "--\n\n";
}

//method for number input validation
int inputValidation(int input, int lowerBound, int upperBound)
{
	cin >> input;
	if (input >= lowerBound && input <= upperBound) return input;
	else cout << "Invalid input.\n";

	while (true)
	{
		cin >> input;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}
		if (input >= lowerBound && input <= upperBound) break;
		cout << "Invalid input.\n";
	}
	return input;
}

//create file from console
void Folder::createFile()
{
	string name;
	Date dateCreated;
	double sizeMB;
	Extension ext=exe; //uninitialized warning
	string device;
	Resolution res;
	string artist;
	string song;
	int releaseYear;

	cout << "What would you like to create?\n1) File\n2) Image File\n3) Music File\n\n";
	int n = 0;
	n=inputValidation(n, 1, 3);

	switch (n)
	{
		case 2:
		{
			cout << "Enter name: ";
			cin >> name;
			cout << "Entering date of creation...\n";
			cin >> dateCreated;
			cout << "Enter size in MB: ";
			cin >> sizeMB;

			cout << "What is the extension?\n1) jpg\n2) png\n";
			int k = 0;
			k=inputValidation(k, 1, 2);
			if (n == 1) ext = jpg;
			else ext = png;

			cout << "Enter name of device: ";
			cin >> device;
			cout << "Entering resolution...\n";
			cin >> res;

			arr.push_back(new ImageFile(name, dateCreated, sizeMB, ext, device, res));
			break;
		}
		case 3:
		{
			cout << "Entering date of creation...\n";
			cin >> dateCreated;
			cout << "Enter size in MB: ";
			cin >> sizeMB;

			cout << "What is the extension?\n1) mp3\n2) flac\n";
			int k = 0;
			k=inputValidation(k, 1, 2);
			if (k == 1) ext = mp3;
			else ext = flac;

			cout << "Enter name of artist: ";
			cin >> artist;
			cout << "Enter name of song: ";
			cin >> song;
			cout << "Enter release year: ";
			releaseYear = 0;
			releaseYear=inputValidation(releaseYear, 0, 2020);
			name = artist + " - " + song;

			arr.push_back(new MusicFile(dateCreated, sizeMB, ext, artist, song, releaseYear));
			break;
		}
		default:
		{
			cout << "Enter name: ";
			cin >> name;
			cout << "Entering date of creation...\n";
			cin >> dateCreated;
			cout << "Enter size in MB: ";
			cin >> sizeMB;

			cout << "What is the extension?\n1) exe\n2) rar\n3) zip\n4) mp4\n5) avi\n6) bat\n";
			int k= 0;
			k= inputValidation(k, 1, 6);
			switch (k) //exe,rar,zip,mp4,avi,bat
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
			}

			arr.push_back(new File(name, dateCreated, sizeMB, ext));
			break;
		}
	}
	cout << endl;
}

//create file using existing file instance
void Folder::create(InterfaceFile* fileptr)
{
	arr.push_back(fileptr);
}

//create folder from console
void Folder::createFolder()
{
	string name;
	Date dateCreated;
	cout << "Enter folder name: ";
	cin >> name;
	cout << "Entering date of creation...\n";
	cin >> dateCreated;
	arr.push_back(new Folder(name,dateCreated));
	cout << endl;
}

//search for file name
string Folder::search(string nameToSearch)
{
	string path;

	//check current folder
	for (int i = 0;i < arr.size();i++)
	{
		if(nameToSearch==((File*)arr[i])->getName())
		{
			path = name + '/';
			return path;
		}
	}
	//check subfolders
	for (int i = 0;i < arr.size();i++)
	{
		//check if current item is folder
		if (dynamic_cast<Folder*>(arr[i]))
		{
			//check inside recursively
			path = ((Folder*)arr[i])->search(nameToSearch);
		}

		if (path != "" && path!="File not found.") //file found
		{
			path.insert(0, name + '/');
			return path;
		}
	}

	path = "File not found.";
	return path;
}

//create file with specific path using existing file instance
void Folder::createWithPath(string path, InterfaceFile* file)
{
	if (path[path.size() - 1] != '/') path.append("/"); //put '/' at the end for easier use

	string nextFolder;
	string destinationPath;

	if (path == "")
	{
		cout << "Invalid path.\n";
		return;
	}

	destinationPath = path.substr(path.find_first_of('/') + 1); //remove current folder from path
	nextFolder = destinationPath.substr(0, destinationPath.find_first_of('/')); //get the name for the next folder to enter in

	if (destinationPath == "") //if in destination folder
	{
		create(file);
		//cout << "File created successfully.\n";
		return;
	}
	else //enter in subfolder
	{
		for (int i = 0;i < arr.size();i++)
		{
			if (nextFolder == ((Folder*)arr[i])->getName())
			{
				//cout << "Entered in " << nextFolder << endl;
				((Folder*)arr[i])->createWithPath(destinationPath, file);
				break;
			}
		}
	}
	return;
}

//create file with specific path from console
void Folder::createFileWithPath(string path)
{
	if (path[path.size() - 1] != '/') path.append("/"); //put '/' at the end for easier use

	string nextFolder;
	string destinationPath;

	if (path == "")
	{
		cout << "Invalid path.\n";
		return;
	}

	destinationPath = path.substr(path.find_first_of('/') + 1); //remove current folder from path
	nextFolder = destinationPath.substr(0, destinationPath.find_first_of('/')); //get the name for the next folder to enter in

	if (destinationPath == "") //if in destination folder
	{
		createFile();
		cout << "File created successfully.\n";
		return;
	}
	else //enter in subfolder
	{
		for (int i = 0;i < arr.size();i++)
		{
			if (nextFolder == ((Folder*)arr[i])->getName())
			{
				//cout << "Entered in " << nextFolder << endl;
				((Folder*)arr[i])->createFileWithPath(destinationPath);
				break;
			}
		}
	}
	return;
}

//create folder with specific path 
void Folder::createFolderWithPath(string path)
{
	if (path[path.size() - 1] != '/') path.append("/"); //put '/' at the end for easier use

	string nextFolder;
	string destinationPath;

	if (path == "")
	{
		cout << "Invalid path.\n";
		return;
	}

	destinationPath = path.substr(path.find_first_of('/') + 1); //remove current folder from path
	nextFolder = destinationPath.substr(0, destinationPath.find_first_of('/')); //get the name for the next folder to enter in

	if (destinationPath == "") //if in destination folder
	{
		createFolder();
		cout << "Folder created successfully.\n";
		return;
	}
	else //enter in subfolder
	{
		for (int i = 0;i < arr.size();i++)
		{
			if (nextFolder == ((Folder*)arr[i])->getName())
			{
				//cout << "Entered in " << nextFolder << endl;
				((Folder*)arr[i])->createFolderWithPath(destinationPath);
				break;
			}
		}
	}
	return;
}
