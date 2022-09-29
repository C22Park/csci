// alphabeticalTriangle.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 4 - Problem 5 
#include <iostream>

using namespace std;

int main(){
    
    int height;
    int letter_start = 97;
    int string_length = 1;

    cout << "Enter the height: " << endl;
    cin >> height;
    if (height <= 0) {
        cout << "Invalid input." << endl;
    }
    else {
        for (int i = 1; i <= height; i++) {
            for (int c = 0; c < string_length; ++c) {
                cout << char(letter_start);
                ++letter_start;
                if (letter_start > 122) {
                    letter_start = 97;
                }
            }
            string_length += 2;
            cout << endl;
        }
    }

    return 0;
}