#include <iostream>
#include "DoubleLinkedList.h"

void IsListEmpty(DoubleLinkedList& list) {
    if (list.isEmpty() == true) {
        std::cout << "Is the list empty? (Yes)" << std::endl;
        return;
    }
    std::cout << "Is the list empty? (No)" << std::endl;
    return;
};

void Debug() {
    // Create a new linked list (everything will be null)
    DoubleLinkedList* list_01 = new DoubleLinkedList();

    // Count how many nodes there are (should be nil)
    list_01->count();

    // Tell if the list is empty (it should be)
    IsListEmpty(*list_01);

    // Count how many nodes there are (should be 0)
    list_01->count();

    // Add some nodes
    list_01->pushBack(15);  // Should go to the front because the list is empty
    list_01->pushBack(12);  // Should go to the back
    list_01->pushBack(45);  // Should go to the back
    list_01->pushBack(45);  // Should go to the back
    list_01->pushBack(14);  // Should go to the back
    list_01->pushFront(8);  // Should go to the front

    // Tell if the list is empty (should not be)
    IsListEmpty(*list_01);

    // Count how many nodes there are (should be 6)
    list_01->count();

    // Return the first node
    list_01->first();       // Should be 8

    // Return the last node
    list_01->last();        // Should be 14

    // Delete all nodes with data equal to...
    list_01->remove(45);    // Should be 2

    // Count how many nodes there are (should be 4)
    list_01->count();

    // Add some nodes
    list_01->pushBack(35);  // Should go to the back
    list_01->pushFront(1);  // Should go to the front
    list_01->addToEmpty(100);  // Should go to the front

    // Count how many nodes there are (should be 7)
    list_01->count();

    // Return the first node
    list_01->first();       // Should be 100

    // Return the last node
    list_01->last();        // Should be 35

    // Delete the first node
    list_01->popFront();    // Should delete 100
    list_01->popFront();    // Should delete 1

    // Count how many nodes there are (should be 5)
    list_01->count();

    // Clear the list
    list_01->clear();

    // Count how many nodes there are (should be 0)
    list_01->count();

    // Tell if the list is empty (it should be)
    IsListEmpty(*list_01);


    // Add some nodes
    list_01->pushBack(35);  // Should go to the back
    list_01->pushBack(60);  // Should go to the back
    list_01->pushBack(105);  // Should go to the back
    list_01->pushFront(1);  // Should go to the front

    list_01->addToEmpty(100);  // Should go to the front

    // Return the first node
    list_01->first();       // Should be 100

    // Return the last node
    list_01->last();        // Should be 35

    // Insert number 20 after element 3
    list_01->insert(20, 3);

    list_01->popFront();
    list_01->popFront();
    list_01->popFront();

    list_01->first();       // Should be 20
};

int main() {
    Debug();
};