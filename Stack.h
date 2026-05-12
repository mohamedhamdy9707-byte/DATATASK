#ifndef STACK_H
#define STACK_H

#include "node.h"

// (3)
class StackArray {
private:
    int* arr;       // Dynamic array
    int top;        // Top index
    int capacity;   // Stack capacity

public:
    StackArray(int size); 
    ~StackArray();        // Destructor
    void push(int value); // Handle Overflow
    int pop();            // Handle Underflow
    int peek();           // Handle Underflow
    bool isEmpty();
};

// (4)(StackLinkedList)
class StackLL {
private:
    node* topNode; // Private top pointer

public:
    StackLL();
    ~StackLL();           // Free all nodes
    void push(int value); // O(1) complexity
    int pop();            // O(1) complexity
    int peek();           // O(1) complexity
    bool isEmpty();       
};

#endif