#pragma once

#include "name.h"
#include "address.h"

class Person
{
private:
	Name m_name;
	Address m_address;
	std::string m_persNr;

public:
	Person();
	Person(Name name, Address address, std::string persNumber);

	void setName(Name name) { m_name = name; };
	void setAddress(Address address) { m_address = address; };
	void setPersonalNumber(std::string persNr) { m_persNr = persNr; };

	Name getName() const { return m_name; };
	Address getAddress() const { return m_address; };
	std::string getPersonalNumber() const { return m_persNr; };

	bool operator<(const Person &person) const;
	bool operator==(const Person &person) const;

	void printInfo();
};

std::ostream &operator<<(std::ostream &os, const Person &person);
std::istream &operator>>(std::istream &is, Person &person);


Person createPerson();
