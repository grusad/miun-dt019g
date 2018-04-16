/*
* Filename:		Input.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#pragma once

#include <string>

//------------------------------------------------------------------------------
//	A class that handles userinput.
//------------------------------------------------------------------------------
class Input
{

private:
	Input();

public:

	static void promptUser();
	static std::string getString();
	static int getInteger();
	static int getInteger(const int min, const int max);


};