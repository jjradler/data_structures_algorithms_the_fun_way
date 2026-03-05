/* linked_list.cpp
 * Written from Kubica's Data Structures the Fun Way as illustrative example.
  * A slghtly more than barebones implementation of a singly-linked list with some convenience functions just to illustrate
 * how these data structures work (and to polish some of the rust off of my C++ skills with pointers and classes...)
 * Updated to include a barebones doubly-linked list with the same interface as the singly linked list. 
 * Updated: 2026-03-05
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
Node::Node(int value)
{
    data = value; 
    next = NULL;
}


/*! 
* Gozer! The Destructor! 
*/
Node::~Node()
{
    ;
}


/*!
*
*/
DoubleNode::DoubleNode() {
    data = 0; 
    next = NULL; 
    previous = NULL; 
}


/*!
*
*/
DoubleNode::DoubleNode(int value) {
    data = value; 
    next = NULL; 
    previous = NULL; 
}


/*!
*
*/
DoubleNode::~DoubleNode(){
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
* Returns `size` of the entire `LinkedList` as an integer.  
*/
int LinkedList::get_size() {
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
    Node * newNode = new Node(value); 
    Node * currentNode = head; 
    int listLength = this->get_size();
    int currentIndex = 0; 
    
    // guards
    if (previousIndex >= listLength || previousIndex < 0)
    {
        cout << "Index out of range!";
    }

    while(currentIndex < listLength && currentNode->next != NULL)
    {
        if (currentIndex == previousIndex)
        {
            newNode->next = currentNode->next; // case where we found the index. 
            currentNode->next = newNode;
            break; 
        }
        else
        {
            currentNode = currentNode->next;
            currentIndex++; 
        }
    }
}

/*!
* Return the `element_number` based on the `value`. 
*/
int LinkedList::lookupElement(int value) {
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
int LinkedList::lookupValue(int element_number) {
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
* Pops the top (head) node off the linked list, returning the value and resets the second node as the new head. 
*/
int LinkedList::pop() {
    int value = this->head->data; 
    Node* newHead = this->head->next; 
    this->head->~Node();
    this->head = newHead;
    // cout << "Pop!\n"; 
    return value; 
}


/*!
* Print a text value representation of the linked list.
*/
void LinkedList::print() {
    Node *temp = this->head; 

    if (head == NULL)
    {
        cout << "This list is empty.\n"; 
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
void LinkedList::printAddress() {
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


/*!
* Pushes a new node to the front (head) of the list. No return value. 
*/
void LinkedList::push(int data) {
    Node *newNode = new Node(data); 

    // Assign to head if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return; 
    }

    // insert the newly created linked list at the head
    newNode->next = head; // change the reference links. 
    head = newNode; 
}


/*!
*  Remove by value. Return 'value not found' as error condition.
*/
int LinkedList::remove(int value) {
    Node *currentNode = head; 
    Node *previousNode = NULL; 
    int maxElement = this->get_size(); 
    int currentIndex = 0; 
    int status = -1; 

    // IF index == 0 (head): newHead = head.next; head.next = NULL edge case.
    if(this->head->data == value) {
        Node *newHead = head->next; 
        head->next = NULL; // break the link from head to head->next.
        head->~Node(); // destruct the existing head node (garbage collecting.)
        head = newHead; //reassign the new head node. 
        status = 0;
        return status; 
    }

    while(currentNode->data != value)
    {
        if (currentNode->next == NULL)
        {
            cout << "Value not found.\n";
            return status; 
        }
        else
        {
            previousNode = currentNode; 
            currentNode = currentNode->next; 
            currentIndex++; 
        }
    }

    if (currentNode != NULL) {
        previousNode->next = currentNode->next; 
        currentNode->next = NULL; 
        currentNode->~Node();   // garbage collection. 
        status = 0; 
    } 
    else {
        cout << "Index not found, could not be removed.\n"; 
        return status; 
    }

    return status; 
}


/*!
* Remove a specific LinkedListNode from its stored value. 
*/
int LinkedList::removeByIndex(int elementIndex) {
    // guard against out of bounds.
    int maxElement = this->get_size(); 
    int status = -1; 

    if ((elementIndex > maxElement) || (elementIndex < 0)) {
        cout << "Element " << elementIndex << " is out of bounds!\n"; 
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
        currentNode->~Node();   // garbage collection. 
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
DoublyLinkedList::DoublyLinkedList() {
    head = NULL;
}


/*!
*
*/
DoublyLinkedList::~DoublyLinkedList() {
    ;
}


/*!
*
*/
void DoublyLinkedList::append(int value) {
    DoubleNode* temp = head;
    DoubleNode* newNode = new DoubleNode(value); 

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
        newNode->previous = temp; 
        temp->next = newNode; 
    }
}


/*!
*
*/
int DoublyLinkedList::get_size() {
    int counter = 0;
    DoubleNode* temp = head; 

    if (head == NULL)
    {
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
*
*/
void DoublyLinkedList::insert(int previousValue, int insertValue) 
{
    int previousElement = this->lookupElement(previousValue); 
    int counter = 0; 
    DoubleNode *previousNode = head; 
    DoubleNode *newNode = new DoubleNode(insertValue); 

    // guard against values not found in the linked list: 


    if(previousNode->next == NULL)
    {
        previousNode->next = newNode; 
        newNode->next = NULL;   // set this as the tail of the linked list. 
        newNode->previous = head; 
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
        DoubleNode* nextNodeTemp = previousNode->next;   // break the link to temp->next, point temp->next to newNode, point newNode to previous temp->next
        previousNode->next = newNode; 
        newNode->previous = previousNode; 
        newNode->next = nextNodeTemp; 

    }
    else        // 2. The edge case is previousValue is found at the last node. 
    {
        previousNode->next = newNode; 
        newNode->next = NULL; 
        newNode->previous = previousNode; 
    }
}


/*!
*
*/
void DoublyLinkedList::insertByIndex(int previousIndex, int elementValue) {
    DoubleNode * newNode = new DoubleNode(elementValue); 
    DoubleNode * currentNode = head; 
    int listLength = this->get_size();
    int currentIndex = 0; 
    
    // guards
    if (previousIndex >= listLength || previousIndex < 0)
    {
        cout << "Index out of range!";
    }

    while(currentIndex < listLength && currentNode->next != NULL)
    {
        if (currentIndex == previousIndex)
        {
            // TODO: DOUBLE CHECK THAT THERE DOESN'T NEED TO BE A NEXT->NEXT->PREVIOUS POINTER RESET. 
            newNode->next = currentNode->next; // case where we found the index.
            currentNode->next->previous = newNode;  
            currentNode->next = newNode;
            newNode->previous = currentNode; 
            break; 
        }
        else
        {
            currentNode = currentNode->next;
            currentIndex++; 
        }
    }
} 


/*!
*
*/
int DoublyLinkedList::lookupElement(int elementValue) {
    DoubleNode* temp = head; 
    int element_number = 0; 

    while(temp->data != elementValue)
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
*
*/
int DoublyLinkedList::lookupValue(int elementNumber) {
    DoubleNode* temp = head; 
    int counter = 0; 
    int max_element = this->get_size() - 1; 
    int value = -1; 

    // guard against out of bounds.
    if ((elementNumber > max_element) || (elementNumber < 0)) {
        cout << "Element " << elementNumber << " is out of bounds!\n\n"; 
        return value; 
    }

    // iterate until element_number located. 
    while(counter <= max_element) {
        if (counter == elementNumber){
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
*
*/
int DoublyLinkedList::pop() {
    if (head == NULL)
    {
        cout << "This list is empty!\n"; 
        return -1; 
    }

    int value = head->data; 
    DoubleNode* newHead = head->next; 
    head->~DoubleNode();
    head = newHead;
    newHead->previous = NULL;
    return value; 
}


/*!
*
*/
void DoublyLinkedList::print() {
    DoubleNode *temp = this->head; 

    if (head == NULL)
    {
        cout << "This list is empty.\n"; 
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
* Prints the values in the list alongside their addresses in memory with pointers to previous and next. This is useful for troubleshooting 
* development of the doubly linked list as it can highlight where pointers might be dangling or should be set to NULL (0x0). Formatting
* for the output is `node->previous address <- node_value = node_address -> node_next_address'. 
* 
*/
void DoublyLinkedList::printAddress()
{
    DoubleNode *temp = head; 

    if (head == NULL)
    {
        cout << "This list is empty.\n" << endl; 
        return;
    }

    while (temp != NULL)
    {
        cout << temp->previous << " <- " << temp->data << " = " << temp << " -> " << temp->next << endl;
        temp = temp->next; 
    } 
    cout << endl; 
}


/*!
*
*/
void DoublyLinkedList::push(int value) {
    DoubleNode *newNode = new DoubleNode(value); 

    // Assign to head if the list is empty
    if (head == NULL)
    {
        head = newNode;
        return; 
    }

    // insert the newly created linked list at the head
    newNode->next = head; // change the reference links. 
    head->previous = newNode; 
    head = newNode; 
}


/*!
*
*/
int DoublyLinkedList::remove(int value) {
    return 0;
}


/*!
*
*/
int DoublyLinkedList::removeByIndex(int elementIndex) {
    return 0;
}
