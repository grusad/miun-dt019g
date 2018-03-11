#include <iostream>
#include "name.h"

int main()
{

	{
		Name name;
		
		name.setFirstName("Alexander");
		name.setLastName("Gillberg");

		printNames(name);
	}

	{
		Name name("Alexander", "Gillberg");
		printNames(name);
	}
	
	std::cin.get();

}