#include "Test.h"
#include "timer.h"
#include <iostream>
#include <iomanip>
#include <string>

void runTest(Test &test)
{

	const int amountOfTests = 10;
	double result = 0;

	for (int i = 0; i < amountOfTests; i++)
	{

		IntArray arr(test.getNumberOfElements());
		arr.fillRandomNumbers(0, 1000);

		Timer timer;
		timer.start();
		switch (test.getTestType())
		{
		case QUICK:
			arr.quickSort();
			break;
		case INSERTION:
			arr.insertionSort();
			break;
		case SELECTION:
			arr.selectionSort();
			break;
		case BUBBLE:
			arr.bubbleSort();
			break;
		}

		result += timer.stop() / 1000000;

	}

	result /= 10;

	test.setResult(result);
}

void printTestResult(Test &test)
{

	std::cout << std::setw(10) << std::left << "Time [s]";
	std::cout << std::left << std::setw(20) << std::fixed << std::setprecision(7) << test.getResult();
	std::cout << std::left << std::setw(10) << "Element: ";
	std::cout << std::left << std::setw(10) << test.getNumberOfElements() << std::endl;

}

void writeToFile(Test &test, std::ofstream &file)
{
	std::string str;

	TestType type = test.getTestType();
	if (type == BUBBLE)			str = "BubbleSort";
	else if (type == QUICK)		str = "QuickSort";
	else if (type == SELECTION)	str = "SelectionSort";
	else						str = "InsertionSort";

	file << str << '\t' << test.getNumberOfElements() <<
		'\t' << test.getResult() << std::endl;
}