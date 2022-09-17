// wifiSpeeds.cpp

// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
// Homework 3 - Problem 4

#include <iostream>

using namespace std;

int main(){
    
    double wifi1, wifi2, wifi3;
    cout << "Enter wifi speeds over the last 3 classes:" << endl;
    cin >> wifi1 >> wifi2 >> wifi3;
    if (wifi1 > 0 && wifi2 > 0 && wifi3 > 0) {
    if (wifi1 < wifi2 && wifi2 < wifi3) {
        cout << "The wifi is getting faster!" << endl;
    }
    else if (wifi1 > wifi2 && wifi2 > wifi3) {
        cout << "The wifi is getting slower!" << endl;
    }
    else {
        cout << "The wifi speed is changing unpredictably." << endl;
    }
    }
    else {
        cout << "Please enter a valid input." << endl;
    }

    return 0;
}