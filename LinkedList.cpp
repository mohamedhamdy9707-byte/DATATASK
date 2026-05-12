#include "LinkedList.h"
#include <iostream>
using namespace std;

linked_list::linked_list()
{
    head = nullptr;
}

void linked_list::insertAtEnd(int value)
{ 
    node* newnode = new node ; // creat the new box
    newnode->data = value ;  // put the value inside node
    newnode->next = nullptr; // next nullptr
    
    //case 1 list is empty 
    if (head==nullptr)
    {
       head = newnode ; 
       return ;     // head point to new nod 
    }
    
    node* temp = head ;
    while (temp->next != nullptr)
    {
        temp= temp->next ;           // it move till (temp->next = nullptr)
    }
    temp->next= newnode ; // it creat newnode
}

void linked_list::insertAtHead(int value)
{
    node* newnode = new node;
    newnode->data = value ; 
    newnode->next = head ;
    head = newnode ; 
}

void linked_list::deleteValue(int value)
{
    node* current = head;
    node* pre = nullptr;
    while(current != nullptr)        // walk until end
    {
        if(current->data == value)   // found it!
        {
            // case 1: deleting the head
            if(pre == nullptr)
            {
                head = current->next; // move head forward
            }
            // case 2: deleting middle or end
            else
            {
                pre->next = current->next; // delete el current 
            }
            delete current;  // free memory
            return;          // done!
        }
        pre = current;           // move pre forward
        current = current->next; // move current forward
    }
    // if we reach here value not found
    cout << "Value not found!" << endl;
}

void linked_list::display()
{
    node* temp = head;
    while(temp != nullptr)
    {
        cout << temp->data <<"->";
        temp = temp->next ;
    }
    cout << "NULL" << endl;
}

linked_list::~linked_list() // ~ → this symbol means DESTRUCTOR
{
    node* temp = head;
    while(temp != nullptr)
    {
     node* next = temp->next;  // save next first
     delete temp;              // now safe to delete
     temp = next;              // move forward safely    
    }
}