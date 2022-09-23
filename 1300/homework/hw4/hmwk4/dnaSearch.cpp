// dnaSearch.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 4 - Problem 4
#include <iostream>

using namespace std;

int main(){

    string search_dna, full_dna;
    bool valid_input = true;
    int count = 0;

    cout << "Enter the DNA Sequence:" << endl;
    cin >> full_dna;
    for (int i = 0; i < full_dna.length(); i++) {
        if (full_dna[i] != 'A' && full_dna[i] != 'C' && full_dna[i] != 'G' && full_dna[i] != 'T') {
            cout << "This is not a valid DNA sequence." << endl;
            valid_input = false;
            break;
        }
    }
    
    if (valid_input == true) {
        cout << "Enter the DNA fragment to be searched:" << endl;
        cin >> search_dna;
        for (int i = 0; i < search_dna.length(); i++) {
        if (search_dna[i] != 'A' && search_dna[i] != 'C' && search_dna[i] != 'G' && search_dna[i] != 'T') {
            cout << "This is not a valid DNA sequence" << endl;
            valid_input = false;
            break;
        }
    }            
        if (valid_input == true) {
        for (int i = 0; i < full_dna.length(); ++i) {
            if (full_dna.substr(i, search_dna.length()) == search_dna) {
                ++count;
            }
        }
        cout << "Number of occurrences: " << count << endl;
        }
    }

    return 0;
}