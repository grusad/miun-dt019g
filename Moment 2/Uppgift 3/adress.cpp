#include "address.h"
#include <iostream>

Address::Address() { };

Address::Address(std::string streetAddress, std::string city, std::string postalCode)
{
	m_streetAddress = streetAddress;
	m_city = city;
	m_postalCode = postalCode;
}

void Address::setStreetAddress(std::string streetAddress)
{
	m_streetAddress = streetAddress;
}

void Address::setCity(std::string city)
{
	m_city = city;
}

void Address::setPostalCode(std::string postalCode)
{
	m_postalCode = postalCode;
}

std::string Address::getStreetAddress() const
{
	return m_streetAddress;
}

std::string Address::getCity() const
{
	return m_city;
}

std::string Address::getPostalCode() const
{
	return m_postalCode;
}

//Prints the address.
void printAddress(Address const &address)
{
	std::cout << address.getStreetAddress() << ", " <<
		address.getPostalCode() << ", " << address.getCity() << std::endl;
}

//Returns an Addressobject. Lets the user input the addresses.
Address createAddress()
{
	Address address;
	std::string str;
	std::cout << "Enter streetaddress: ";
	std::getline(std::cin, str);
	address.setStreetAddress(str);

	std::cout << "Enter city: ";
	std::getline(std::cin, str);
	address.setCity(str);

	std::cout << "Enter postalcode: ";
	std::getline(std::cin, str);
	address.setPostalCode(str);

	return address;

}