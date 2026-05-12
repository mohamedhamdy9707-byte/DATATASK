#include "queue.h"
#include <iostream>

using namespace std;

/*
   Linked List Queue
*/

QueueLinkedList::QueueLinkedList() {
  front = nullptr;
  rear = nullptr;
}

QueueLinkedList::~QueueLinkedList() {
  while (!isEmpty()) {
    dequeue();
  }
}

bool QueueLinkedList::isEmpty() { return front == nullptr; }

// Linked list queue is never full
bool QueueLinkedList::isFull() { return false; }

void QueueLinkedList::enqueue(int value) {
  node *newNode = new node;
  newNode->data = value;
  newNode->next = nullptr;

  if (isEmpty()) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = newNode;
  }
}

int QueueLinkedList::dequeue() {
  if (isEmpty()) {
    cout << "Queue is empty\n";
    return -1;
  }

  node *temp = front;
  int value = front->data;
  front = front->next;

  if (front == nullptr)
    rear = nullptr;

  delete temp;
  return value;
}

void QueueLinkedList::display() {
  if (isEmpty()) {
    cout << "Queue is empty\n";
    return;
  }

  node *current = front;
  while (current != nullptr) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL\n";
}

/*
   Circular Queue (Array)
*/

QueueArray::QueueArray(int size) {
  n_c = size;
  arr = new int[n_c];
  front_c = -1;
  rear_c = -1;
}

QueueArray::~QueueArray() { delete[] arr; }

bool QueueArray::isEmpty() { return front_c == -1; }

bool QueueArray::isFull() { return (rear_c + 1) % n_c == front_c; }

void QueueArray::enqueue(int value) {
  if (isFull()) {
    cout << "Circular Queue is full\n";
    return;
  }

  if (isEmpty()) {
    front_c = rear_c = 0;
  } else {
    rear_c = (rear_c + 1) % n_c;
  }

  arr[rear_c] = value;
}

int QueueArray::dequeue() {
  if (isEmpty()) {
    cout << "Circular Queue is empty\n";
    return -1;
  }

  int value = arr[front_c];

  if (front_c == rear_c) {
    front_c = rear_c = -1;
  } else {
    front_c = (front_c + 1) % n_c;
  }

  return value;
}

void QueueArray::display() {
  if (isEmpty()) {
    cout << "Circular Queue is empty\n";
    return;
  }

  int i = front_c;
  while (true) {
    cout << arr[i] << " -> ";
    if (i == rear_c)
      break;
    i = (i + 1) % n_c;
  }
  cout << "NULL\n";
}