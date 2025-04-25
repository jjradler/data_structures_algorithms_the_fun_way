# Notes:  Binary Search

An efficient algorithm for efficiently searching a *sorted* list for a target value by repeatedly dividing a list in half, determining which of the two halves contains the target, and whittling it down by discarding the other half. 

Searching lists happens all the time in programming, and the *binary search* highlights how important the **structure** of the data is with regards to the efficiency of an algorithm. Binary search is also easily audited for correctness. 

According to Kubica, it is also an excellent lens for viewing the difference in data storage techniques (*i.e.,* the data structures) like the difference between linked lists and arrays, and the motivation behind many tree-based algorithms. 

## Problem:

> Given a set of $N$ data points $X = \{x_1, x_2, …, x_N\}$ and a target value $x'$, find a point $x_i \in X$ such that $x’ = x_i$, or indicate that no such point exists in $X$. 

In other words, “Find me a thing within this other collection of things.”



## Option #1: Linear Scan

This is a brute-force method where you scan the *entire* list for the presence of an object, regardless of order or indexing. 

For example, assume our `target = 21`. 

```pseudocode
LinearScan(Array: A, Integer: target):
	Integer: i = 0
	WHILE i < length(A):
		IF A[i] == target:
			return i
		i = i + 1
	return -1	
```

We define our linear scan function `LinearScan` to ingest an array `A` and `target` value. Essentially, scan the *entire* array and return the *index* of the value. Otherwise, if the target does not exist, `return -1`. 

In `C++`, a very simple, naive implementation of linear scan might look like: 

```C++
int linearScan(int *A, int target)
{
  int i = 0;
  int N = sizeof A; 
  
  while(i < N)
  {
    if(A[i] == target)
    {
      return i;	// found it! 
    }
  	i++;
  }
  // this is essentially the fall-through case where nothing is found. 
  return -1;
}
```

I might also use the `chrono` library in `C++` like this in the `main.cpp` module:

``` c++
#include <chrono>
#include <iostream> 
#include "linear_scan.h"
using namespace std::chrono; 

int main()
{
  // set up the array to search. 
  int A[11] = {3, 11, 9, 37, 7, 8, 1, 21, 5, 17, 31};
  int target, targetIndex; 
  
  // first we'll time the case of a value in the middle of the array.
  target = 8; 
  auto start = high_resolution_clock::now();
	
  targetIndex = linearScan(A, target);

  auto stop = high_resolution_clock::now(); 
  auto dt = duration_cast<nanoseconds>(stop - start); 
  std::cout << "Linear Scan returned target index =" << targetIndex << "in "<< dt.count() << " ns." << endl; 

  // now the case for if the value does not exist in the array. 
  auto start = high_resolution_clock::now();

  target = 2; 
	targetIndex = linearScan(A, target); 

  stop = high_resolution_clock::now(); 
  dt = duration_cast<nanoseconds>(stop - start); 
  std::cout << "Linear Scan returned target index =" << targetIndex << "in "<< dt.count() << " ms." << endl; 

	return 0;   
}
```

There are sometimes ways to make linear scan faster by comparison, but instead we can move on to Option #2. 

**Sidenote:** This example with the runtime comparisons gets me thinking that I need to learn if/how to wrap other functions within a timer function in C++. I’m certain there is a way to do it cleanly and simply in a reusable way. Right now I’ll just brute-force it. 

## Option 2:  Binary Search

