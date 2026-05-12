#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

/*
   Linked List Queue
*/

class QueueLinkedList {
private:
  node *front;
  node *rear;

public:
  QueueLinkedList();
  ~QueueLinkedList();

  bool isEmpty();
  bool isFull();
  void enqueue(int value);
  int dequeue();
  void display();
};

/*
   Circular Queue (Array)
*/

class QueueArray {
private:
  int *arr;
  int front_c;
  int rear_c;
  int n_c;

public:
  QueueArray(int size);
  ~QueueArray();

  bool isEmpty();
  bool isFull();
  void enqueue(int value);
  int dequeue();
  void display();
};

#endif
