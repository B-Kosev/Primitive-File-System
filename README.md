# Primitive File System
## Primitive File System Homework project for OOP, Year 1, Software Engineering at Sofia University

***

Your task is to write primitive file system. In our file system we have the following types of objects:

**File:**
- Name
- Date (Hour, Day, Month and Year) of creation
- Size in MB
- Extension

**Image File - Extends File with the following data:**
- Name of the device, which captured the file
- Resolution (width/height)
- Extension - 'jpg' or 'png'

**Music File - Extends file with the following data:**
- Name of the artist
- Name of the song
- Release year of the song
- The name of the file is generated with the following pattern: '<name-of-the-artist> - <name-of-the-song>'
- Extension - 'mp3' or 'flac'

**Folder:**
- Name
- Date of creation
- The folder can contain other files and folders

***

Create class FileSystem, which has one main folder, containing all other files and folders.
The user should be able to create files in specific folder - pass the name of the desired folder as parameter
The user should be able to search for files

