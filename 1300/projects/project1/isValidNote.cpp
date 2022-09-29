// isValidNote.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 1 - Problem 1 

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/*
    Algorithm: Finds whether the input is a valid note in SPN
    1. Accept note which is passed to function
    2. Declare string check_note as A0
    3. Repeat 4-7 until check_note is G9
    4. Repeat 5-6 until check_note has 9 at the end
    5. If note is the same as check_note return true for algorithm
    6. Add one to the number of check_note
    7. Go up one letter in alphabet for check_note and set the number to 0
    Parameters: string note
    Returns: false unless note = check_note at any time
*/

bool isValidNote(string note) {

    bool is_valid = false;
    string check_note = "A0"; // first note it checks with input

    for (int n = 65; n <= 71; n++) { // n is the number for the ascii of the note letter
        check_note[0] = char(n); // checks the letter for note with n, starting at A going to G for notes
        for (int p = 48; p <= 57; p++) { // p is used as ascii for the numbers to check for pitch
            check_note[1] = char(p); // checks the number with p, starting at 0 going to 9
            if (note == check_note) { // if input is any valid note this if will run setting the function to true
                is_valid = true;
            }
        }
    }
    
    return is_valid;
}

int main() {
    // test 1-3 for valid inputs
    assert(isValidNote("A0") == true);
    assert(isValidNote("G6") == true);
    assert(isValidNote("D4") == true);
    //test 4 for longer than acceptable length
    assert(isValidNote("A0C7B5") == false);
    // test 5 for capitalization
    assert(isValidNote("c7") == false);
    // test 6 for capitalization and if the second char is a number
    assert(isValidNote("gP") == false);

    return 0;
}