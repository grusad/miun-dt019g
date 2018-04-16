/*
* Filename:		Utils.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#include "Utils.h"
#include <algorithm>

//------------------------------------------------------------------------------
//	Returns a copy of the given string as lowered cased.
//------------------------------------------------------------------------------
std::string toLowerCase(const std::string &str)
{
	std::string newStr = str;
	std::transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
	return newStr;
}

//------------------------------------------------------------------------------
//	Returns a copy of the given string as uppered cased.
//------------------------------------------------------------------------------
std::string toUpperCase(const std::string &str)
{
	std::string newStr = str;
	std::transform(newStr.begin(), newStr.end(), newStr.begin(), ::toupper);
	return newStr;
}

//------------------------------------------------------------------------------
//	Clears the screen depending on OS
//------------------------------------------------------------------------------
void clearScreen()
{

#if defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))
	std::cout << "\033[2J\033[1;1H" << std::endl;
#elif _WIN32
	system("cls");
#else
	std::cout << std::string(100, '\n') << std::endl;
#endif 



}