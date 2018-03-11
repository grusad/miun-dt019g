#pragma once

#include "IntArray.h"
#include <fstream>

enum TestType
{
	QUICK, INSERTION, SELECTION, BUBBLE
};

/*
	@breif A simple Test-objekt that holds a few testrelated variables.
*/
class Test
{
private:

	int m_numberOfElements;
	TestType m_type;
	double m_result = 0;

public:

	Test(int numberOfElements, TestType type)
		: m_numberOfElements(numberOfElements), m_type(type) {};

public:

	int getNumberOfElements() { return m_numberOfElements; };
	double getResult() const { return m_result; };
	void setResult(double result) { m_result = result; };
	TestType getTestType() const { return m_type; };
};

void runTest(Test &test);
void printTestResult(Test &test);
void writeToFile(Test &test, std::ofstream &file);