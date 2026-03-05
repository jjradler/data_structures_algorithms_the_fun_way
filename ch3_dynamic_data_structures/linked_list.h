/*!
*   linked_list.h
*   jjradler
*   created: 2026-03-01
*   updated: 2026-03-05
*/

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


class DoubleNode {
  public:
    int data; 
    DoubleNode* next; 
    DoubleNode* previous; 
    DoubleNode(); 
    DoubleNode(int value); 
    ~DoubleNode(); 
};


class LinkedList {
  public:
    Node* head;   // pointer to linked list head node. 
    LinkedList(); 
    LinkedList(int headValue);
    ~LinkedList();
    void append(int value); 
    int get_size();
    void insert(int previousValue, int value);
    void insertByIndex(int previousIndex, int value); 
    int lookupElement(int value);
    int lookupValue(int element_number);
    void push(int value); 
    void print(); 
    void printAddress();
    int pop(); 
    int remove(int value); 
    int removeByIndex(int elementIndex);
};


class DoublyLinkedList {
  public: 
    DoubleNode* head; 
    DoublyLinkedList(); 
    ~DoublyLinkedList(); 
    void append(int value); 
    int get_size(); 
    void insert(int previousValue, int insertValue);
    void insertByIndex(int previousIndex, int value); 
    int lookupElement(int value);
    int lookupValue(int elementNumber);
    int pop(); 
    void print(); 
    void printAddress();
    void push(int value); 
    int remove(int value); 
    int removeByIndex(int elementIndex); 
};

#endif /*LINKED_LIST_H*/
