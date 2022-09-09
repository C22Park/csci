// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
//Homework 2 - Problem #3

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    
    long int carton_base, carton_height,cubic_inches;
    cout << "What is the side length of the base of the carton in inches?" << endl;
    cin >> carton_base;
    carton_base *= carton_base;
    cout << "What is the height of the carton in inches?" << endl;
    cin >> carton_height;
    cubic_inches = carton_base*carton_height;
    cout << "The carton has a volume of " << fixed << setprecision(1) << cubic_inches*0.55 << " ounces." << endl;

    return 0;
}