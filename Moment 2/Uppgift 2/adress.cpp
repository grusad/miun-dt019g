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

void printAddress(Address const &address)
{
	std::cout << address.getStreetAddress() << ", " <<
		address.getPostalCode() << ", " << address.getCity() << std::endl;
}