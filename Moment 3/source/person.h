#pragma once

#include "name.h"
#include "address.h"

class Person
{
private:
	Name m_name;
	Address m_address;
	std::string m_persNr;
	int m_shoeSize;

public:
	Person();
	Person(Name name, Address address, std::string persNumber, int shoeSize);

	void setName(Name name) { m_name = name; };
	void setAddress(Address address) { m_address = address; };
	void setPersonalNumber(std::string persNr) { m_persNr = persNr; };
	void setShoeSize(int shoeSize) { m_shoeSize = shoeSize; };

	Name getName() const { return m_name; };
	Address getAddress() const { return m_address; };
	std::string getPersonalNumber() const { return m_persNr; };
	int getShoeSize() const { return m_shoeSize; };

	bool operator<(const Person &person) const;
	bool operator==(const Person &person) const;

};

std::ostream &operator<<(std::ostream &os, const Person &person);
std::istream &operator>>(std::istream &is, Person &person);

Person createPerson();
void printPerson(Person const &person);