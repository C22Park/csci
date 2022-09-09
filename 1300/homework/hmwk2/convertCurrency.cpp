// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation 305 - Nikhith Sannidi
//Homework 2 - Problem #5

#include <iostream>

using namespace std;

int main(){
    
    int bolts, gold_coins, gems;
    cout << "Enter the number of Bolts:" << endl;
    cin >> bolts;
    gold_coins = bolts/23;
    bolts = bolts%23;
    gems = gold_coins/13;
    gold_coins = gold_coins%13;
    cout << gems << " Gem(s) " << gold_coins << " GoldCoin(s) " << bolts << " Bolt(s)" << endl;

    return 0;
}