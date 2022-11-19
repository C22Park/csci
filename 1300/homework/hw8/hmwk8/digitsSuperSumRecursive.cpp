// digitsSuperSumRecursive.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 8 - Problem 1

#include <iostream>
#include <cassert>

using namespace std;

/*
    Algorithm:
        If the length of n is 1 or 0 return n
        Otherwise take the last digit in the integer and add it to the other integers repeating until it has a length of one
*/

int digitsSuperSumRecursive(int n)
{
    if (to_string(n).length() <= 1)
    {
        return n;
    } else
    {
        string temp_n = to_string(n);
        int new_n = temp_n[temp_n.length() - 1];
        if (new_n != 0)
        {
            new_n -= 48;
        }
        new_n += digitsSuperSumRecursive(stoi(temp_n.substr(0, temp_n.length() - 1)));
        if (to_string(new_n).length() <= 1)
        {
            return new_n;
        } else 
        {
            return digitsSuperSumRecursive(new_n);
        }
    }
}

int main()
{
    // Tests for digitsSuperSumRecursive()

    assert(digitsSuperSumRecursive(12345) == 6);
    assert(digitsSuperSumRecursive(7319) == 2);
    assert(digitsSuperSumRecursive(94792) == 4);
    assert(digitsSuperSumRecursive(123) == 6);
    assert(digitsSuperSumRecursive(1234567891) == 1);

    return 0;
}