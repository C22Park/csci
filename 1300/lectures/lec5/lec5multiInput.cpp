#include <iostream>
#include <cmath>
using namespace std;

int main(){
    // prompt user to enter two numbers at the same time (space separated)
    cout << "Enter two numbers" << endl;
    int num1;
    int num2;
    cin >> num1 >> num2;
    // calculate the sum of the two numbers, print the sum
    cout << "The sum of the two numbers is " << num1 + num2 << endl;
    // calculate the absolute value of the difference of the two numbers, 
    cout << "The difference between the numbers is " << abs(num1 - num2) << endl;
    // print the absolute value of the difference
    

    return 0;
}