/* linked_list.cpp
 * Written from Kubica's Data Structures the Fun Way as illustrative example.
  * A slghtly more than barebones implementation of a singly-linked list with some convenience functions just to illustrate
 * how these data structures work (and to polish some of the rust off of my C++ skills with pointers and classes...)
 * 2026-03-03
 */
#include <iostream>
#include "linked_list.h"

using namespace std; 

/*!
* Default constructor
*/ 
Node::Node()
{
    data = 0; 
    next = NULL; 
}


/*!
* Parameterized constructor
*/ 
Node::Node(int data)
{
    this->data = data; 
    this->next = NULL;
}

/*! 
* Gozer! The Destructor! 
*/
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
    Node* temp = head;
    Node* newNode = new Node(value); 

    // Assign to head if the list is empty
    if (temp == NULL)
    {
        head = newNode;
        return; 
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next; 
        }
        
        newNode->next = NULL; 
        temp->next = newNode; 
    }
}


/*!
* Insert a LinkedListNode between two existing nodes or after the last node.
* previousValue, value reference between which nodes to insert. 
*/
void LinkedList::insert(int previousValue, int value)
{
    int previousElement = this->lookupElement(previousValue); 
    int counter = 0; 
    Node *previousNode = head; 
    Node *newNode = new Node(value); 

    // guard against values not found in the linked list: 


    if(previousNode->next == NULL)
    {
        previousNode->next = newNode; 
        newNode->next = NULL;   // set this as the tail of the linked list. 
    }

    // first iterate to the previousValue node. 
    while (counter < previousElement)
    {
        previousNode = previousNode->next; 
        counter++;
    } 
    // two ways this could go: 
    // 1. The more common case where it is in the middle of the LinkedList.
    if (previousNode->next != NULL)
    {
        Node* nextNodeTemp = previousNode->next;   // break the link to temp->next, point temp->next to newNode, point newNode to previous temp->next
        previousNode->next = newNode; 
        newNode->next = nextNodeTemp; 
    }
    else        // 2. The edge case is previousValue is found at the last node. 
    {
        previousNode->next = newNode; 
        newNode->next = NULL; 
    }
}

/*!
*
*/
void LinkedList::insertByIndex(int previousIndex, int value) {
    ; 
}

/*!
* Remove a specific LinkedListNode from its stored value. 
*/
int LinkedList::remove(int elementIndex)
{
    // guard against out of bounds.
    int maxElement = this->get_size(); 
    int status = -1; 

    if ((elementIndex > maxElement) || (elementIndex < 0)) {
        cout << "Element " << elementIndex << " is out of bounds!\n\n"; 
        return status; 
    }

    // Does this need some kind of guard statement to throw an exception if linked list has no more nodes? 
    int counter = 0;

    // IF head == null { return NULL} edge case
    if(head == NULL)
    {
        cout << "A Node cannot be removed from an empty list.\n";   // is there a better way to do this with like, an exception?
        return status; 
    }
    
    // IF index == 0 (head): newHead = head.next; head.next = NULL edge case.
    if(elementIndex == 0) {
        Node *newHead = head->next; 
        head->next = NULL; // break the link from head to head->next.
        head->~Node(); // destruct the existing head node (garbage collecting.)
        head = newHead; //reassign the new head node. 
        status = 0;
        return status; 
    }
 
    Node *currentNode = head; 
    Node *previousNode = NULL; 

    // iterate through the linked list until currentNode is set to our target. 
    while ((counter < elementIndex) && (currentNode != NULL))
    {
        previousNode = currentNode;  // set the previous node (initialized to NULL)
        currentNode = currentNode->next; // iterate to the next node. 
        counter++;  // always remember to increment or you're going nowhere...
    }
    
    if (currentNode != NULL) {
        previousNode->next = currentNode->next; 
        currentNode->next = NULL; 
        status = 0; 
    } 
    else {
        cout << "Index not found, could not be removed.\n"; 
        return status; 
    }

    return status; 
}

/*!
*
*/
int LinkedList::removeByValue(int value) {
    int status = -1; // defaults to error code. 
    return status; 
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
    int value = this->head->data; 
    Node* newHead = this->head->next; 
    this->head->~Node();
    this->head = newHead;
    // cout << "Pop!\n"; 
    return value; 
}


/*!
* Return the `element_number` based on the `value`. 
*/
int LinkedList::lookupElement(int value)
{
    Node* temp = head; 
    int element_number = 0; 

    while(temp->data != value)
    {
        element_number++; 
        if (temp->next == NULL)
        {
            cout << "Value not found.\n";
            return -1; 
        }
        else
        {
            temp = temp->next; 
        }
    }
    
    return element_number;
}


/*!
* Return the `value` of a specific `element_number`.
*/
int LinkedList::lookupValue(int element_number)
{
    Node* temp = head; 
    int counter = 0; 
    int max_element = this->get_size() - 1; 
    int value = -1; 

    // guard against out of bounds.
    if ((element_number > max_element) || (element_number < 0)) {
        cout << "Element " << element_number << " is out of bounds!\n\n"; 
        return value; 
    }

    // iterate until element_number located. 
    while(counter <= max_element) {
        if (counter == element_number){
            value = temp->data; 
            break; 
        }
        else {
            temp = temp->next;
            counter++; 
        }
    }

    return value; 
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
