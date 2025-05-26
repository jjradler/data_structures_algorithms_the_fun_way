#include "array_double.h"

int* arrayDouble(int *A, int arraySize)
{
  int doubleSize = 2 * arraySize;
  int* arrayPointer = new int[doubleSize];
  int j = 0;
  while(j < arraySize)
  {
    arrayPointer[j] = A[j];
    j++;
  }

  return arrayPointer;
}
