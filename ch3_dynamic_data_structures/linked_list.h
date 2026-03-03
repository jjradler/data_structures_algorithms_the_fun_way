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
    void remove(int value);
    void push(int value); 
    int pop(); 
    int lookupElement(int value);
    int lookupValue(int element_number);
    int get_size();
    void print(); 
    void addressPrint();
};

#endif /*LINKED_LIST_H*/
