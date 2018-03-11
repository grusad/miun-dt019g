#include "person.h"
#include "constants.h"
#include <iostream>

Person::Person() {};

Person::Person(Name name, Address address, std::string persNumber, int shoeSize)
{
	m_name = name;
	m_address = address;
	m_persNr = persNumber;
	m_shoeSize = shoeSize;
}

bool Person::operator<(const Person &person) const
{

	if (m_name < person.m_name) return true;
	if (m_name == person.m_name)
	{
		if (m_address < person.m_address) return true;
	}
	return false;

}

bool Person::operator==(const Person &person) const
{
	if (m_name == person.m_name && m_address == person.m_address
		&& m_persNr == person.m_persNr && m_shoeSize == person.m_shoeSize)
		return true;
	return false;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
	os << person.getName() << DELIM;
	os << person.getAddress() << DELIM;
	os << person.getPersonalNumber() << DELIM;
	os << person.getShoeSize();
	return os;
}

std::istream &operator>>(std::istream &is, Person &person)
{

	Name name;
	is >> name;
	person.setName(name);

	Address address;
	is >> address;

	person.setAddress(address);

	std::string persNr;
	getline(is, persNr, DELIM);
	person.setPersonalNumber(persNr);

	int shoeSize;
	is >> shoeSize;
	is.get();
	person.setShoeSize(shoeSize);

	return is;
}

//Returns a Personobjekt. Lets the user input the properties of the objekt.
Person createPerson()
{
	std::cout << "********   NEW PERSON   ********" << std::endl << std::endl;
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

