// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
//Homework 2 - Problem #6

#include <iostream>
#include <cmath>

using namespace std;

int main(){
    
    int x;
    double sigmoid;
    cout << "Enter a value for x:" << endl;
    cin >> x;
    sigmoid = 1/(1+exp(-x));
    cout << "The sigmoid for x=" << x << " is " << sigmoid << endl;

    return 0;
}