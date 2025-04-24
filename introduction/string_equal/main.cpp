/*
 * introduction/string_equal/main.cpp
 * Test application for string_equal implementation from J. Kubica.
 * 2025/04/24
 * Joseph J. Radler
 */
#include "string_equal.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;

    cout << "String 1:\t";
    getline(cin, s1);
    cout << "String 2:\t";
    getline(cin, s2);

    bool result = stringEqual(s1, s2);

    if(result == true)
    {
        cout << "They are equal.";
    }
    else
    {
        cout << "They are NOT equal!";
    }

    return 0;
}
