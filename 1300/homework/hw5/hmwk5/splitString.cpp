// splitString.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 4 

#include <iostream>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size) {

    if (input_string == "") { // when empty return 0
        return 0;
    }

    int num_elements = 0;
    int start = 0;

        for (int i = 0; i < input_string.length(); i++) {
            if (num_elements + 1 < arr_size) { // as long as the number of elements is less than the size of array put part of string up to seperater into a spot in array
                if (input_string[i] == separator) {
                    arr[num_elements] = input_string.substr(start, i - start);
                    start = i + 1;
                    num_elements++;
                }
                } else if (input_string[i] == separator) { // when the array is smaller than the number of elements puit in the last one you can and return -1
                    arr[num_elements] = input_string.substr(start, i - start);
                    return -1;
                }
        }
    arr[num_elements] = input_string.substr(start, input_string.length() - start); // the final element gets put in from the last seperator to the end of string
    num_elements++;

    return num_elements;
}

int main() {

    string testcase = "RST,UVW,XYZ";
char separator = ',';
int arr_size = 3;
string arr[arr_size];
// num_splits is the value returned by split
int num_splits = split(testcase, separator, arr, arr_size);
cout << "Function returned value: " << num_splits << endl;
for (int i=0; i < arr_size; i++){
  cout << "arr["<< i << "]:" << arr[i] << endl;
}

    return 0;
}