#pragma once


class DoubleLinkedList
{
protected:
	// Node navigation pointers
	class Node* Head;
	class Node* Tail;
	class Node* temp;
	class Node* iterator;

public:
	// Default constructor
	DoubleLinkedList();

	// Destructor
	~DoubleLinkedList();

	// Node navigation functions
		// Add a new value if the linked list is empty
		void addToEmpty(double value);
		// Add a new value to the front of the list
		void pushFront(double value);
		// Add a new value to the end of the list
		void pushBack(double value);
		// Add a new value one-past the specified iterator location
		void insert(double nodeData, double iteratorNumber);
		// Return an iterator to the first element
		Node* begin();
		// Return an iterator to a null element
		Node* end();
		// Return the first element by value, assert if no elements
		double first();
		// Return the last element by value, assert if no oidlements
		double last();
		// Return how many elements exist in the list
		double count();
		// Remove an element by its iterator
		void erase(Node& iterator);
		// Remove all elements with matching value
		void remove(double nodeData);
		// Remove the last element
		void popBack();
		// Remove the first element
		void popFront();
		// Return a Boolean, true if the list is empty, false otherwise
		bool isEmpty();
		// Remove all elements from the list
		void clear();
};

