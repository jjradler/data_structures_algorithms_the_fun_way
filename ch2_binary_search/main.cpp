/*
 * main.cpp
 * Test/illustration module that runs the different search algorithms that are
 * developed in Chapter 3 of Data Structures and Algorithms The Fun Way by
 * Jeremy Kubica. His examples are written in pseudocode, so this is my
 * adaptation of the algorithms and my own illustration/test structures to
 * make sure my implementations are correct.
 *
 * Joseph J. Radler
 * 2025/04/24
 */
#include <iostream>
#include <chrono>
#include <array>

using namespace std::chrono;
#include "linear_scan.h"
#include "binary_search.h"

void linearScanTimer(int *A, int target, int arraySize);
void binarySearchTimer(int *A, int target, int arraySize);

int main()
{
  // set up the array to search through:
  int A[11] = {3, 11, 9, 37, 7, 8, 1, 21, 5, 17, 31};
  int target;


  // first time the case of a value we know is in the middle of the array.
  target = 8;
  linearScanTimer(A, target, 11);

  // then time the case of linear scan where the value is NOT in the array.
  target = 2;
  linearScanTimer(A, target, 11);

  // then one more at the very beginning
  target = 3;
  linearScanTimer(A, target, 11);

  // and one more at the very end of the array
  target = 17;
  linearScanTimer(A, target, 11);

  // Now moving on to testing a binary search timer.
  target = 8;
  binarySearchTimer(A, target, 11);

  target = 2;
  binarySearchTimer(A, target, 11);

  target = 3;
  binarySearchTimer(A, target, 11);

  target = 17;
  binarySearchTimer(A, target, 11);
  return 0;
}

/*
 * wrapper function for the array linear scan
 */
void linearScanTimer(int *A, int target, int arraySize)
{
  int targetIndex = 0;
  auto start = high_resolution_clock::now();
  targetIndex = linearScan(A, target, arraySize);
  auto stop = high_resolution_clock::now();
  auto dt = duration_cast<nanoseconds>(stop-start);
  std::cout << "Linear Scan returned index " << targetIndex << " in " << dt.count() << " ns." << std::endl;

}


/*
 * wrapper function for binary search timer
 */
void binarySearchTimer(int* A, int target, int arraySize)
{
  int targetIndex = 0;
  auto start = high_resolution_clock::now();
  targetIndex = binarySearch(A, target, arraySize);
  auto stop = high_resolution_clock::now();
  auto dt = duration_cast<nanoseconds>(stop-start);
  std::cout << "Binary Search returned index " << targetIndex << " in " << dt.count() << " ns." << std::endl;
}
