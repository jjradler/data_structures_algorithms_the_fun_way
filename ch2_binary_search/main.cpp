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

void linearScanTimer(int *A, int target, int arraySize);

int main()
{
  // set up the array to search through:
  int A[11] = {3, 11, 9, 37, 7, 8, 1, 21, 5, 17, 31};
  int target;


  // first time the case of a value we know is in the middle of the array.
  target = 8;
  linearScanTimer(A, target, 11);
  /*
  auto start = high_resolution_clock::now();
  targetIndex = linearScan(A, target);
  auto stop = high_resolution_clock::now();
  auto dt = duration_cast<microseconds>(stop-start);
  std::cout << "Linear Scan returned index " << targetIndex << " in " << dt.count() << " ms." << std::endl;
  */

  // then time the case of linear scan where the value is NOT in the array.
  target = 2;
  linearScanTimer(A, target, 11);
  /*
  start = high_resolution_clock::now();
  targetIndex = linearScan(A, target);
  stop = high_resolution_clock::now();
  dt = duration_cast<microseconds>(stop-start);
  std::cout << "Linear Scan returned index " << targetIndex << " in " << dt.count() << " ms." << std::endl;
  */

  // then one more at the very beginning
  target = 3;
  linearScanTimer(A, target, 11);

  // and one more at the very end of the array
  target = 17;
  linearScanTimer(A, target, 11);

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
