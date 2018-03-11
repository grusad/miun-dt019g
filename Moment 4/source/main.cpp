#include <iostream>
#include <iomanip>
#include <fstream>
#include "Test.h"

int main()
{

	const int SIZE = 8;
	int elementsToTest[SIZE] = {5000, 10000, 15000, 20000, 25000, 30000, 35000, 40000};
	
	std::ofstream file("file.txt");

	std::cout << "----- BUBBLSORT -----" << std::endl;
	for (int i = 0; i < SIZE; i++)					// Loops through all test-elements
	{
		Test test(elementsToTest[i], BUBBLE);		// Creates a new Test-objekt. Input: The amount of elements to test, the testtype.
		runTest(test);								// Run the test
		printTestResult(test);						// Prints the test to the console
		writeToFile(test, file);					// Writes the testresult to file
	}

	std::cout << "----- INSERTIONSORT -----" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		Test test(elementsToTest[i], INSERTION);
		runTest(test);
		printTestResult(test);
		writeToFile(test, file);

	}
	
	std::cout << "----- SELECTIONSORT -----" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		Test test(elementsToTest[i], SELECTION);
		runTest(test);
		printTestResult(test);
		writeToFile(test, file);

	}

	std::cout << "----- QUICKSORT -----" << std::endl;
	for (int i = 0; i < SIZE; i++)
	{
		Test test(elementsToTest[i], QUICK);
		runTest(test);
		printTestResult(test);
		writeToFile(test, file);
	}

	file.close();

	std::cin.get();

}
