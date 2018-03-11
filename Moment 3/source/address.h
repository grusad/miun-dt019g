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

	void setStreetAddress(std::string streetAddress) { m_streetAddress = streetAddress; };
	void setCity(std::string city) { m_city = city;  };
	void setPostalCode(std::string postalCode) { m_postalCode = postalCode; };

	std::string getStreetAddress() const { return m_streetAddress; };
	std::string getCity() const { return m_city; };
	std::string getPostalCode() const { return m_postalCode; };

	bool operator<(const Address &address) const;
	bool operator==(const Address &address) const;

};

std::ostream &operator<<(std::ostream &os, const Address &address);
std::istream &operator>>(std::istream &is, Address &address);

Address createAddress();
void printAddress(Address const &address);