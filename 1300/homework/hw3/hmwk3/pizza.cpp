// pizza.cpp

// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
// Homework 3 - Problem 3

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    char pizza_size;
    int pizza_toppings;
    cout << "What size pizza would you like to order?" << endl;
    cin >> pizza_size;
    if (pizza_size == 'S' || pizza_size == 'M' || pizza_size == 'L') {
    cout << "How many toppings do you want?" << endl;
    cin >> pizza_toppings;
    if (pizza_size == 'S' && pizza_toppings >= 0) {
            cout << "Your total is $" << fixed << setprecision(2) << 4.99 + pizza_toppings*.75 << endl;
    }
    else if (pizza_size == 'M' && pizza_toppings >= 0) {
            cout << "Your total is $" << fixed << setprecision(2) << 5.99 + pizza_toppings*1.5 << endl;
    }
    else if (pizza_size == 'L' && pizza_toppings >= 0) {
            cout << "Your total is $" << fixed << setprecision(2) << 6.99 + pizza_toppings*2.25 << endl;
    }
    else {
        cout << "Please enter a valid input." << endl;
    }
    }
    else {
        cout << "Please enter a valid input." << endl;
    }

    return 0;
}