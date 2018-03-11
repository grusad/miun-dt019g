#pragma once
#include <string>

class Address
{
	
private:
	std::string m_streetAddress;
	std::string m_city;
	std::string m_postalCode;

public:

	Address();
	Address(std::string streetAddress, std::string city, std::string postalCode);

	void setStreetAddress(std::string streetAddress);
	void setCity(std::string city);
	void setPostalCode(std::string postalCode);

	std::string getStreetAddress() const;
	std::string getCity() const;
	std::string getPostalCode() const;

};

void printAddress(Address const &address);