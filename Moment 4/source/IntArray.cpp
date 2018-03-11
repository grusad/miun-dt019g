#include "IntArray.h"
#include <random>
#include <ctime>

IntArray::IntArray()
	:arr(nullptr), maxSize(0), size(0) {};

IntArray::IntArray(int num)
	:maxSize(num), size(0)
{
	arr = new int[maxSize];
}

IntArray::IntArray(const IntArray &a)
{
	maxSize = a.getMaxSize();
	size = a.getSize();
	arr = new int[maxSize];
	for (int i = 0; i < size; i++)
	{
		arr[i] = a.arr[i];
	}
}

IntArray::~IntArray()
{
	delete[]arr;
	arr = nullptr;

}

int IntArray::getValue(int i) const
{
	return arr[i];
}

bool IntArray::addValue(int value)
{
	bool valueAdded = false;
	if (size < maxSize)
	{
		arr[size] = value;
		size++;
		valueAdded = true;
	}
	return valueAdded;
}


const IntArray &IntArray::operator=(const IntArray &a)
{
	if (this != &a)
	{
		delete[]arr;
		arr = new int[a.maxSize];
		maxSize = a.maxSize;
		size = a.size;

		for (int i = 0; i < size; i++)
		{
			arr[i] = a.arr[i];
		}
		
	}

	return *this;
}

void IntArray::fillRandomNumbers(const int minValue, const int maxValue)
{
	std::default_random_engine generator(static_cast<unsigned>(time(0)));
	std::uniform_real_distribution<double> random(minValue, maxValue);

	for (int i = 0; i < maxSize; i++)
	{
		addValue(random(generator));
	}
}

void quick(int a[], int first, int last)
{
	if (first < last)
	{
		int low = first;
		int high = last;

		if (a[first] > a[last]) 
			swap(a[first], a[last]);
		do
		{
			do { low++; } while (a[low] < a[first]);

			do { high--; } while (a[high] > a[first]);

			if (low < high)
				swap(a[low], a[high]);
		} while (low <= high); 

		swap(a[first], a[high]); 
		quick(a, first, high - 1); 
		quick(a, high + 1, last); 
	}
}

void IntArray::quickSort()
{
	quick(arr, 0, size - 1);
}

void IntArray::insertionSort()
{

	for (int i = 0; i < size; i++) {
	int j = i;

		while (j > 0 && arr[j] < arr[j - 1]) {
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void IntArray::selectionSort()
{
	int smallestIndex = 0;
	for (int i = 0; i < size - 1; i++)
	{
		smallestIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[smallestIndex]) smallestIndex = j;
		}

		if (smallestIndex != i)
		{
			swap(arr[i], arr[smallestIndex]);
		}

	}
}

void IntArray::bubbleSort()
{
	for (int pass = 0; pass < size - 1; pass++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		}
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

