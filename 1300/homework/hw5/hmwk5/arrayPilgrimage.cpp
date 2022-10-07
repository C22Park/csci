// arrayPilgrimage.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 5 - Problem 1 

#include <iostream>

using namespace std;

int main(){

    int distance[10];
    for (int i = 0; i < 10; i++) {
        distance[i] = 5 + i;
    }

    string cities[5] = {"Boulder", "NYC", "LA", "Chicago", "Houston"};

    int sequence[100];
    for (int i = 1; i <= 100; i++) {
        sequence[i - 1] = 6 * i;
    }

    char letters[52];
    int count = 0;
    for (int i = 0; i < 52; i += 2) {
        letters[i] = 65 + count;
        letters[i + 1] = 97 + count;
        count++;
    }

    for (int i = 0; i < 10; i++) {
        cout << distance[i] << endl;
    }
    for (int i = 0; i < 5; i++) {
        cout << cities[i] << endl;
    }
    for (int i = 0; i < 100; i++) {
        cout << sequence[i] << endl;
    }
    for (int i = 0; i < 52; i++) {
        cout << letters[i] << endl;
    }

    return 0;
}