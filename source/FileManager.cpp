/*
* Filename:		FileManager.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#include "FileManager.h"
#include <fstream>
#include "Input.h"

//------------------------------------------------------------------------------
//	Loads albums from file and put it in the referenced vector.
//------------------------------------------------------------------------------
bool FileManager::readFromFile(std::vector<Album> &albums)
{
	std::ifstream file(FILE_NAME);

	if (file.is_open())
	{

		if (!albums.empty()) albums.clear();

		while (true)
		{
			Album album;
			file >> album;
			if (file.eof()) break;
			albums.push_back(album);
		}

		std::cout << std::endl << "Loaded from file." << std::endl;
		file.close();

		Input::promptUser();
		return true;
	
	}
	else
	{
		std::cout << std::endl << "Could not load file." << std::endl;
		Input::promptUser();
		return false;
	}


}

//------------------------------------------------------------------------------
//	Saves albums to file
//------------------------------------------------------------------------------
bool FileManager::saveToFile(const std::vector<Album> &albums)
{
	std::ofstream file(FILE_NAME);

	if (file.is_open())
	{
		for (Album album : albums)
		{
			file << album;
		}

		std::cout << std::endl << "Saved to file." << std::endl;
		file.close();

		Input::promptUser();
		return true;
	}
	else
	{
		std::cout << std::endl << "Could not save to file." << std::endl;
		Input::promptUser();
		return false;
	}

}
