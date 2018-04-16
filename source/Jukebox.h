/*
* Filename:		Jukebox.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#pragma once

#include <vector>
#include "Album.h"
#include "Menu.h"
#include "Queue.h"


//------------------------------------------------------------------------------
//	The class that is the main-program.
//------------------------------------------------------------------------------
class Jukebox
{

private:

	std::vector<Album> m_albums;

	Menu m_fileMenu;
	Menu m_printMenu;
	Menu m_playMenu;
	Menu m_mainMenu;
	Queue m_queue;


public:
	Jukebox();
	void run();

private:
	void addAlbum();
	void removeAlbum();

	void runFileMenu();
	void runPrintMenu();
	void runPlayMenu();

	void createPlaylist();
	void playPlaylist();
	void randomizePlaylist();

	Song createSongManually();
	Album *findAlbum(std::string const &searchName);
	bool findAlbum(std::string const &searchName, int &atIndex);
	std::vector<Song> getAllSongs() const;

};

