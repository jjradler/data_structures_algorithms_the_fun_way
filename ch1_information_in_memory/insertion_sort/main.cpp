/*
 * main.cpp
 * Test application of insertion sort code example.
 * jjradler
 * 04/24/25
 */

#include "insertion_sort.h"
#include <iostream>

// void sort(int * a);


int main()
{
    int testArray[10] = {6, 4, 7, 2, 8, 30, 23, 37, 32, 75};
    std::cout << "Original array: [";
    for(int i = 0; i < 10; i++)
    {
        std::cout << testArray[i] << " ";
    }

    std::cout << "]" << std::endl;

    sort(testArray);

    std::cout << "Sorted Array: [";

    for(int i = 0; i < 10; i++)
    {
        std::cout << testArray[i] << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}

/*
void sort(int *A)
{
    int n = sizeof A;
    int i = 1;  // why do we start at 1?

    while(i < n)
    {
        int  current = A[i];
        int j = i - 1;

        while(j >= 0 && A[j] > current)

        {
            A[j + 1] = A[j];
            j = j - 1;
        }

        A[j + 1] = current;
        i = i + 1;
    }
}
*/
