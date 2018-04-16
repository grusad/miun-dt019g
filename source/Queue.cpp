/*
* Filename:		Queue.cpp
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/


#include "Queue.h"

//------------------------------------------------------------------------------
//	Default constructor.
//------------------------------------------------------------------------------
Queue::Queue()
{
	m_arrPtr = new Song[ARRAY_WIDTH];
	m_maxSize = ARRAY_WIDTH;
	m_currentSize = 0;
	m_first = 0;
	m_last = 0;
}

//------------------------------------------------------------------------------
//	Constructor that copies a queue.
//------------------------------------------------------------------------------
Queue::Queue(Queue &queue)
{
	m_arrPtr = new Song[queue.m_maxSize];
	m_maxSize = queue.m_maxSize;
	m_first = queue.m_first;
	m_last = queue.m_last;
	m_currentSize = queue.m_currentSize;

	for (int i = 0; i < m_maxSize; i++)
	{
		m_arrPtr[i] = queue.m_arrPtr[i];
	}
}

//------------------------------------------------------------------------------
//	Dectonstructor. Freeing memory.
//------------------------------------------------------------------------------
Queue::~Queue()
{
	delete[] m_arrPtr;
	m_arrPtr = nullptr;
}

//------------------------------------------------------------------------------
//	Puts a song in the rear of the queue.
//------------------------------------------------------------------------------
void Queue::enque(const Song &song)
{
	
	if (isFull())
	{
		// Increase size.
		m_maxSize += ARRAY_WIDTH;
		Song *newArr = new Song[m_maxSize];

		// Copy the content from first to last.
		for (int i = 0; i < m_maxSize - ARRAY_WIDTH; i++)
		{
			newArr[i] = m_arrPtr[m_first];
			m_first = (m_first + 1) % (m_maxSize - ARRAY_WIDTH);
		}

		delete[] m_arrPtr;
		m_arrPtr = newArr;
		m_last = m_maxSize - ARRAY_WIDTH;

	}
	
	m_arrPtr[m_last] = song;
	m_last = (m_last + 1) % m_maxSize;
	m_currentSize++;
	
}

//------------------------------------------------------------------------------
//	Removes a song from the front of the queue. Returns a pointer to the object.
//	If queue is empty it returns a nullptr.
//------------------------------------------------------------------------------
Song *Queue::deque()
{

	if (isEmpty())
	{
		return nullptr;
	}

	Song *song = &m_arrPtr[m_first];
	m_first = (m_first + 1) % m_maxSize;
	m_currentSize--;
	return song;

}

//------------------------------------------------------------------------------
//	Clears the queue.
//------------------------------------------------------------------------------
void Queue::clear() 
{
	delete[] m_arrPtr;
	m_arrPtr = new Song[ARRAY_WIDTH];
	m_maxSize = ARRAY_WIDTH;
	m_first = 0;
	m_last = 0;
	m_currentSize = 0;
}

//------------------------------------------------------------------------------
//	Overloaded operator. Gives a queue to another queue.
//------------------------------------------------------------------------------
const Queue &Queue::operator=(const Queue &queue)
{

	// If the object has different addresses.
	if (this != &queue)
	{

		delete[] m_arrPtr;
		m_arrPtr = new Song[queue.m_maxSize];
		m_maxSize = queue.m_maxSize;
		m_first = queue.m_first;
		m_last = queue.m_last;
		m_currentSize = queue.m_currentSize;

		for (int i = 0; i < m_maxSize; i++)
		{
			m_arrPtr[i] = queue.m_arrPtr[i];
		}
	}

	return *this;
}

//------------------------------------------------------------------------------
//	Overloaded operator. Adds a song to the queue.
//------------------------------------------------------------------------------
Queue &Queue::operator+=(Song &song)
{
	enque(song);
	return *this;
}