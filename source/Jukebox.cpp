/*
* Filename:		Jukebox.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#include "Jukebox.h"
#include "Input.h"
#include "Utils.h"
#include "FileManager.h"
#include "PrintManager.h"
#include <algorithm>
#include <sstream>
#include <random>
#include <chrono>
#include <thread>

//------------------------------------------------------------------------------
//	Default constructor. Initalize all the menus.
//------------------------------------------------------------------------------
Jukebox::Jukebox()
{
	m_mainMenu.setTitle("JUKE BOX");
	m_mainMenu.addItem("File...",				true);
	m_mainMenu.addItem("Add an album",			false);
	m_mainMenu.addItem("Delete an album",		false);
	m_mainMenu.addItem("Print...",				false);
	m_mainMenu.addItem("Play...",				false);
	m_mainMenu.addItem("Exit",					true);

	m_fileMenu.setTitle("FILE");
	m_fileMenu.addItem("Open",					true);
	m_fileMenu.addItem("Save",					false);
	m_fileMenu.addItem("Back to main menu",		true);

	m_printMenu.setTitle("PRINT");
	m_printMenu.addItem("Print one album",							false);
	m_printMenu.addItem("Print all sorted by album name",			false);
	m_printMenu.addItem("Print all sorted by album total time",		false);
	m_printMenu.addItem("Print simple sorted by album name",		false);
	m_printMenu.addItem("Print simple sorted by album total time",	false);
	m_printMenu.addItem("Back to main menu",						false);

	m_playMenu.setTitle("PLAY");
	m_playMenu.addItem("Create a playlist from songs",				false);
	m_playMenu.addItem("Create a random list",						false);
	m_playMenu.addItem("Play list",									false);
	m_playMenu.addItem("Back to main menu",							false);
}

//------------------------------------------------------------------------------
//	The memeber-function that contains the main-loop of the program.
//------------------------------------------------------------------------------
void Jukebox::run()
{
	bool running = true;

	while (running)
	{

		clearScreen();

		m_mainMenu.printMenuItems();

		switch (m_mainMenu.getMenuChoise())
		{
		case 1:
			runFileMenu();
			break;
		case 2:
			addAlbum();
			break;
		case 3:
			removeAlbum();
			break;
		case 4:
			runPrintMenu();
			break;
		case 5:
			runPlayMenu();
			break;
		case 6:
			running = false;
			break;
		}

	}
}

//------------------------------------------------------------------------------
//	Lets the user add an Album to the program.
//------------------------------------------------------------------------------
void Jukebox::addAlbum()
{



	std::string albumName;

	// Checks if the name already exists in the list.
	while (true)
	{
		std::cout << std::endl << "Enter album name: ";
		albumName = Input::getString();
		
		if (findAlbum(albumName) != nullptr) // If already exists...
		{
			std::cout << albumName << " already exists." << std::endl;
			std::cout << "Retry?" << std::endl;
			std::cout << "1. Yes" << std::endl;
			std::cout << "2. No" << std::endl;
			if (Input::getInteger(1, 2) == 2) return;
		}
		else
		{
			break;
		}

	}

	Album album(albumName);

	// Adding songs to album.
	while (true)
	{
		std::cout << std::endl << "Add a song?" << std::endl;
		std::cout << "1. Yes" << std::endl;
		std::cout << "2. No" << std::endl;

		if (Input::getInteger(1, 2) == 2) break;
		
		album.addSong(createSongManually());
	}

	m_albums.push_back(album);

	std::cout << std::endl << album.getName() << " added!" << std::endl;
	Input::promptUser();
	
}

//------------------------------------------------------------------------------
//	Lets the user remove an Album from the program.
//------------------------------------------------------------------------------
void Jukebox::removeAlbum()
{

	std::cout << std::endl << "Enter album name: " << std::endl;
	std::string albumName = Input::getString();

	int atIndex = 0;
	if (findAlbum(albumName, atIndex))
	{
		m_albums.erase(m_albums.begin() + atIndex);
		std::cout << std::endl << "Album was removed." << std::endl;
	}
	else
	{
		std::cout << std::endl << "Album was not found." << std::endl;
	}
	
	Input::promptUser();
}

//------------------------------------------------------------------------------
//	The member-funcktion that runs the file-menu.
//------------------------------------------------------------------------------
void Jukebox::runFileMenu()
{

	FileManager fileManager;

	bool running = true;
	
	while (running)
	{

		clearScreen();

		m_fileMenu.printMenuItems();
		switch (m_fileMenu.getMenuChoise())
		{
		case 1:
			if (fileManager.readFromFile(m_albums))
			{
				m_fileMenu.enableAll();
				m_playMenu.enableAll();
				m_printMenu.enableAll();
				m_mainMenu.enableAll();
			}
			break;
		case 2:
			fileManager.saveToFile(m_albums);
			break;
		case 3:
			running = false;
			break;
		}
	}

	
}

//------------------------------------------------------------------------------
//	The member-function that runs the play-menu.
//------------------------------------------------------------------------------
void Jukebox::runPlayMenu()
{


	bool running = true;

	while (running)
	{

		clearScreen();

		m_playMenu.printMenuItems();
		switch (m_playMenu.getMenuChoise())
		{
		case 1:
			createPlaylist();
			break;
		case 2:
			randomizePlaylist();
			break;
		case 3:
			playPlaylist();
			break;
		case 4:
			running = false;
			break;
		}
	}

	
}

//------------------------------------------------------------------------------
//	Lets the user to create a playlist from the programs library.
//------------------------------------------------------------------------------
void Jukebox::createPlaylist()
{

	m_queue.clear();

	std::vector<Song> allSongs = getAllSongs();
	PrintManager::printSongs(allSongs);

	std::cout << std::endl << "Enter your playlist. Use ',' as deliminator. ex 2, 10, 1: 3. 14. 40" << std::endl << std::endl;

	std::stringstream lineStream(Input::getString());
	int alternative;
	while (lineStream >> alternative)
	{
		char deliminator;
		lineStream >> deliminator;

		if (alternative > allSongs.size() || alternative < 0) // If user input is out of range of the vector.
		{
			continue;
		} 

		m_queue.enque(allSongs[alternative - 1]);
		std::cout << alternative << " was added." << std::endl;
	}

	std::cout << std::endl << "Playlist created." << std::endl;
	Input::promptUser();
}


//------------------------------------------------------------------------------
//	Simulating the program playing the playlist.
//------------------------------------------------------------------------------
void Jukebox::playPlaylist()
{

	if (!m_queue.isEmpty())
	{
		Queue tempQueue = m_queue;

		while (!m_queue.isEmpty())
		{
			Song *song = m_queue.deque();

			std::cout << std::endl << "Now playing: " << song->getTitle() << " - " << song->getArtist();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}

		std::cout << std::endl << "Playlist reached its end." << std::endl;

		m_queue = tempQueue;

		Input::promptUser();
	}
	else
	{
		std::cout << std::endl << "Playlist is empty." << std::endl;
		Input::promptUser();
		return;
	}

	
}

//------------------------------------------------------------------------------
//	Creates a random playlist 
//------------------------------------------------------------------------------
void Jukebox::randomizePlaylist()
{

	m_queue.clear();

	std::vector<Song> avalibleSongs = getAllSongs();

	std::cout << std::endl << "How many songs would you like to have in your random playlist?" << std::endl;
	int amount = Input::getInteger();
	if (amount > avalibleSongs.size())
	{
		amount = avalibleSongs.size();
	}

	std::random_shuffle(avalibleSongs.begin(), avalibleSongs.end());

	for (int i = 0; i < amount; i++)
	{
		m_queue.enque(avalibleSongs[i]);
	}
	
	std::cout << std::endl << std::endl << "Playlist generated." << std::endl;

	Input::promptUser();

}

//------------------------------------------------------------------------------
//	The member-function that runs the print-menu.
//------------------------------------------------------------------------------
void Jukebox::runPrintMenu()
{

	bool running = true;

	while (running)
	{

		clearScreen();

		m_printMenu.printMenuItems();
		switch (m_printMenu.getMenuChoise())
		{
		case 1:
		{

			std::cout << std::endl << "Enter album name: " << std::endl;
			Album *album = findAlbum(Input::getString());

			if (album != nullptr)
			{
				PrintManager::printAlbum(*album);
			}
			else
			{
				std::cout << "Album not found" << std::endl;
			}

			Input::promptUser();

			break;
		}

		case 2:
			PrintManager::printAlbumsByName(m_albums);
			Input::promptUser();
			break;
		case 3:
			PrintManager::printAlbumsByLength(m_albums);
			Input::promptUser();
			break;
		case 4:
			std::cout << std::endl;
			PrintManager::simplePrintAlbumsByName(m_albums);
			Input::promptUser();
			break;
		case 5:
			std::cout << std::endl;
			PrintManager::simplePrintAlbumsByLength(m_albums);
			Input::promptUser();
			break;
		case 6:
			running = false;
			break;
		}
	}
	
}

//------------------------------------------------------------------------------
//	A function that lets the user create a Song-object manually.
//------------------------------------------------------------------------------
Song Jukebox::createSongManually()
{
	Song song;
	std::cout << std::endl;
	std::cout << "Artist: ";			song.setArtist(Input::getString());
	std::cout << "Title: ";				song.setTitle(Input::getString());
	std::cout << "Length [seconds]: ";	song.setTime(fromSeconds(Input::getInteger()));

	return song;
}

//------------------------------------------------------------------------------
//	Finds the album that equals the given searchname. Returns a pointer to the album or
//	nullptr if not found.
//------------------------------------------------------------------------------
Album *Jukebox::findAlbum(std::string const &searchName)
{

	auto i = std::find_if(m_albums.begin(), m_albums.end(),
		[&searchName](const Album &a) {return toLowerCase(a.getName()) == toLowerCase(searchName); });


	if (i != m_albums.end())
	{
		Album *a = &*i;
		return a;
	}

	return nullptr;

}

//------------------------------------------------------------------------------
//	Finds the album that equals the search name. Returns true of false and sets the 
//	referenced integer with the index if found.
//------------------------------------------------------------------------------
bool Jukebox::findAlbum(std::string const &searchName, int &atIndex)
{
	int i = std::find_if(m_albums.begin(), m_albums.end(),
		[&searchName](const Album &a) {return toLowerCase(a.getName()) == toLowerCase(searchName); }) - m_albums.begin();

	if (i < m_albums.size())
	{
		atIndex = i;
		return true;
	}

	return false;

}

//------------------------------------------------------------------------------
//	Returns all songs in all Albums.
//------------------------------------------------------------------------------
std::vector<Song> Jukebox::getAllSongs() const
{
	std::vector<Song> all;

	for (Album a : m_albums)
	{
		for (Song s : a.getAllSongs())
		{
			all.push_back(s);
		}
	}
	return all;
}