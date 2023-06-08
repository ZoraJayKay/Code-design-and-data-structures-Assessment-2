#include "DoubleLinkedList.h"
#include "Node.h"
#include <iostream>			// For NULL, etc, etc
#include <assert.h>			// For null pointer assertions

// Default constructor
DoubleLinkedList::DoubleLinkedList() {
	// Start the linked list with zero elements on creation
	Head = NULL;
	Tail = NULL;
	temp = NULL;
	iterator = NULL;

	// OPTIONAL DEBUG CONSOLE PRINTOUT
	std::cout << "New list created." << std::endl;
};

// Destructor
DoubleLinkedList::~DoubleLinkedList() {
	// Pointer deletion on class destruction
	delete Head;
	Head = nullptr;

	delete Tail;
	Tail = nullptr;

	delete temp;
	temp = nullptr;

	delete iterator;
	iterator = nullptr;
};

// Node navigation functions
	// Add a new value if the linked list is empty
	void DoubleLinkedList::addToEmpty(double value) {
		// Create a pointer to a new node
		temp = new Node();
		// Populate the new node with the passed-in value but do not point its 'next' pointer to any address
		temp->data = value;
		temp->nextNode = NULL;
		temp->previousNode = NULL;

		// If the linked list doesn't have a 'Head' pointer yet (if the linked list is empty)...
		if (Head == NULL) {
			// Then the new node is the only node in the list, so make the new node both the linked list's Head and Tail
			Head = temp;
			Tail = temp;

			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "List was empty: New node added to the front of the list (" << value << ")" << std::endl;
		}

		// If the linked list DOES have a 'Head' pointer already, insert this in front of it.
		else {
			pushFront(value);
			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "New node added to the front of the list (" << value << ")" << std::endl;
		}
	};

	// Add a new value to the front of the list
	void DoubleLinkedList::pushFront(double value) {
		// Create a pointer to a new node
		temp = new Node();
		// Populate the new node with the passed-in value 
		temp->data = value;
		// Make the 'previous' pointer of the new node point nowhere
		temp->previousNode = NULL;
		
		// If the linked list doesn't have a 'Head' pointer yet (if the linked list is empty)...
		if (Head == NULL) {
			// Add the first entry to the linked list
			addToEmpty(value);
			// Do not continue the rest of the function
			return;
		}

		// If the linked list DOES have a 'Head' pointer already...
		// The current head will be second, so make the current head's 'previous' pointer equal to the new node
		Head->previousNode = temp;
		// Make the 'next' pointer of the new node point to the current 'Head' pointer (the first entry) of the linked list
		temp->nextNode = Head;
		// Replace the address of the 'Head' of the linked list with the address of the new node, thereby making the old 'Head' entry #2
		Head = temp;

		// OPTIONAL DEBUG CONSOLE PRINTOUT
		std::cout << "New node added to the front of the list (" << value << ")" << std::endl;
	};

	// Add a new value to the end of the linked list
	void DoubleLinkedList::pushBack(double value) {
		// Create a pointer to a new node
		temp = new Node();
		// Populate the new node with the passed-in value 
		temp->data = value;

		// If the linked list doesn't have a 'Head' pointer yet (if the linked list is empty)...
		if (Head == NULL) {
			// Add the first entry to the linked list
			addToEmpty(value);
			// Do not continue the rest of the function
			return;
		}

		// Make the current 'Tail' pointer (the last entry) of the linked list point to the address of the new node
		Tail->nextNode = temp;
		// Make the 'previous' pointer of the new 'Tail; point to the old 'Tail'
		temp->previousNode = Tail;
		// Replace the address of the current 'Tail' with the address of the new node, thereby making the old 'Tail' the 2nd last
		Tail = Tail->nextNode;
		// Make the 'Tail' point nowhere
		Tail->nextNode = NULL;

		// OPTIONAL DEBUG CONSOLE PRINTOUT
		std::cout << "New node added to the back of the list (" << value << ")" << std::endl;
	};

	// Add a new value one element past the specified iterator location
	void DoubleLinkedList::insert(double nodeData, double iteratorNumber) {
		// Create a counter for determining when the iterator has been reached (starts at 1 because the list doesn't use 0-indexing)
		int counter = 1;
		// Create a pointer to a new node
		temp = new Node();
		// Populate the new node with the passed-in value 
		temp->data = nodeData;

		// If the linked list doesn't have a 'Head' pointer yet (if the linked list is empty)...
		if (Head == NULL) {
			// Add the new node to the end of the linked list
			addToEmpty(nodeData);
			// Do not continue the rest of the function
			return;
		}

		// Set an iterator for the linked list, starting at the 'Head' (the beginning)...
		begin();
		// ... and until the iterator reaches the end of the linked list...
		while (iterator != NULL) {
			// ... check if the target insertion point has been found...
			if (counter == iteratorNumber) {
				// ... and if the target insertion node is the last node in the linked list...
				if (iterator->nextNode == NULL) {
					pushBack(nodeData);
					return;
				}

				// ... or if the target insertion point was found but BEFORE reaching the 'Tail'...
				else {
					// Assign the new node the 'next' pointer that would have been iterated through
					temp->nextNode = iterator->nextNode;
					temp->previousNode = iterator;
					iterator->nextNode->previousNode = temp;
				}

				// After the target insertion point is found and the new node has been inserted, set the address of the iterator equal to the node just inserted and end the loop.
				iterator->nextNode = temp;

				// OPTIONAL DEBUG CONSOLE PRINTOUT
				std::cout << "Element with contents (" << nodeData << ") was added to the linked list after element " << iteratorNumber << "." << std::endl;
				return;
			}
			// ... and if the target insertion point has not yet been found, set the address of the iterator equal to the next node to be iterated through.
			iterator = iterator->nextNode;
			counter++;
		}
		// ... otherwise the element was not found.
		// OPTIONAL DEBUG CONSOLE PRINTOUT
		std::cout << "Element with contents (" << nodeData << ") was not found in the linked list." << std::endl;
	};

	// Return an iterator to the first element
	Node* DoubleLinkedList::begin() {
		// Create an iterator for the linked list, starting at the 'Head' (the beginning)...
		iterator = Head;
		return iterator;
	};

	// Return an iterator to a null element
	Node* DoubleLinkedList::end() {
		// Create an iterator for the linked list, starting at the 'Tail' (the end)...
		iterator = Tail->nextNode;
		return iterator;
	};

	// Return the first element by value, assert if no elements
	double DoubleLinkedList::first() {
		// Before beginning, assert that the list is not empty
		assert(Head != NULL && Tail != NULL);
		// Create an iterator for the linked list, starting at the 'Head' (the beginning)...
		begin();

		// OPTIONAL DEBUG CONSOLE PRINTOUT
		std::cout << "The data in the first element is: (" << iterator->data << ")." << std::endl;

		// Return the first element's recorded value
		return iterator->data;
	};

	// Return the last element by value, assert if no elements
	double DoubleLinkedList::last() {
		// Before beginning, assert that the list is not empty
		assert(Head != NULL && Tail != NULL);
		// Create an iterator for the linked list, starting at the 'Tail' (the end)...
		iterator = Tail;

		// OPTIONAL DEBUG CONSOLE PRINTOUT
		std::cout << "The data in the last element is: (" << iterator->data << ")." << std::endl;

		// Return the last element's recorded value
		return iterator->data;
	};

	// Return how many elements exist in the list
	double DoubleLinkedList::count() {
		double counter = 0;
		// Create a new node pointer which will point to the 'Head'.
		iterator = new Node;
		// Use the new node's 'data' field to count how many elements exist in the list, starting the counter at 0.
			// *** NOTE TO SELF *** This would need updating in a Template linked list because the data that the linked list holds may not be capable of storing numbers like a 'double' can.

		// If the 'Head' is empty (if the 'Head' returns a null pointer)...
		if (begin() == NULL) {
			// Return that the count is zero elements.
			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "The count returned 0 elements." << std::endl;
			return 0;
		}

		// If the linked list DOES have a non-NULL 'Head' pointer...
		if (begin() != NULL) {
			begin();
			// ... then until the iterator reaches the end of the linked list...
			while (iterator != NULL) {
				// ... increase the count inside of the iterator by 1.
				counter++;
				// Move to the next element by setting the address of the iterator equal to the next node to be iterated through (the first 'next' node will be inherited from the 'Head' when we instantiated the iterator)
				iterator = iterator->nextNode;
			}
			// once the count is finished by returning a NULL pointer result, end the function by returning a 'double' which counted how many elements were found in the linked list

			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "The list has " << counter << " elements." << std::endl;
			
			return counter;
		};		
	};

	// Remove an element by its iterator
	void DoubleLinkedList::erase(Node& nodeForDeletion) {
		// In this context an element is a node and its iterator is a pointer to its memory address.
		// So we need to remove a Node object according to a passed-in memory address (a pointer)
		
		// If the list is empty...
		if (isEmpty() == true) {
			// ... exit the function.
			return;
		};

		// If the memory address of the 'Head' is the same as the memory address of the element for deletion...
		if (Head == &nodeForDeletion) {
			// ... delete the 'Head'.
			popFront();
			// ... exit the function.
			return;
		};

		// If the memory address of the 'Tail' is the same as the memory address of the element for deletion...
		if (Tail == &nodeForDeletion) {
			// ... delete the 'Tail'.
			popBack();
			// ... exit the function.
			return;
		};

		// ... Otherwise, starting at the 'Head'...
		begin();
		while (iterator != NULL) {
			// ... if the memory address of the next node is the same as the memory address of the element for deletion...
			if (iterator->nextNode == &nodeForDeletion) {
				// Copy the memory address of the target node...
				temp = iterator->nextNode;
				// Skip the node for deletion in the list sequence...
				iterator->nextNode = iterator->nextNode->nextNode;
				// ... nullify the contents of the memory address of the target node
				temp = NULL;
				// ... exit the function.
				return;
			}

			// ... If the target node for deletion hasn't been found yet...
			else {
				// ... look at the next node
				iterator = iterator->nextNode;
			};
		};
	};

	// Remove all elements with matching value
	void DoubleLinkedList::remove(double nodeDataForDeletion) {
		// In this context an element is a node and its value is its data.
		int counter = 0;

		// First, if the list is empty...
		if (isEmpty() == true) {
			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "The list was empty so no elements were removed." << std::endl;

			// ... exit the function.
			return;
		};

		// Otherwise, for as long as the data of the 'Head' is the same as the data for deletion...
		begin();
		while (Head->data == nodeDataForDeletion) {
			// ... delete the 'Head' and continue the function.
			popFront();
			counter++;
		};
		
		// ... Then, if the data of the 'Tail' is the same as the data for deletion...
		while (Tail->data == nodeDataForDeletion) {
			// ... delete the 'Tail' and continue the function.
			popBack();
			counter++;
		};


		// ... Then, iterate through the remaining elements until reaching the 'Tail'...
		while (iterator != NULL) {
			// ... if we reach the 'tail'...
			if (iterator->nextNode == NULL) {
				// OPTIONAL DEBUG CONSOLE PRINTOUT
				std::cout << counter << " elements of value ("<< nodeDataForDeletion <<") were removed." << std::endl;

				// End the loop
				return;
			};

			// ... but before reaching the 'Tail', if the data of the next node is the same as the data for deletion...
			if (iterator->nextNode->data == nodeDataForDeletion) {
				// Copy the memory address of the node to be deleted...
				temp = iterator->nextNode;
				// Skip the node for deletion in the list sequence...
				iterator->nextNode = iterator->nextNode->nextNode;
				// ... nullify the contents of the memory address of the target node and continue the function.
				temp = NULL;
				counter++;
			}

			// ... If a target node for deletion hasn't been found yet...
			else {
				// ... look at the next node.
				iterator = iterator->nextNode;
			};
		};
	};

	// Remove the last element
	void DoubleLinkedList::popBack() {
		// If the linked list doesn't have a 'Tail' pointer yet (if the linked list is empty)...
		if (Tail == NULL) {
			// There is nothing to delete; do not continue the rest of the function
			return;
		}

		// Otherwise, create an iterator for the linked list, starting at the 'Head' (the beginning)...
		begin();
		// ... and until the iterator reaches the end of the linked list...
		while (iterator != NULL) {
			if (iterator == Tail) {
				iterator = NULL;
				return;
			}

			// ... look for the node which points to the 'Tail' of the linked list and if it is found...
			if (iterator->nextNode == Tail) {
				// Set the 'next' pointer of that node to NULL
				iterator->nextNode = NULL;
				// Nullify the object in the memory address of the 'Tail' pointer
				Tail = NULL;
				// Set this node to be the 'Tail'
				iterator = Tail;
				// Exit the function
				return;
			}

			// ... and each time the 'Tail' is not found, advance the iterator one node.
			iterator = iterator->nextNode;
		}
	}

	// Remove the first element
	void DoubleLinkedList::popFront() {
		// If the linked list doesn't have a 'Head' pointer yet (if the linked list is empty)...
		if (Head == NULL) {
			// There is nothing to delete; do not continue the rest of the function
			return;
		}
		
		begin();	// iterator = Head
		
		if (Head->nextNode != NULL) {
			Head = iterator->nextNode;

			// OPTIONAL DEBUG CONSOLE PRINTOUT
			std::cout << "The first element (" << iterator->data << ") was removed. The new first element is (" << Head->data << ")." << std::endl;

			// Nullify / clear the memory address of the original 'Head' node.
			iterator = NULL;
			return;
		};

		if (Head->nextNode = NULL) {
			iterator = NULL;
			Head = NULL;
			std::cout << "The first element (" << iterator->data << ") was removed. This was the final element and the Head." << std::endl;
			return;
		};
	};

	// Return a Boolean, true if the list is empty, false otherwise
	bool DoubleLinkedList::isEmpty() {
		// If the memory address of the 'Head' pointer is null AND the memory address of the 'Tail' pointer is also null...
		if (Head == NULL && Tail == NULL) {
			// return that the list is not empty
			return true;
		}
		// otherwise return that the list is empty
		return false;
	};

	// Remove all elements from the list
	void DoubleLinkedList::clear() {
		if (isEmpty() == true) {
			std::cout << "The list was already clear." << std::endl;
			return;
		}

		int size = count();
		int counter = 1;
		begin();

		while (counter < size) {
			temp = iterator->nextNode;
			iterator = NULL;
			iterator = temp;
			counter++;
		};

		Head = NULL;
		Tail = NULL;
	};