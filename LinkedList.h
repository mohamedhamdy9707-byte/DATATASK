#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

class linked_list
{
private:
    node* head;

public:
    linked_list();
    ~linked_list();
    void insertAtHead(int value);
    void insertAtEnd(int value);
    void deleteValue(int value);
    void display();
};

#endif