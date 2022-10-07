// fullClass.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 5 

#include <iostream>

using namespace std;

int fullClass(bool classroom[][4], int rows, int waitlist) {
    if (rows <= 0) {
        cout << "Remaining Students: " << waitlist << endl;
        return 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            if (classroom[i][j] == false && waitlist > 0) {
                classroom[i][j] = true;
                waitlist--;
            }
            cout << classroom[i][j];
        }
        cout << endl;
    }
    cout << "Remaining Students: " << waitlist << endl;
    return waitlist;
}

int main() {

bool classroom[4][4] = {{0, 1, 1, 1},
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 0, 1}};
int waitlist = 6;
fullClass(classroom, 4, waitlist);

    return 0;
}