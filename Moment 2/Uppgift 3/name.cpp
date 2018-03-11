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