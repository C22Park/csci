// splitString.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 4 

#include <iostream>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
 {

    if (input_string == "")
    {
        return 0;
    }

    int num_elements = 0;
    
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator && num_elements >= arr_size) 
        {
            return -1;
        } else if (input_string[i] == separator)
        {
            num_elements++;
        } else
        {
            arr[num_elements] += input_string[i];
        }
    }
        
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