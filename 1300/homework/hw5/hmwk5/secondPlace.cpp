// secondPlace.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 3b 

#include <iostream>
#include <cassert>

using namespace std;

bool insertAfter(string input_strings[], int num_elements, int arr_size, int index, string string_to_insert) {
    bool success;

    if (num_elements >= arr_size || index + 1 > arr_size) {
        success = false;
    } else {
        for (int i = 0; i < num_elements - index; i++) { // for all i less than the number of elements after index
            input_strings[num_elements - i] = input_strings[num_elements - 1 - i]; // starting one past the end of array set that equal to previous and move back until youre going to reach index
        }
        input_strings[index + 1] = string_to_insert; // puts the inserted string one space after index
        success = true;
    }

    return success;
}

int secondPlace(string input_strings[], string string_to_insert, string string_to_find, int num_elements, int arr_size, int count) {

    int index;

    if (num_elements + count <= arr_size) { // if the final output can fit in array then run
        for (int i = 0; i < num_elements; i++) {
            if (input_strings[i] == string_to_find) {
                index = i;
                if (insertAfter(input_strings, num_elements, arr_size, index, string_to_insert)) {
                    num_elements++; // you increase the number of elements with the pass by reference
                }
                count--;
            }
        }
    }

    return num_elements;
}

int main() {

int size = 12;
string input_strings[size] = {"clefairy", "charizard", "pikachu", "clefairy" };
int num_elements = 4;
int count = 2;
string string_to_insert = "pichu";
string string_to_find = "clefairy";
// updating num_elements with the updated value returned by secondPlace
num_elements = secondPlace(input_strings, string_to_insert, string_to_find, num_elements, size, count);
// print num_elements
cout << "Function returned value: " << num_elements << endl;
// print array contents
for(int i = 0; i < size; i++)
{
    cout << input_strings[i] << endl;
}

   return 0;
}