// vacation.cpp

// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
// Homework 3 - Problem 2

#include <iostream>

using namespace std;

int main(){

    double budget;
    char transport;

    cout << "What is your budget?" << endl;
    cin >> budget;
    if (budget >= 0) {
        cout << "What mode of transportation would you like to take (B, T, or A)?" << endl;
        cin >> transport;
        switch (transport){
            case 'B':
                if (budget >= 175.25){
                    cout << "Yes, this vacation is within your budget!" << endl;
                }
                else {
                    cout << "Sorry, this vacation is outside your budget." << endl;
                    break;
                }
                break;
            case 'T':
                if (budget >= 240.66){
                    cout << "Yes, this vacation is within your budget!" << endl;
                }   
                else {
                    cout << "Sorry, this vacation is outside your budget." << endl;
                }
                break;
            case 'A':
                if (budget >= 350.93){
                    cout << "Yes, this vacation is within your budget!" << endl;
                }
                else {
                    cout << "Sorry, this vacation is outside your budget." << endl;
                }
                break;
            default:
                cout << "Please enter a valid input." << endl;
                break;
        }
    }
    else {
        cout << "Please enter a valid input." << endl;
    }

    return 0;
}