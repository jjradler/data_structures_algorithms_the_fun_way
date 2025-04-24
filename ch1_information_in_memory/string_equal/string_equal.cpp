#include "string_equal.h"
#include <iostream>

bool stringEqual(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
    {
        return false;
    }

    int N = s1.length();
    int i = 0;

    while((i < N) && (s1[i] == s2[i]))
    {
        i = i + 1;
    }

    return (i == N);
}
