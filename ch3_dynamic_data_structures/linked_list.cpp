/* linked_list.cpp
 * Written from Kubica's Data Structures the Fun Way as illustrative example.
 * 2025-05-20
 */
#include <iostream>
#include "linked_list.h"

using namespace std; 

// Default constructor
Node::Node()
{
    data = 0; 
    next = NULL; 
}

// Parameterized constructor
Node::Node(int data)
{
    this->data = data; 
    this->next = NULL;
}

Node::~Node()
{
    ;
}

/*!
* default constructor
*/
LinkedList::LinkedList() {
    head = NULL;
}

/*!
* parameterized constructor
*/ 
LinkedList::LinkedList(int headValue)
{
    head = new Node(headValue);
    head->next = NULL; 
}

/*!
* LinkedList destructor method. 
*/
LinkedList::~LinkedList()
{
    ;
}

/*!
* Append a LinkedListNode to this LinkedList (FIXME: THIS DOES NOT WORK AT ALL.)
*/
void LinkedList::append(int value)
{
    ;
}

/*!
* Insert a LinkedListNode between two existing nodes.
* previousValue, value reference between which nodes to insert. 
*/
void LinkedList::insert(int previousValue, int value)
{
    std::cout << "Inserting value between values...";
}

/*!
* Remove a specific LinkedListNode from its stored value. 
*/
void LinkedList::remove(int value)
{
    // Does this need some kind of guard statement to throw an exception if linked list has no more nodes? 
    std::cout << "Removing node...";
}

/*!
* Pushes a new node to the front (head) of the list. No return value. 
*/
void LinkedList::push(int data)
{
    Node *newNode = new Node(data); 

    // Assign to head if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return; 
    }

    // insert the newly created linked list at the head
    newNode->next = this->head; // change the reference links. 
    this->head = newNode; 
}

/*!
* Pops the top (head) node off the linked list, returning the value and resets the second node as the new head. 
*/
int LinkedList::pop()
{
    // T nodeValue = this->headPointer.value; 
    // return nodeValue;
    cout << "Pop!"; 
    return 0; 
}

/*!
* Return the `element_number` based on the `value`. 
*/
int LinkedList::lookupElement(int value)
{
    int element_number = 0;
    return element_number;
}

/*!
* Return the `value` of a specific `element_number`.
*/
int LinkedList::lookupValue(int element_number)
{
    int stored_value = 0; 
    return stored_value;
}

/*! 
* Returns `size` of the entire `LinkedList` as an integer.  
*/
int LinkedList::get_size()
{
    int counter = 0;
    Node* temp = head; 

    if (head == NULL)
    {
        // cout << "This list is empty.\n" << endl; 
        return counter;
    }

    while (temp != NULL)
    {
        counter++; 
        temp = temp->next; 
    } 

    return counter; 
}


/*!
* Print a text value representation of the linked list.
*/
void LinkedList::print()
{
    Node *temp = head; 

    if (head == NULL)
    {
        cout << "This list is empty.\n" << endl; 
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; 
    } 
    cout << endl; 
}


/*!
* Print a text value representation of the linked list with the associated node address.
* These addresses are not necessarily contiguous. 
*/
void LinkedList::addressPrint()
{
    Node *temp = head; 

    if (head == NULL)
    {
        cout << "This list is empty.\n" << endl; 
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << "<-" << temp << " ";
        temp = temp->next; 
    } 
    cout << endl; 
}
