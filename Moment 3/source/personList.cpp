#include "personList.h"
#include "constants.h"
#include <algorithm>

void PersonList::addPerson(const Person &person)
{
	m_list.push_back(person);
}

Person PersonList::getPerson(const int index) const
{
	return m_list[index];
}

void PersonList::sortName()
{
	std::sort(m_list.begin(), m_list.end(), compareNames);
}

void PersonList::sortPersNr()
{
	std::sort(m_list.begin(), m_list.end(), comparePersonalNumber);
}

void PersonList::sortShoeNumber()
{
	std::sort(m_list.begin(), m_list.end(), compareShoeSize);
}

bool PersonList::readFromFile()
{
	std::ifstream file(m_fileName);

	if (file.is_open())
	{
		m_list.clear();

		Person person;
		while (file >> person)
		{
			m_list.push_back(person);
		}

		file.close();

		return true;
	}
	
	return false;
}

bool PersonList::writeToFile()
{

	std::ofstream file(m_fileName);

	if (file.is_open())
	{

		for (auto i : m_list)
		{
			file << i << std::endl;
		}

		file.close();

		return true;
	}

	return false;

}
