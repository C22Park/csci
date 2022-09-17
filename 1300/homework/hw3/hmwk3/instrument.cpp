// instrument.cpp

// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
// Homework 3 - Problem 6

// #include <iostream>
// using namespace std;

// DO NOT include the above statements in your answer here
// only paste in your main() function
#include <iostream>

using namespace std;

int main(){
    int input;

    cout << "Select a category: (1)Brass (2)Woodwind (3)Percussion" << endl;
    cin >> input;
    switch (input) {
        case 1:
            cout << "Select an instrument: (1)Trumpet (2)Trombone" << endl;
            cin >> input;
            switch (input) {
                case 1:
                    cout << "Your instrument will be $350." << endl;
                    break;
                case 2:
                    cout << "Your instrument will be $400." << endl;
                    break;
                default:
                    cout << "Please enter a valid input" << endl;
                    break;
            }
        break;
        case 2:
            cout << "Select an instrument: (1)Flute (2)Saxophone" << endl;
            cin >> input;
            switch (input) {
                case 1:
                    cout << "Your instrument will be $325." << endl;
                    break;
                case 2:
                    cout << "Your instrument will be $425." << endl;
                    break;
                default:
                    cout << "Please enter a valid input." << endl;
                    break;
            }
        break;
        case 3:
            cout << "Select an instrument: (1)Snare Drum (2)Cymbals" << endl;
            cin >> input;
                switch (input) {
                case 1:
                    cout << "Your instrument will be $275." << endl;
                    break;
                case 2:
                    cout << "Your instrument will be $200." << endl;
                    break;
                default:
                    cout << "Please enter a valid input" << endl;
                    break;
            }
        break;
        default:
            cout << "Please enter a valid input." << endl;
            break;
    }


    return 0;
}