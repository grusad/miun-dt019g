#include "housingQ.h"
#include <iostream>
#include <string>
#include <fstream>

/*
	@breif A function that clears the buffer.
*/
static void flush()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
}

static void wait()
{
	std::cout << std::endl << std::endl << "Press Enter to Continue . . . ";
	flush();
}


void HousingQ::run()
{
	std::cout << "Enter programs filename. [name.txt]" << std::endl;
	std::cout << "If file already exists with the given name the file will be loaded." << std::endl;
	std::cout << ">";
	std::getline(std::cin, m_fileName);

	loadFromFile();

	printMenu();
}

void HousingQ::printMenu()
{

	bool running = true;

	do
	{
		std::cout << ":::: MENU ::::" << std::endl << std::endl;
		std::cout << "1. Place a person in the queue." << std::endl;
		std::cout << "2. Offer a person a house." << std::endl;
		std::cout << "3. Print the queue." << std::endl;
		std::cout << "4. Print a person." << std::endl;
		std::cout << "5. Remove a person from the queue." << std::endl;
		std::cout << "6. Save to file." << std::endl;
		std::cout << "7. Quit." << std::endl;
		std::cout << "> ";

		int alternative = -1;

		do
		{
			std::cin >> alternative;
			flush();

		} while (alternative < 0 || alternative > 7);

		switch (alternative)
		{
		case 1:
			putInQueue();
			break;
		case 2:
			offerPersonHouse();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			printPerson();
			break;
		case 5:
			removeFromQueue();
			break;
		case 6:
			saveToFile();
			break;
		case 7:
			running = false;
			break;
		}

	} while (running);

}



void HousingQ::putInQueue()
{
	Person person = createPerson();
	m_list.enque(person);

	std::cout << "Person added to the queue." << std::endl;
	wait();
}

void HousingQ::offerPersonHouse()
{

	if (m_list.isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		wait();
		return;
	}

	Person person;
	m_list.deque(person);
	std::cout << "Person removed from queue:" << std::endl;
	person.printInfo();

	wait();
}

void HousingQ::printQueue()
{

	if (m_list.isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		wait();
		return;
	}
	
	std::cout << ":::: QUEUE ::::" << std::endl;
	std::cout << "Queuesize " << m_list.getSize() << std::endl << std::endl;

	int index = 1;
	for(QIterator iterator = m_list.begin(); iterator != m_list.end(); iterator++)	//Loops through the queue using an iterator
	{
		std::cout << "Place " << index++ << std::endl;
		(*iterator).printInfo();
		std::cout << std::endl;
	}

	wait();
}

void HousingQ::printPerson()
{

	if (m_list.isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		wait();
		return;
	}

	std::cout << "Enter person id: ";
	std::string id;
	std::getline(std::cin, id);

	int queueIndex = -1;

	for (auto i = m_list.begin(); i != m_list.end(); i++)	//Iterate over queue
	{
		if ((*i).getPersonalNumber() == id)					//If entered id is found in queue.
		{
			std::cout << "Person found in queue at position " << queueIndex << std::endl;
			wait();
			return;
			
		}
		queueIndex++;
	}

	std::cout << "Person not found in queue." << std::endl;
	wait();
}

void HousingQ::removeFromQueue()
{
	if (m_list.isEmpty())
	{
		std::cout << "The queue is empty." << std::endl;
		wait();
		return;
	}

	std::cout << "Enter person id: ";
	std::string id;
	std::getline(std::cin, id);

	int queueIndex = -1;

	for (auto i = m_list.begin(); i != m_list.end(); i++)			//Iterate over queue
	{
		if ((*i).getPersonalNumber() == id)							//If entered id is found in queue
		{
			m_list.deque(*i);										//remove
			std::cout << "Person removed from queue" << std::endl;
			wait();
			return;

		}
		queueIndex++;
	}


}

void HousingQ::saveToFile()
{
	std::ofstream file(m_fileName);
	if (file.is_open())
	{
		for (QIterator iterator = m_list.begin(); iterator != m_list.end(); iterator++)
		{
			file << (*iterator) << std::endl;
		}

		file.close();
		
		std::cout << "File saved." << std::endl;
	}
	else
	{
		std::cout << "File could not save." << std::endl;
	}

	wait();
}

void HousingQ::loadFromFile()
{
	std::ifstream file(m_fileName);
	if (file.is_open())
	{
		Person person;
		while (file >> person)
		{
			m_list.enque(person);
		}

		file.close();

		std::cout << "File loaded." << std::endl;
	}
	else
	{
		std::cout << "No file to load." << std::endl;
	}

	wait();

}
