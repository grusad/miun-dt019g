#include "address.h"
#include <iostream>

Address::Address() { };

Address::Address(std::string streetAddress, std::string city, std::string postalCode)
{
	m_streetAddress = streetAddress;
	m_city = city;
	m_postalCode = postalCode;
}

bool Address::operator<(const Address &address) const
{
	if (m_city < address.m_city) return true;
	if (m_city == address.m_city)
	{
		if (m_streetAddress >= address.m_streetAddress) return false;
		return true;
	}
	return false;
}

bool Address::operator==(const Address &address) const
{
	if (m_streetAddress == address.m_streetAddress &&
		m_city == address.m_city) return true;
	return false;
}


std::ostream &operator<<(std::ostream &os, const Address &address)
{
	os << address.getStreetAddress() << DELIM;
	os << address.getCity() << DELIM;
	os << address.getPostalCode();
	return os;
}

std::istream &operator>>(std::istream &is, Address &address)
{
	std::string str;
	std::getline(is, str, DELIM);
	address.setStreetAddress(str);
	std::getline(is, str, DELIM);
	address.setCity(str);
	std::getline(is, str, DELIM);
	address.setPostalCode(str);

	return is;
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