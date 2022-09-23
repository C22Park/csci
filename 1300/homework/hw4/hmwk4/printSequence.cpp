// printSequence.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 4 - Problem 2
#include <iostream>

using namespace std;

int main(){

    int input;
    cout << "Enter a value between 1 and 1000:" << endl;
    cin >> input;
    while (input <= 1 || input >= 1000) {
        cout << "Invalid input." << endl;
        cout << "Enter a value between 1 and 1000:" << endl;
        cin >> input;
    }
    do {
        cout << input << endl;
        if (input % 2 == 0) {
            input = input / 2;
        }
        else {
            input = 3*input + 1;
        }
    } while (input > 1);
    cout << input << endl;

    return 0;
}