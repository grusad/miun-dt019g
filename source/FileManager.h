/*
* Filename:		FileManager.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#pragma once

#include <string>
#include <vector>
#include "Album.h"

//------------------------------------------------------------------------------
//	A class that manage the usage with files.
//------------------------------------------------------------------------------
class FileManager
{
private:

	const std::string FILE_NAME = "file.txt";

public:

	bool readFromFile(std::vector<Album> &albums);
	bool saveToFile(const std::vector<Album> &albums);
};