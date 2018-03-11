#include "name.h"
#include <iostream>
#include <algorithm>

Name::Name() { };

Name::Name(std::string firstName, std::string lastName)
{
	m_firstName = firstName;
	m_lastName = lastName;
}

bool Name::operator<(const Name name) const
{
	if (m_lastName < name.m_lastName) return true;
	if (m_lastName == name.m_lastName)
	{
		if (m_firstName >= name.m_lastName) return false;
		else return true;
	}

	return false;
}

bool Name::operator==(const Name name) const
{
	if (m_firstName == name.m_firstName &&
		m_lastName == name.m_lastName) return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Name &name)
{
	os << name.getFirstName() << DELIM;
	os << name.getLastName();
	return os;
}

std::istream &operator>>(std::istream &is, Name &name)
{
	std::string str;
	std::getline(is, str, DELIM);
	name.setFirstName(str);
	std::getline(is, str, DELIM);
	name.setLastName(str);

	return is;
}


//Prints the names
void printNames(Name const &name)
{
	std::cout << "Firstname: " << name.getFirstName() << std::endl;
	std::cout << "Lastname: " << name.getLastName() << std::endl;
}

//Returns a Nameobjekt. Lets the user input the names.
Name createName()
{
	Name name;
	std::string str;

	std::cout << "Enter firstname: ";
	std::getline(std::cin, str);
	name.setFirstName(str);
	std::cout << "Enter lastname: ";
	std::getline(std::cin, str);
	name.setLastName(str);

	return name;
}