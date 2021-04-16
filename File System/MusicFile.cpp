#include "MusicFile.h"

Extension MusicFile::verify(Extension ext) const
{
	if (ext != mp3 && ext != flac) {
		cout << "Invalid extension. Setting extension to mp3.\n";
		ext = mp3;
	}
	return ext;
}

MusicFile::MusicFile(Date dateCreated, double sizeMB, Extension ext, string artist, string song, int releaseYear) : File(artist + " - " + song, dateCreated, sizeMB, verify(ext))
{
	this->artist = artist;
	this->song = song;
	this->releaseYear = releaseYear;
}

void MusicFile::setArtist(string artist)
{
	this->artist = artist;
	setName(this->artist + " - " + this->song);
}

void MusicFile::setSong(string song)
{
	this->song = song;
	setName(this->artist + " - " + this->song);
}

void MusicFile::setReleaseYear(int releaseYear)
{
	this->releaseYear = releaseYear;
}

void MusicFile::setMusicFile(Date dateCreated, double sizeMB, Extension ext, string artist, string song, int releaseYear)
{
	setFile(artist + " - " + song, dateCreated, sizeMB, verify(ext));
	this->artist = artist;
	this->song = song;
	this->releaseYear = releaseYear;
}

string MusicFile::getName() const
{
	return name;
}

string MusicFile::getArtist() const
{
	return artist;
}

string MusicFile::getSong() const
{
	return song;
}

int MusicFile::getReleaseYear() const
{
	return releaseYear;
}

void MusicFile::readMusicFile()
{
	cout << "Enter date of creation: ";
	cin >> dateCreated;
	cout << "Enter size in MB: ";
	cin >> sizeMB;

CHOICE:
	int n = 0;
	cout << "What is the extension?\n1) mp3\n2) flac\n";
	cin >> n;
	if (n != 1 && n != 2)
	{
		cout << "Invalid input.\n";
		goto CHOICE;
	}
	if (n == 1) ext = mp3;
	else ext = flac;

	cout << "Enter name of artist: ";
	cin >> artist;
	cout << "Enter name of song: ";
	cin >> song;
	cout << "Enter release year: ";
	cin >> releaseYear;

	setName(artist + " - " + song);
}

void MusicFile::print() const
{
	File::print();
	cout << "Artist: " << artist << "\nSong: " << song << "\nYear of release: " << releaseYear << endl;
}
