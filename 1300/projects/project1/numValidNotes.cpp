// numValidNotes.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 1 - Problem 3

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
        for (int p = 48; p <= 57; p++) { // p is used as ascii for the numbers to check pitch
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

/*
    Algorithm: Finds the number of valid notes from input
    1. Accept input which is passed on function
    2. Declare number_of_notes and i both as 0
    3. For i being less than the length of input repeat 4-5
    4. If isValidNote of the substring of input w length 2 and starting at i is true add one to number_of_notes
    5. Add one to i
    Parameters: string input
    Returns: number_of_notes
*/

int numValidNotes(string input) {

    int number_of_notes = 0;  // start at 0 notes
    for (int i = 0; i < input.length(); ++i) {
        if (isValidNote(input.substr(i,2)) == true) {
            ++number_of_notes;
        }
    }

    return number_of_notes;
}

int main() {

    // Test 1 for a typical correct input
    assert(numValidNotes("A0C5B3G9") == 4);
    // Test 2 for a tune shifted by 1 
    assert(numValidNotes("AB0C7G3F1") == 4);
    // Test 3 for a tune with no valid notes
    assert(numValidNotes("a9ggGW9") == 0);

}