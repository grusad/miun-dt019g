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

	void setName(Name name);
	void setAddress(Address address);
	void setPersonalNumber(std::string persNr);
	void setShoeSize(int shoeSize);

	Name getName() const;
	Address getAddress() const;
	std::string getPersonalNumber() const;
	int getShoeSize() const;
};

Person createPerson();
void printPerson(Person const &person);