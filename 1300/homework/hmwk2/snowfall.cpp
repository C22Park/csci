// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
//Homework 2 - Problem #4

#include <iostream>

using namespace std;

int main(){
    
    int days, breckenridge, vail, copper_mountain;
    cout << "How many days in the future would you like a prediction for?" << endl;
    cin >> days;
    breckenridge = 25 + 10*days - 5*days;
    vail = 28 + 14*days - 2*days;
    copper_mountain = 40 + 5*days - 3*days;
    cout << "Breckenridge will have " << breckenridge << " inches, Vail will have " << vail << " inches, and Copper Mountain will have " << copper_mountain << " inches." << endl;

    return 0;
}