// isValidTune.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 1 - Problem 2

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/*
    Algorithm: Finds whether the input is a valid note in SPN
    1. Accept note which is passed to function
    2. Declare string check_note as A0
    3. Declare bool is_valid as false
    4. Repeat 5-8 until check_note is G9
    5. Repeat 6-7 until check_note has 9 at the end
    6. If note is the same as check_note set is_valid to true
    7. Add one to the number of check_note
    8. Go up one letter in alphabet for check_note and set the number to 0
    Parameters: string note
    Returns: is_valid
*/

bool isValidNote(string note) {

    bool is_valid = false;
    string check_note = "A0"; // first note it checks with input

    for (int n = 65; n <= 71; n++) { // n is the number for the ascii of the note letter
        check_note[0] = char(n); // checks the letter for note with n, starting at A going to G for notes
        for (int p = 48; p <= 57; p++) { // p is used as ascii for the numbers to check for pich
            check_note[1] = char(p); // checks the number with p, starting at 0 going to 9
            if (note == check_note) { // if input is any valid note this if will run setting the function to true
                is_valid = true;
            }
        }
    }
    
    return is_valid;
}

/*
    Algorithm: Finds whether the input is a valid tune in SPN
    1. Accept input which is passed to function
    2. Declare bool is_valid as true
    3. Declare int i as 0
    4. For i being less than the length of input repeat 5-6
    5. set is_valid as false if isValidNote for the substring of input w length two at position i is also false
    6. Add 2 to i
    Parameters: string input
    Returns: is_valid
*/

bool isValidTune(string input) {

    bool is_valid = true;

    for (int i = 0; i < input.length(); i += 2) {
        if (isValidNote(input.substr(i, 2)) == false) { // splits input into group of 2s to check if theyre all SPN
            is_valid = false;
        }
    }

    return is_valid;
}

int main() {

    // test 1-2 tests valid tunes
    assert(isValidTune("B5C8G2F0") == true);
    assert(isValidTune("A0C4B3G9") == true);
    // test 3 has one note invalid for capitalization
    assert(isValidTune("B5C8G2f0") == false);
    //test 4 for some random string
    assert(isValidTune("Hey there") == false);
    //test 5 for some tune missing the first character
    assert(isValidTune("7G4B6D3") == false);

    return 0;
}