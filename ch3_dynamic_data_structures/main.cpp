/*
 * Data Structures the Fun Way by J. Kubicka
 * Implemented in C++ by jjradler 
 * Updated: 2026-03-02
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


  cout << "** BEGIN LINKED LIST TESTS **" << endl; 
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
  testList.addressPrint(); 

  cout << "Testing LinkedList.pop()" << endl; 
  int poppedValue = testList.pop(); 
  cout << "Popped value " << poppedValue << " off the list.\n"; 
  testList.print(); 

  cout << "Testing LinkedList.lookupElement()\n";
  testList.push(poppedValue); 
  cout << "Element 23 is at index: " << testList.lookupElement(23) << endl; 
  cout << "Element 11 is at index: " << testList.lookupElement(11) << endl;
  cout << "Testing element that does not exist... \n ";
  cout << "Element 27 is at index: " << testList.lookupElement(27) << endl; 

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


