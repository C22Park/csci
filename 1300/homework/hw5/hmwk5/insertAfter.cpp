// insertAfter.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 3a 

#include <iostream>

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

int main() {

    int size = 5;
    string input_strings[size] = {"caterpie", "eevee"};
    int num_elements = 2;
    int index = 0;
    string string_to_insert = "bulbasaur";
    // result contains the value returned by insertAfter
    bool result = insertAfter(input_strings, num_elements, size, index, string_to_insert);
    // print result
    cout << "Function returned value: "<< result << endl;
    // print array contents
    for(int i = 0; i < size; i++) {
        cout << input_strings[i] << endl;
    }
    return 0;
}