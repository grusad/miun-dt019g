#pragma once

#include <string>

class Name
{

private:

	std::string m_firstName;
	std::string m_lastName;

public:

	Name();
	Name(std::string firstName, std::string lastName);

	void setFirstName(std::string firstName) { m_firstName = firstName; };
	void setLastName(std::string lastName) { m_lastName = lastName; };
	std::string getFirstName() const { return m_firstName; };
	std::string getLastName() const { return m_lastName; };

	bool operator<(const Name name) const;
	bool operator==(const Name name) const;

};

std::ostream &operator<<(std::ostream &os, const Name &name);
std::istream &operator>>(std::istream &is, Name &name);

Name createName();
void printNames(Name const &name);