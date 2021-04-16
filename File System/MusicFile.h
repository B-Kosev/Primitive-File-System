#pragma once

#include "File.h"

//Extends File
class MusicFile : public File
{
	string artist;
	string song;
	int releaseYear;

	//verify that the extension is correct for music file
	Extension verify(Extension ext) const;
public:
	//Constructors
	MusicFile() : artist(), song(), releaseYear(0) {}
	MusicFile(Date dateCreated, double sizeMB, Extension ext, string artist, string song, int releaseYear);

	//Setters
	void setArtist(string artist);
	void setSong(string song);
	void setReleaseYear(int releaseYear);
	void setMusicFile(Date dateCreated, double sizeMB, Extension ext, string artist, string song, int releaseYear);

	//Getters
	string getName() const;
	string getArtist() const;
	string getSong() const;
	int getReleaseYear() const;

	//Other
	void readMusicFile(); //read from console
	void print() const; //override
};