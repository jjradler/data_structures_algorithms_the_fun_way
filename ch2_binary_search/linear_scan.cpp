#include <iostream>
#include "linear_scan.h"


int linearScan(int *A, int target, int arraySize)
{
  int i = 0;

  while(i < arraySize)
  {
    // std::cout << "i = " << i << "\tA[i] = " << A[i] << std::endl;
    if(A[i] == target)
    {
        return i; // found it!
    }
    i++;
  }
  // fall-through case where the value is not detected.
  return -1;
}
