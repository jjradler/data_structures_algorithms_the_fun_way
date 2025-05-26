/*
 *
 */
#include <iostream>
#include "array_double.h"
#include "linked_list.h"
#include <random>

using namespace std;


void arrayPrint(int*, int);


int main()
{
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

  return 0;
}


void arrayPrint(int* a, int arraySize)
{
  cout << "Array = [ ";
  for(int i = 0; i < arraySize; i++)
  {
    cout << a[i] << " ";
  }
  cout << "]" << endl;
}

