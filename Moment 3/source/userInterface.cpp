#include "userInterface.h"
#include <iostream>


void flush()
{

	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void wait()
{
	std::cout << std::endl << std::endl << "Press Enter to Continue . . . ";
	flush();
}

void UserInterface::run()
{
	menu();
}

void UserInterface::menu()
{

	bool running = true;

	do
	{

		std::cout << "********   MENU   ********" << std::endl << std::endl;

		std::cout << "1. Add a person." << std::endl;
		std::cout << "2. Print the list." << std::endl;
		std::cout << "3. Save to file." << std::endl;
		std::cout << "4. Load from file." << std::endl;
		std::cout << "5. Sort by name." << std::endl;
		std::cout << "6. Sort by personal number." << std::endl;
		std::cout << "7. Sort by shoe size." << std::endl;
		std::cout << "8. Exit" << std::endl << std::endl;

		int alternative = -1;
		do
		{
			std::cin >> alternative;
			flush();

		} while (alternative < 0 || alternative > 8);

		switch (alternative)
		{
		case 1:
			addPerson();
			break;
		case 2:
			printPersons();
			break;
		case 3:
			saveList();
			break;
		case 4:
			loadList();
			break;
		case 5:
			sortByName();
			break;
		case 6:
			sortByPersNr();
			break;
		case 7:
			sortByShoeSize();
			break;
		case 8:
			running = false;
			break;

		}

	} while (running);
}

void UserInterface::addPerson()
{
	Person person = createPerson();
	list.addPerson(person);
}

void UserInterface::printPersons()
{

	if (list.getSize() == 0) 
	{
		std::cout << "The list is empty." << std::endl;
		wait();
		return;
	}

	for (int i = 0; i < list.getSize(); i++)
	{
		printPerson(list.getPerson(i));
		std::cout << std::endl;
	}

	wait();
}

void UserInterface::saveList()
{

	if (list.getSize() == 0)
	{
		std::cout << "The list is empty." << std::endl;
		wait();
		return;
	}

	std::cout << "Enter filename: ";
	std::string filename;
	std::getline(std::cin, filename);
	list.setFileName(filename);

	if (list.writeToFile())
	{
		std::cout << "List saved." << std::endl;
		wait();
	}
}

void UserInterface::loadList()
{
	std::cout << "Enter filename: ";
	std::string filename;
	std::getline(std::cin, filename);
	list.setFileName(filename);

	if (list.readFromFile())
	{
		std::cout << "List loaded." << std::endl;
		wait();
	}
}

void UserInterface::sortByName()
{
	list.sortName();
	std::cout << "List sorted." << std::endl;
	wait();
}

void UserInterface::sortByPersNr()
{
	list.sortPersNr();
	std::cout << "List sorted." << std::endl;
	wait();
}

void UserInterface::sortByShoeSize()
{
	list.sortShoeNumber();
	std::cout << "List sorted." << std::endl;
	wait();
}