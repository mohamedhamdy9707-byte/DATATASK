#include "Stack.h"
#include <iostream>

using namespace std;

//(3)

StackArray::StackArray(int size) {
    capacity = size;
    arr = new int[capacity]; // dynamic memory
    top = -1; 
}

StackArray::~StackArray() {
    delete[] arr; // every new -- delete
}

void StackArray::push(int value) {
    if (top == capacity - 1) { // Stack Overflow handling
        cout << "Error: Stack Overflow!" << endl;
        return;
    }
    arr[++top] = value;
}

int StackArray::pop() {
    if (isEmpty()) { // Stack Underflow handling
        cout << "Error: Stack Underflow!" << endl;
        return -1; 
    }
    return arr[top--];
}

int StackArray::peek() {
    if (isEmpty()) { // Underflow handling
        cout << "Error: Stack is empty!" << endl;
        return -1;
    }
    return arr[top];
}

bool StackArray::isEmpty() {
    return top == -1;
}

//(4)

StackLL::StackLL() : topNode(nullptr) {}

StackLL::~StackLL() {
    // repeat -- delete nodes -- memory
    while (!isEmpty()) {
        pop();
    }
}

void StackLL::push(int value) {
    node* newNode = new node; // [cite: 52]
    newNode->data = value;
    newNode->next = topNode;
    topNode = newNode;
}

int StackLL::pop() {
    if (isEmpty()) return -1;
    node* temp = topNode;
    int val = temp->data;
    topNode = topNode->next;
    delete temp; // تحرير الميموري [cite: 58]
    return val;
}

int StackLL::peek() {
    if (isEmpty()) return -1;
    return topNode->data;
}

bool StackLL::isEmpty() {
    return topNode == nullptr;
}