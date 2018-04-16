/*
* Filename:		Menu.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/



#include "Menu.h"
#include <iostream>
#include "Input.h"
#include <iomanip>


//------------------------------------------------------------------------------
//	Adds an item to the menu-list.
//------------------------------------------------------------------------------
void Menu::addItem(const Item &item)
{
	m_menu.push_back(item);
}

//------------------------------------------------------------------------------
//	Adds an item to the menu-list.
//------------------------------------------------------------------------------
void Menu::addItem(std::string text, bool enabled)
{
	addItem(Item(text, enabled));
}

//------------------------------------------------------------------------------
//	Prints all the items that the menulist contains. 
//------------------------------------------------------------------------------
void Menu::printMenuItems() const
{

	std::cout << "**** " << m_title << " ****" << std::endl;

	for (int i = 0; i < m_menu.size(); i++)
	{
		std::cout << (i + 1) << ". ";
		Item item = m_menu[i];
		std::cout << std::setw(15) << std::left << item.getText();

		if (!item.isEnabled()) std::cout << std::setw(15) << std::right << "[Unavalible]";

		std::cout << std::endl;
	}

}

//------------------------------------------------------------------------------
//	Gets the users choise of Items. 
//------------------------------------------------------------------------------
int Menu::getMenuChoise()
{
	
	bool validInput = false;

	int choise = -1;

	//MenuItem needs to be enabled for the user to select.
	while (!validInput)
	{
		choise = Input::getInteger(1, m_menu.size());
		
		validInput = getItem(choise - 1).isEnabled();
		if (!validInput) std::cout << "Alternative is unavalible. . ." << std::endl;
	}

	return choise;
}

//------------------------------------------------------------------------------
//	Set all items in the list to be avalible.
//------------------------------------------------------------------------------
void Menu::enableAll()
{
	for (Item &item : m_menu)
	{
		item.setEnabled(true);
	}
}