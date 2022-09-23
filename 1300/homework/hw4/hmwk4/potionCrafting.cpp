// potionCrafting.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 4 - Problem 3
#include <iostream>

using namespace std;

int main(){

    int honeycomb, dandelion, coal, toadstool, input;
    int  mana = 0;
    int healing = 0;

    do {
    cout << "Select a potion crafting priority:\n" 
         << "1. Minor Mana\n" << "2. Minor Healing" << endl;
    cin >> input;
    if (input != 1 && input != 2) {
        cout << "Invalid input." << endl;
    }
    } while(input != 1 && input != 2);

    do {
    cout << "How many Honeycombs do you have?" << endl;
    cin >> honeycomb;
    if (honeycomb < 0) {
        cout << "Invalid input. ";
    }
    } while(honeycomb < 0);
    do {
    cout << "How many Dandelions do you have?" << endl;
    cin >> dandelion;
    if (dandelion < 0) {
        cout << "Invalid input. ";
    }
    } while(dandelion < 0);
    do {
    cout << "How many Coal do you have?"<< endl;
    cin >> coal;
    if (coal < 0) {
        cout << "Invalid input. ";
    }
    } while(coal < 0);
    do {
    cout << "How many Toadstools do you have?" << endl;
    cin >> toadstool;
    if (toadstool < 0) {
        cout << "Invalid input. ";
    }
    } while(toadstool < 0);
    
    if (input == 1) {
        while (honeycomb >= 5 && dandelion >= 3 && coal >=1){
            ++mana;
            honeycomb -= 5;
            dandelion -=3;
            --coal; 
        }
        while (honeycomb >=5 && coal >= 2 && toadstool >= 3){
            ++healing;
            honeycomb -= 5;
            coal -= 2;
            toadstool -=3;
        }
        cout << "You can make " << mana << " Mana potion(s) and " << healing << " Healing potion(s)." << endl;
    }
    if (input == 2) {
        while (honeycomb >=5 && coal >= 2 && toadstool >= 3){
            ++healing;
            honeycomb -= 5;
            coal -= 2;
            toadstool -=3;
        }
        while (honeycomb >= 5 && dandelion >= 3 && coal >=1){
            ++mana;
            honeycomb -= 5;
            dandelion -=3;
            --coal; 
        }
        cout << "You can make " << healing << " Healing potion(s) and " << mana << " Mana potion(s)." << endl;
    }

    

    return 0;
}