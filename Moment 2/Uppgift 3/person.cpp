#include "person.h"
#include <iostream>

Person::Person() {};

Person::Person(Name name, Address address, std::string persNumber, int shoeSize)
{
	m_name = name;
	m_address = address;
	m_persNr = persNumber;
	m_shoeSize = shoeSize;
}

void Person::setName(Name name)
{
	m_name = name;
}

void Person::setAddress(Address address)
{
	m_address = address;
}

void Person::setPersonalNumber(std::string persNr)
{
	m_persNr = persNr;
}

void Person::setShoeSize(int shoeSize)
{
	m_shoeSize = shoeSize;
}

Name Person::getName() const
{
	return m_name;
}

Address Person::getAddress() const
{
	return m_address;
}

std::string Person::getPersonalNumber() const
{
	return m_persNr;
}

int Person::getShoeSize() const
{
	return m_shoeSize;
}

//Returns a Personobjekt. Lets the user input the properties of the objekt.
Person createPerson()
{
	std::cout << "CREATE A NEW PERSON" << std::endl;
	std::string str;

	Person person;

	person.setName(createName());
	person.setAddress(createAddress());

	std::cout << "Enter personal number: ";
	std::getline(std::cin, str);
	person.setPersonalNumber(str);

	std::cout << "Enter shoe size:";
	int shoesize = 0;
	std::cin >> shoesize;
	person.setShoeSize(shoesize);

	return person;

}

//Prints the Person
void printPerson(Person const &person)
{
	printNames(person.getName());
	printAddress(person.getAddress());
	std::cout << "Personal number: " << person.getPersonalNumber() << std::endl;
	std::cout << "Shoesize: " << person.getShoeSize() << std::endl;
}

