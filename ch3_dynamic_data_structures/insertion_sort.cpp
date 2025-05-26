/*
 * insertion_sort.cpp
 */
#include "insertion_sort.h"

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
