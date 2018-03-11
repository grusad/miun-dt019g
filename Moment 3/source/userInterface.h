#pragma once

#include "personList.h"

class UserInterface
{

private:
	PersonList list;

	void menu();
	void addPerson();
	void printPersons();
	void saveList();
	void loadList();
	void sortByName();
	void sortByPersNr();
	void sortByShoeSize();

public:

	void run();

};
void flush();
void wait();