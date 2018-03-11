#include <iostream>
#include "person.h"
#include <vector>

int printMenu();
void printList(const std::vector<Person> &list);

//Cleans the buffer
void flush()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	typedef Person Item;

	std::vector<Item> list;

	Person person1(Name("Alexander", "Gillberg"),
		Address("Skepparegatan 1", "Halmstad", "302 94"),
		"910707-2275", 44);

	Person person2(Name("Ulrixandur", "Gullburg"),
		Address("Skepparegatan 55", "Hulmstud", "13132"),
		"855545-5575", 23);

	Person person3(Name("Tobbe", "Segerdojja"),
		Address("KomDa", "Ulricehamn", "222"),
		"556544-2254", 88);

	list.push_back(person1);
	list.push_back(person2);
	list.push_back(person3);

	bool running = true;

	do
	{
		int alternative = printMenu();

		switch (alternative)
		{
		case 1:
			list.push_back(createPerson());
			break;
		case 2:
			printList(list);
			break;
		case 3:
			running = false;
			break;
		}

	} while (running);

	flush();
	std::cin.get();

}

//prints the full list to console
void printList(const std::vector<Person> &list)
{
	for (size_t i = 0; i < list.size(); i++)
	{
		printPerson(list[i]);
		std::cout << std::endl;
	}
}

//Prints the menu and return the alternative as an integer
int printMenu()
{
	std::cout << "1. Add a person" << std::endl;
	std::cout << "2. Print list" << std::endl;
	std::cout << "3. Exit" << std::endl;

	int alternative;
	std::cin >> alternative;
	
	if (!std::cin)
	{
		alternative = -1;
	}

	flush();

	return alternative;

	
}