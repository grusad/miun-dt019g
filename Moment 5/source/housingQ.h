#pragma once

#include "queue.h"
#include <string>

class HousingQ
{
private:
	QList m_list;
	int m_count;
	std::string m_fileName;

public:
	HousingQ() : m_count(0), m_fileName("") { };

	void run();

private:
	void putInQueue();
	void offerPersonHouse();
	void printQueue();
	void printPerson();
	void removeFromQueue();
	void saveToFile();
	void loadFromFile();
	void printMenu();

};