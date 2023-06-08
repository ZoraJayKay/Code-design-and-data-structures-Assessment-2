#include "Node.h"

// Default constructor
Node::Node() {};

// Destructor
Node::~Node() {
	// Pointer deletion on class destruction
	delete previousNode;
	previousNode = nullptr;

	delete nextNode;
	nextNode = nullptr;
};