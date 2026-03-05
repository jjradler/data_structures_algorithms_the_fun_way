/*!
 * Data Structures the Fun Way by J. Kubicka
 * Implemented in C++ by jjradler 
 * Created: 2026-03-01
 * Updated: 2026-03-05
 */

#include <iostream>
#include "array_double.h"
#include "linked_list.h"
#include <random>

using namespace std;

void arrayPrint(int*, int);

int main()
{
  cout << "** BEGIN ARRAY CONSTRUCTION AND MANIPULATION TESTS **\n"; 
  const int arraySize = 10;
  int A[arraySize];

  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(1, 100);

  for(int i = 0; i < arraySize; i++)
  {
    int dice_roll = distribution(generator);  // generate a number between 1 and 100
    A[i] = dice_roll;
  }

  arrayPrint(A, arraySize);

  int *newArrayPointer = arrayDouble(A, arraySize);
  arrayPrint(A, arraySize * 2);
  cout << "New Array Size after Doubling = " << arraySize * 2  << endl;
  cout << endl;


  cout << "\n** BEGIN LINKED LIST TESTS **" << endl; 
  LinkedList testList;  
  cout << "testList size is set to " << testList.get_size() << endl; 

  testList.push(11); 
  cout << "testList size is set to " << testList.get_size() << endl; 

  testList.push(23); 
  cout << "testList size is now: " << testList.get_size() << endl; 

  // and again, to get out of the first-node edge case. 
  testList.push(245);    // so far so good! 
  cout << "testList size is now: " << testList.get_size() << endl;

  testList.print(); 
  testList.printAddress(); 

  cout << "Testing LinkedList.pop()" << endl; 
  int poppedValue = testList.pop(); 
  cout << "Popped value " << poppedValue << " off the list.\n"; 
  testList.print(); 

  cout << "\n** Testing LinkedList.lookupElement() **\n";
  testList.push(poppedValue); 
  cout << "Element 23 is at index: " << testList.lookupElement(23) << endl; 
  cout << "Element 11 is at index: " << testList.lookupElement(11) << endl;
  cout << "Testing element that does not exist... \n ";
  cout << "Element 27 is at index: " << testList.lookupElement(27) << endl; 

  cout << "\n** Testing LinkedList.append() **\n"; 
  testList.append(27); 
  testList.print(); 
  
  cout << "Element 27 is at index: " << testList.lookupElement(27) << endl; 
  
  cout << "\n** Testing LinkedList.lookupValue() **\n"; 
  cout << "Value at index " << 3 << " is: " << testList.lookupValue(3) << endl; 
  cout << "Value at index " << 0 << " is: " << testList.lookupValue(0) << endl; 
  testList.lookupValue(5); // this should yield an error message and return -1. 
  testList.lookupValue(-2); // this should also yield an error. 
  testList.lookupValue(4); // this should also yield an error. 

  cout << "\n**Testing LinkedList.insert()**\n";
  testList.insert(11, 314); // insert node 314 after node with value 11
  testList.printAddress(); // diagnostic testprint. 
  testList.insert(27, 42); 
  testList.printAddress(); 

  cout << "\n** Testing testList.remove(value) **\n"; 
  testList.print(); 
  testList.remove(42);
  testList.print(); 
  testList.append(42); 
  testList.print(); 
  testList.remove(314); 
  testList.print(); 
  testList.insert(11, 314); 
  testList.print(); 
  testList.remove(245); 
  testList.print(); 
  testList.push(245); 
  testList.print(); 

  cout << "\n** Testing LinkedList.insertByIndex() ** \n";
  testList.insertByIndex(0, 5); 
  testList.print();
  testList.remove(5); 
  testList.print(); 
  testList.removeByIndex(0); 
  testList.print();
  testList.push(245);
  testList.print(); 
  testList.insertByIndex(5,5); 
  testList.print();
  testList.removeByIndex(5); 
  testList.print(); 
  testList.append(42); 

  cout << "\n** Testing LinkedList.removeByIndex() ** \n";
  testList.print();
  cout << "testList.removeByIndex(0) status: " << testList.removeByIndex(0) << endl; // should remove the head node and test an edge case. 
  testList.print();
  testList.push(245); 
  cout << "testList.removeByIndex(3) status: " << testList.removeByIndex(3) << endl;
  testList.print();
  testList.insert(11, 314); 
  testList.print();
  cout << "testList.removeByIndex(4) status: " << testList.removeByIndex(4) << endl;
  testList.print();
  testList.insert(314, 27); 
  testList.print(); 
  cout << "testList.removeByIndex(5) status: " << testList.removeByIndex(5) << endl;
  testList.print(); 
  cout << "Trying that again should yield an error...\n";
  cout << "testList.removeByIndex(5) status: " << testList.removeByIndex(5) << endl;
  testList.print();
  cout << "The following three tests should all show errors...\n";

  LinkedList testList2;  // create a new empty list. 
  testList2.removeByIndex(0); // should return an error because it is empty. 
  testList2.removeByIndex(1); 
  testList2.removeByIndex(-1); 
  testList2.~LinkedList(); 
  cout << "\n ** END SINGLY LINKED LIST TESTS **\n";

  cout << "\n ** BEGIN DOUBLY LINKED LIST TESTS ** \n";
  DoublyLinkedList testList3; 
  testList3.print();
  testList3.push(1); 
  testList3.print();
  testList3.push(3); 
  testList3.print(); 
  testList3.push(5); 
  cout << "testList3 size = " << testList3.get_size() << endl;
  testList3.append(7);
  testList3.append(9);
  cout << "testList3 size is now = " << testList3.get_size() << endl; 
  cout << "Popped value: " << testList3.pop() << " off testList3.\n"; 
  testList3.print();
  testList3.insert(7, 8); 
  testList3.print();
  testList3.insertByIndex(2, 5);
  testList3.print();
  testList3.printAddress(); 

  testList3.~DoublyLinkedList(); 
  cout << "\n ** END DOUBLY LINKED LIST TESTS ** \n"; 
  // TODO: Add a test harness to this repository, maybe using Unity or CPPUTest? 

  return 0;
}


/*! 
* Convenience Function for representing an array for testing array doubling functions. 
*/
void arrayPrint(int* a, int arraySize)
{
  cout << "Array = [ ";
  for(int i = 0; i < arraySize; i++)
  {
    cout << a[i] << " ";
  }
  cout << "]" << endl;
}
