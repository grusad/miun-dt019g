#include "queue.h"
#include "person.h"

class Node
{

public:
	Node *next;
	Item data;
	Node(Node *node, Item newData) :next(node), data(newData) {};

};

QIterator::QIterator()
{
	m_node = nullptr;
}

QIterator::QIterator(Node *node)
{
	m_node = node;
}

Item &QIterator::operator*() const
{
	return m_node->data;
}

QIterator &QIterator::operator++()
{
	m_node = m_node->next;
	return *this;
}

QIterator QIterator::operator++(int)
{
	QIterator temp;
	temp.m_node = m_node;
	m_node = m_node->next;
	return temp;
}

bool QIterator::operator!=(const QIterator &iterator) const
{
	return !(m_node == iterator.m_node);
}


QList::~QList()
{
	while (!isEmpty())
	{
		Node *tempPtr = first;
		first = first->next;
		delete tempPtr;
	}
}

void QList::enque(Item item)
{
	Node *newNode = new Node(nullptr, item);
	if (isEmpty())
	{
		first = newNode;
	}
	else
	{
		last->next = newNode;
	}
	last = newNode;
	size++;
}

bool QList::deque(Item &item)
{
	if (isEmpty()) return false;

	Node *node = first;
	item = node->data;
	first = first->next;

	if (isEmpty()) last = nullptr;

	delete node;
	size--;
	return true;
}

bool QList::del(Item item)
{

	Node *node = first;
	Node *prevNode = nullptr;		//Keeps track of the previouse node in queue. This enables 
									//the function to link the queue together if a node is removed.

	while (node != nullptr)			//while in queue
	{

		if (node->data == item)		//if node holds the correct item
		{
			if(prevNode != nullptr)	//this is true in first iteration
				prevNode->next = node->next;

			else
				first = node->next;

			delete node;			//deleted the node with the correct item.
			return true;
		}

		prevNode = node;
		node = node->next;
	}

	return false;

}

bool QList::isEmpty() const
{
	return first == nullptr;
}
