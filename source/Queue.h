/*
* Filename:		Queue.h
* Course:		DT019G Objektbaserad Programmering i C++
* Author:		Alexander Gillberg
* ID:			algi1701
* Date:			2018-03-19
*/

#pragma once

#include "Song.h"

//------------------------------------------------------------------------------
//	A class that represents an dynamic Queue.
//------------------------------------------------------------------------------
class Queue
{
private:

	Song *m_arrPtr;			// Pointer to queue.
	int m_first, m_last;	// Index of the first and last object in queue.
	int m_currentSize;		// Current size of queue.
	int m_maxSize;			// Current maximum size of queue.

	
	//	This variables sets the size of the queue and how much it should increase in size each time the 
	//	queue is resized.
	const int ARRAY_WIDTH = 5;

public:
	Queue();
	Queue(Queue &queue);
	~Queue();


	void enque(const Song &song);
	Song *deque();
	const Queue &operator=(const Queue &Queue);
	Queue &operator+=(Song &song);

	bool isEmpty() const { return m_currentSize == 0; };
	bool isFull() const { return m_currentSize == m_maxSize; };

	void clear();

};