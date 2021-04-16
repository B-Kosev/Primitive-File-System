#include <iostream>

#include "File.h"
#include "ImageFile.h"
#include "MusicFile.h"
#include "Folder.h"
#include "FileSystem.h"
#include "InterfaceFile.h"

using namespace std;

int main()
{
	//creating sample file instances
	File file;
	file.setFile("FileInstance1", { 12,45,1,4,2000 }, 190,exe);

	ImageFile img;
	img.setImageFile("Image1", {10,10, 5,4,2020 }, 50, jpg, "Redmi Note 7", { 1920,1080 });

	ImageFile img2("Image2", { 1,1,1,1,1000 }, 49, png, "Redmi Note 7", { 1920,1080 });

	MusicFile song1;
	song1.setMusicFile({ 0,0,1,1,2020 }, 20, mp3, "Kose Bose", "MusicFile1", 2020);
	
	MusicFile song2({ 5,5,5,5,2050 }, 20, flac, "Kose Bose", "MusicFile2", 2050);

	//creating sample folders with intuitive names for better testing
	Folder folder("main -> new fold3r", {23,59,15,5,2020});
	Folder folder2("main -> new fold3r -> new fold3r1", { 23,59,15,5,2020 });
	Folder folder3("main -> new fold3r -> new fold3r2", { 23,59,15,5,2020 });

	FileSystem pc;
	
	//adding the existing file instances to the file system
	pc.getMainFolder().create(&song1);
	pc.getMainFolder().create(&song2);
	pc.getMainFolder().create(&folder);
	pc.getMainFolder().create(&img2);
	pc.getMainFolder().create(&img);

	((Folder*)pc.getMainFolder().getArr()[2])->create(&folder2);
	((Folder*)pc.getMainFolder().getArr()[2])->create(&folder3);

	//pc.getMainFolder().print();
	//cout<<pc.getMainFolder().search("RandomFile");

	pc.getMainFolder().createWithPath("Main Folder/main -> new fold3r/main -> new fold3r -> new fold3r2", &file);
	//pc.getMainFolder().createFile();

	//cout << pc.getMainFolder().search("FileInstance1");
	cout << endl;
	pc.getMainFolder().print();
	return 0;
}