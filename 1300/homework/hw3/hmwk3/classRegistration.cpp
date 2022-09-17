// classRegistration.cpp

// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
// Homework 3 - Problem 5

#include <iostream>

using namespace std;

int main(){
    
    int input;
    cout << "Select a department: (1)Computer Science (2)Math (3)Science" << endl;
    cin >> input;
    switch (input) {
        case 1:
            cout << "Select a class: (1)Starting Computing (2)Data Structures (3)Algorithms" << endl;
            cin >> input;
            switch (input) {
                case 1:
                cout << "Select a section: (1)Section 100 (2)Section 200" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 100 of Starting Computing!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 200 of Starting Computing!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;
                }
                break;
                case 2:
                cout << "Select a section: (1)Section 101 (2)Section 201" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 101 of Data Structures!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 201 of Data Structures!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;
                }
                break;
                case 3:
                cout << "Select a section: (1)Section 102 (2)Section 202" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 102 of Algorithms!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 202 of Algorithms!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }
            break;
        case 2:
            cout << "Select a class: (1)Calculus 1 (2)Calculus 2 (3)Linear Algebra" << endl;
            cin >> input;
            switch (input) {
                case 1:
                cout << "Select a section: (1)Section 400 (2)Section 500" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 400 of Calculus 1!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 500 of Calculus 1!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                case 2:
                cout << "Select a section: (1)Section 401 (2)Section 501" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 401 of Calculus 2!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 501 of Calculus 2!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                case 3:
                cout << "Select a section: (1)Section 402 (2)Section 502" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 402 of Linear Algebra!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 502 of Linear Algebra!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }  
            break;          
        case 3:
            cout << "Select a class: (1)General Chemistry 1 (2)Physics 1" << endl;
            cin >> input;
            switch (input) {
                case 1:
                cout << "Select a section: (1)Section 700 (2)Section 800" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 700 of General Chemistry 1!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 800 of General Chemistry 1!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                case 2:
                cout << "Select a section: (1)Section 701 (2)Section 801" << endl;
                cin >> input;
                switch (input) {
                    case 1:
                    cout << "You've been enrolled in Section 701 of Physics 1!" << endl;
                    break;
                    case 2:
                    cout << "You've been enrolled in Section 801 of Physics 1!" << endl; 
                    break;
                    default:
                    cout << "Please enter a valid input." << endl;
                    break;

                }
                break;
                default:
                cout << "Please enter a valid input." << endl;
                break;
            }            
            break;
            default:
            cout << "Please enter a valid input." << endl;
            break;
    }
    


    return 0;
}