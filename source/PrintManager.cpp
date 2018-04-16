/*
* Filename:		PrintManager.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/



#include "PrintManager.h"
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "Utils.h"

//------------------------------------------------------------------------------
//	Prints the columns title (No., Title, Arist, Length)
//------------------------------------------------------------------------------
void PrintManager::printColumnTitles()
{

	int totalWidth = NR_WIDTH + TITLE_WIDTH + ARTIST_WIDTH + TIME_WIDTH;

	std::cout << std::left;
	std::cout << std::setw(NR_WIDTH) << "No.";
	std::cout << std::setw(TITLE_WIDTH) << "Title";
	std::cout << std::setw(ARTIST_WIDTH) << "Artist";
	std::cout << std::setw(TIME_WIDTH);
	std::cout << std::right;
	std::cout << "Length" << std::endl;
	std::cout << std::setfill('=') << std::setw(totalWidth) << "=" << std::endl;
	std::cout << std::setfill(' ');
}

//------------------------------------------------------------------------------
//	Prints an album
//------------------------------------------------------------------------------
void PrintManager::printAlbum(const Album &album)
{

	std::cout << "Album name: " << album.getName() << std::endl;

	printColumnTitles();

	for (int i = 0; i < album.getCount(); i++)
	{
		Song song = album.getSong(i);

		printSong(song, i + 1);
	}

}

//------------------------------------------------------------------------------
//	Prints a song with an index.
//------------------------------------------------------------------------------
void PrintManager::printSong(const Song &song, const int atIndex)
{

	std::cout << std::left;
	std::cout << std::setw(NR_WIDTH) << atIndex;
	std::cout << std::setw(TITLE_WIDTH) << song.getTitle();
	std::cout << std::setw(ARTIST_WIDTH) << song.getArtist();
	std::cout << std::right;
	std::cout << std::setw(TIME_WIDTH);
	std::cout << song.getTime().toString();
	std::cout << std::endl;
}

//------------------------------------------------------------------------------
//	Prints all albums that the vector holds in alphabetic order and by length of each song.
//------------------------------------------------------------------------------
void PrintManager::printAlbumsByName(const std::vector<Album> &albums)
{
	std::vector<Album> modifiedList = albums;

	sortAlbumsByName(modifiedList);

	for (Album a : modifiedList)
	{
		sortSongsInAlbum(a);

		printAlbum(a);
		std::cout << std::endl;
	}

}

//------------------------------------------------------------------------------
//	Prints songs.
//------------------------------------------------------------------------------
void PrintManager::printSongs(const std::vector<Song> &allSongs)
{

	printColumnTitles();

	for (int i = 0; i < allSongs.size(); i++)	
	{
		printSong(allSongs[i], i + 1);
	}

}

//------------------------------------------------------------------------------
//	Prints all albums that the vector holds by their total playtime.
//------------------------------------------------------------------------------
void PrintManager::printAlbumsByLength(const std::vector<Album> &albums)
{
	std::vector<Album> modifiedList = albums;

	sortAlbumsByLength(modifiedList);

	for (Album a : modifiedList)
	{
		std::cout << "Total time: " << a.getTotalTime().toString() << std::endl;
		printAlbum(a);
		std::cout << std::endl;
	}
}

//------------------------------------------------------------------------------
//	Prints all albums and only the albums name in alphabetic order.
//------------------------------------------------------------------------------
void PrintManager::simplePrintAlbumsByName(const std::vector<Album> &albums)
{
	std::vector<Album> modifiedList = albums;

	sortAlbumsByName(modifiedList);

	std::for_each(modifiedList.begin(), modifiedList.end(),
		[](const Album &a) {std::cout << a.getName() << std::endl; });

}

//------------------------------------------------------------------------------
//	Prints all albums and only the albums name by their length.
//------------------------------------------------------------------------------
void PrintManager::simplePrintAlbumsByLength(const std::vector<Album> &albums)
{
	std::vector<Album> modifiedList = albums;

	sortAlbumsByLength(modifiedList);

	std::for_each(modifiedList.begin(), modifiedList.end(),
		[](const Album &a) {std::cout << std::setw(48) << a.getName() << 
							a.getTotalTime().toString() << std::endl; });

}

//------------------------------------------------------------------------------
//	Sort the list of albums by name.
//------------------------------------------------------------------------------
void PrintManager::sortAlbumsByName(std::vector<Album> &albums)
{
	std::sort(albums.begin(), albums.end(),
		[](const Album &a, const Album &b) {return toLowerCase(a.getName()) < toLowerCase(b.getName()); });
}

//------------------------------------------------------------------------------
//	Sort the songs in an album by their length.
//------------------------------------------------------------------------------
void PrintManager::sortSongsInAlbum(Album &album)
{
	std::sort(album.getAllSongs().begin(), album.getAllSongs().end(),
		[](const Song &t1, const Song &t2) { return toSeconds(t1.getTime()) > toSeconds(t2.getTime()); });
}

//------------------------------------------------------------------------------
//	Sort the list of albums by their total length.
//------------------------------------------------------------------------------
void PrintManager::sortAlbumsByLength(std::vector<Album> &albums)
{
	std::sort(albums.begin(), albums.end(),
		[](const Album &a, const Album &b) { return a.getTotalTime() > b.getTotalTime(); });
}