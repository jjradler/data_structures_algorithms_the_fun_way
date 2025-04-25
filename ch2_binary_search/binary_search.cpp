/*
 * Binary Search simplest implementation for an array of integer values.
 * Joseph J. Radler
 * 2025/04/25
 */
#include "binary_search.h"
#include <cmath>
using namespace std;

int binarySearch(int *A, int target, int arraySize)
{
  int indexLow = 0;
  int indexHigh = arraySize - 1;
  int indexMid;

  while(indexLow <= indexHigh)
  {
    indexMid = floor((indexHigh + indexLow) / 2);

    if(A[indexMid] == target)
    {
      return indexMid;
    }
    else if(A[indexMid] < target)
    {
      indexLow = indexMid + 1;
    }
    else
    {
      indexHigh = indexMid - 1;
    }
  }

  return -1;
}

