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
using namespace std; 
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

**Update:** I created a quick and dirty wrapper function in `main.cpp` that will time the execution for each block of linearScan searches. It’s ugly, but I think it works. 

## Option 2:  Binary Search

Find a target value in a *sorted* list. This only works on sorted data. It will work on data sorted in both increasing or decreasing order, but to start consider the increasing order case.

1. Sort the data in increasing order. 
2. Partition the list $X$ in half. 
3. Determine which half of the data $v\subset X$ *must* contain the target. 
4. Discard the other half (the complement) of $X$ where the target does not exist. 
5. Repeat the process with subsequent halves that must contain the data. 

For example, consider the value `target = 7` in set $X = \{1, 2, 3,4,5,6,7,8,9\}$. 

We see that for the nine integers in $X$ that the midpoint is at value `5`. Crucially, we know since this list is sorted, any value before the midpoint (value `5`) must be less than the midpoint value. Additionally, we know that since `7 > 5`, we can discard everything before the midpoint value confidently since the subset before `5` *must* be less than target value `7`. 

More formally, considering a *sorted array* $A$: 

> $A[i] \leq A[j]$ for any pair of indices $i$ and $j$ such that $i \lt j$.

Binary search tracks the current search space with two bounds: 

1. the upper bound `IndexHigh`: marks the highest index of the array that is part of the active search space. 
2. the lower bound `IndexLow`: marks the lowest index of the array that is part of the active search space. 

Therefore, if the target value $v$ is in the array, we guarantee that: 

> `A[IndexLow]` $\leq v \leq$ `A[IndexHigh]`

Each iteration begins by choosing the *midpoint of the current search space.*

```pseudocode
IndexMid = Floor((IndexHigh + IndexLow) / 2)
```

`Floor` is here a mathematical function that will round the number down to an integer. 

Compare the value at the middle location `A[IndexMid]` with the target value `v`. 

Now comes a conditional branch: 

```pseudocode
IF A[IndexMid] == v:
	RETURN IndexMid
ELSEIF A[IndexMid] < v:
	IndexLow = IndexMid + 1
ELSE
	IndexHigh = IndexMid - 1
```

Putting this together, we see a the initialization and first iteration would look like:

```pseudocode
Array: A[N]
Int: IndexHigh = N - 1
Int: IndexLow = 0

Type: v 	// target value

// this only represents the initial evaluation. The following will be within 
// a loop in an actual implementation. 
Int: IndexMid = Floor((IndexHigh + IndexLow) / 2)

IF A[IndexMid] == v:
  RETURN IndexMid
ELSEIF A[IndexMid] < v:
  IndexLow = IndexMid + 1
ELSEIF A[IndexMid] > v:
  IndexHigh = IndexMid - 1
```

So how to deal with absent values? We need to confirm if the value is in the array at all. How does Binary Search accomplish this? 

In the case of Linear Scan we know that if we hit the end of the list and do not find the value, we know it cannot be in the array. For binary search we test the index bounds themselves. How does this work? 

As the search progresses, we know that `IndexHigh` and `IndexLow` grow closer together (converge) *until there are no unexplored values between them.*

Since we are always moving the bounds *past the midpoint index*, we can stop the search when IndexHigh < IndexLow. At that point, we can guarantee the value is *not* in the list. 

The simplest way I can think of doing this is to set the condition of a `WHILE` loop such that the loop continues while `IndexLow <= IndexHigh`, then when the loop terminates without returning another index, the fall-through case is `RETURN -1`. 

Combining this case with the other requirements, we can put together an algorithm for binary search using a single loop that looks like this: 

```pseudocode
Array: A[N]
Int: IndexLow = 0
Int: IndexHigh = N - 1
Int: IndexMid
Type: v		// target value

WHILE(IndexLow <= IndexHigh)
	IndexMid = Floor((IndexHigh + IndexLow) / 2)
	IF A[IndexMid] == v:
		RETURN IndexMid
	ELSEIF A[IndexMid] < v: 
		IndexLow = IndexMid + 1
	ELSE
		IndexHigh = IndexMid - 1

RETURN -1	// fallthrough case. 
	
```

Now I’ll try to adapt this to C++ code in my project repository for the book workthrough.

This seems to work, and now I run comparisons with a short array of 11 elements against linear scan. 

The common denominator after a few iterations of performance tests shows that the binary search is much more reliable on this processor in terms of its execution time, whereas the linear scan varies quite a bit. However, returning a “not found” value takes far less time with the binary search. This suggests scaling binary search to larger data sets to be far better than a linear scan.

### Adapting Binary Search to Other Problems: 

Stuff 



### Runtime Analysis:

Stuff



