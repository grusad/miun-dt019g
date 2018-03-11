#pragma once

#include "person.h"

typedef Person Item;
class Node;

class QIterator
{
private:
	Node *m_node;

public:
	QIterator(); 
	QIterator(Node *n); 
	Item &operator*() const;
	QIterator &operator++(); 
	QIterator operator++(int); 
	bool operator!=(const QIterator &qi) const;

};


class QList
{

private:
	Node *first, *last;
	int size = 0;

public:
	QList() :first(nullptr), last(nullptr) {};
	~QList();
	void enque(Item item);
	bool deque(Item &item);
	bool del(Item item);
	bool isEmpty()const;
	int getSize() { return size; };
	QIterator begin()const { return QIterator(first); }
	QIterator end() const { return QIterator(nullptr); }

};