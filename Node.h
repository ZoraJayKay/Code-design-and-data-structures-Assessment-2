#pragma once
class Node
{
public:
	// Default constructor
	Node();

	// Destructor
	~Node();
	
	// Node navigation pointers
	Node* previousNode;
	Node* nextNode;

	// Node content variables
	double data;
};

