/*
* Filename:		PrintManager.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#pragma once

#include "Album.h"

//------------------------------------------------------------------------------
//	A class that handles all the printing and formatting to the console.
//------------------------------------------------------------------------------

class PrintManager
{
private:

	PrintManager();

	// Used to formatting the output on console.
	static const int NR_WIDTH = 5;
	static const int TITLE_WIDTH = 48;
	static const int ARTIST_WIDTH = 32;
	static const int TIME_WIDTH = 16;



public:

	static void printColumnTitles();
	static 	void printAlbum(const Album &album);
	static void printSong(const Song &song, const int atIndex);
	static void printSongs(const std::vector<Song> &allSongs);
	static void printAlbumsByName(const std::vector<Album> &albums);
	static void printAlbumsByLength(const std::vector<Album> &albums);
	static void simplePrintAlbumsByName(const std::vector<Album> &albums);
	static void simplePrintAlbumsByLength(const std::vector<Album> &albums);

private:

	static void sortAlbumsByName(std::vector<Album> &albums);
	static void sortSongsInAlbum(Album &album);
	static void sortAlbumsByLength(std::vector<Album> &albums);
};