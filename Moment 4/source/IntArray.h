#pragma once


class IntArray
{
private:
	int *arr;
	size_t maxSize;
	size_t size;

public:

	IntArray();
	IntArray(int num);
	IntArray(const IntArray &a);
	~IntArray();


	size_t getMaxSize() const { return maxSize; }
	size_t getSize() const { return size; }
	int getValue(int idx) const;
	bool addValue(int value);

	const IntArray &operator=(const IntArray &a);

	void fillRandomNumbers(const int minValue, const int maxValue);
	void quickSort();
	void insertionSort();
	void selectionSort();
	void bubbleSort();


};

void swap(int &a, int &b);