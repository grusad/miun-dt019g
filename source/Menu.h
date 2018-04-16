/*
* Filename:		Menu.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/



#pragma once

#include <vector>
#include "MenuItem.h"

//	The item that menu-class holds.
typedef MenuItem Item;

//------------------------------------------------------------------------------
//	A class that represents a Menu containing menuItems.
//------------------------------------------------------------------------------
class Menu
{

private:
	std::vector<Item> m_menu;
	std::string m_title;

public:

	// Constructors.
	Menu() : m_title("") {};
	Menu(std::string title) : m_title(title) {};

	void addItem(const Item &item);
	void addItem(std::string text, bool enabled);

	// Setters
	void setTitle(std::string title) { m_title = title; };

	// Getters
	std::string getTitle() const { return m_title; };
	Item &getItem(const int index) { return m_menu[index]; };

	void printMenuItems() const;
	int getMenuChoise();
	void enableAll();

};