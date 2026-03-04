#ifndef LINKED_LIST_H
#define LINKED_LIST_H

class Node {
  public:
    int data;
    Node* next;
  // default constructor
    Node(); 
    Node(int headValue);
    ~Node(); 
};

class LinkedList {
    Node* head;   // pointer to linked list head node. 
  public:
    LinkedList(); 
    LinkedList(int headValue);
    ~LinkedList();
    void append(int value); 
    void insert(int previousValue, int value);
    void insertByIndex(int previousIndex, int value); 
    int remove(int elementIndex);
    int removeByValue(int value); 
    void push(int value); 
    int pop(); 
    int lookupElement(int value);
    int lookupValue(int element_number);
    int get_size();
    void print(); 
    void addressPrint();
};

// TODO: Add doubly linked list that inherits all attributes and methods from LinkedList but adds a "previous" pointer. Override methods to account for this as needed. 
class DoublyLinkedList : public LinkedList {
  public: 
    Node *previous; 
};

#endif /*LINKED_LIST_H*/
