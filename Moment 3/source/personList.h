#pragma once

#include <vector>
#include "person.h"
#include <fstream>

class PersonList
{
private:
	std::vector<Person> m_list;
	std::string m_fileName;

public:

	void setFileName(const std::string fileName) { m_fileName = fileName + ".txt"; }
	std::string getFileName() const { return m_fileName; }

	void addPerson(const Person &person);
	Person getPerson(const int index) const;
	int getSize() { return m_list.size(); }
	void sortName();
	void sortPersNr();
	void sortShoeNumber();
	bool readFromFile();
	bool writeToFile();

	static bool compareNames(const Person &p1, const Person &p2)
	{
		return p1.getName() < p2.getName();
	}

	static bool comparePersonalNumber(const Person &p1, const Person &p2)
	{
		return p1.getPersonalNumber() < p2.getPersonalNumber();
	}

	static bool compareShoeSize(const Person &p1, const Person &p2)
	{
		return p1.getShoeSize() < p2.getShoeSize();
	}
};
