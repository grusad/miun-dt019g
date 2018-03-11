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

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	std::string getFirstName() const;
	std::string getLastName() const;

};

void printNames(Name const &name);