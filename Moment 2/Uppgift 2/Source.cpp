#include <iostream>
#include "address.h"


int main()
{

	{
		Address address;
		address.setCity("Halmstad");
		address.setStreetAddress("Skepparegatan 1");
		address.setPostalCode("302 94");

		printAddress(address);
	}

	{
		Address address("Skepparegatan 1", "Halmstad", "302 94");

		printAddress(address);
	}

	std::cin.get();

}