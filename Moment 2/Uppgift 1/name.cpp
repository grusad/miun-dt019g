#include "name.h"
#include <iostream>

Name::Name() { };

Name::Name(std::string firstName, std::string lastName)
{
	m_firstName = firstName;
	m_lastName = lastName;
}

void Name::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void Name::setLastName(std::string lastName)
{
	m_lastName = lastName;
}

std::string Name::getFirstName() const
{
	return m_firstName;
}

std::string Name::getLastName() const
{
	return m_lastName;
}

void printNames(Name const &name)
{
	std::cout << "Firstname: " << name.getFirstName() << std::endl;
	std::cout << "Lastname: " << name.getLastName() << std::endl;
}