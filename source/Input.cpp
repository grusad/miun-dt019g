/*
* Filename:		Input.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/



#include "Input.h"
#include <iostream>
#include <sstream>

//------------------------------------------------------------------------------
//	Promts the user to enter a key to be able to continue.
//------------------------------------------------------------------------------
void Input::promptUser()
{
	std::cout << "Enter any key to continue. . .";
	getString();
	std::cout << std::endl;
}

//------------------------------------------------------------------------------
//	Reads a stringinput from the user.
//------------------------------------------------------------------------------
std::string Input::getString()
{
	std::string str;
	std::getline(std::cin, str);
	return str;
}

//------------------------------------------------------------------------------
//	Reads an input from the user. The function forces the user to enter a Integer 
//	as input.
//------------------------------------------------------------------------------
int Input::getInteger()
{

	while (std::cin)
	{

		std::string line;
		std::getline(std::cin, line);

		std::stringstream ss(line);
		int value;
		if (!(ss >> value))
		{
			//If invalid input.
			continue;
		}

		return value;
	}

	return -1;
}

//------------------------------------------------------------------------------
//	Reads an input from the user. The function forces the user to enter an Integer
//	between an minimum value and a maximum value.
//------------------------------------------------------------------------------
int Input::getInteger(const int min, const int max)
{
	while (true)
	{
		int value = getInteger();
		if (value >= min && value <= max) return value;
	}

	return -1;
}