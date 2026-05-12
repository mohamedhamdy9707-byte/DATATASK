#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>


using namespace std;

int main() {

  cout << "       TESTING LINKED LIST\n";

  linked_list ll;
  ll.insertAtHead(10);
  ll.insertAtEnd(20);
  ll.insertAtEnd(30);
  cout << "List after insertions: ";
  ll.display();

  ll.deleteValue(20);
  cout << "List after deleting 20: ";
  ll.display();

  cout << "       TESTING STACKS\n";

  // 1. Array-Based Stack
  cout << "--- Stack (Array-Based) ---\n";
  StackArray stackArr(3);
  stackArr.push(1);
  stackArr.push(2);
  stackArr.push(3);
  stackArr.push(4); // Should trigger Stack Overflow

  cout << "Popped from array stack: " << stackArr.pop() << endl;
  cout << "Top element is now: " << stackArr.peek() << endl;

  // 2. Linked List-Based Stack
  cout << "\n--- Stack (Linked List-Based) ---\n";
  StackLL stackLL;
  stackLL.push(100);
  stackLL.push(200);
  cout << "Popped from LL stack: " << stackLL.pop() << endl;
  cout << "Top element is now: " << stackLL.peek() << endl;

  cout << "       TESTING QUEUES\n";

  // 1. Circular Queue (Array-Based)
  cout << "--- Circular Queue (Array-Based) ---\n";
  QueueArray queueArr(3);
  queueArr.enqueue(10);
  queueArr.enqueue(20);
  queueArr.enqueue(30);
  queueArr.enqueue(40); // Should trigger Queue is full

  cout << "Current Circular Queue: ";
  queueArr.display();

  cout << "Dequeued: " << queueArr.dequeue() << endl;
  queueArr.enqueue(40); // Testing circular wrap-around
  cout << "Queue after enqueueing 40 (testing circularity): ";
  queueArr.display();

  // 2. Linked List-Based Queue
  cout << "\n--- Queue (Linked List-Based) ---\n";
  QueueLinkedList queueLL;
  queueLL.enqueue(500);
  queueLL.enqueue(600);
  cout << "Current LL Queue: ";
  queueLL.display();

  cout << "Dequeued: " << queueLL.dequeue() << endl;
  cout << "Queue after dequeue: ";
  queueLL.display();

  cout << "\nAll tests completed successfully!\n";
  return 0;
}