// tuneSimilarity.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 1 - Problem 4

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

/*
    Algorithm: Finds the similarity of two notes
    1. Accept tune1 and tune2 which is passed on from function
    2. Declare the double similarity and integers same_note, same_note_same_pitch, dif_note_dif_pitch all as 0
    3. Declare int i as 0
    4. For i being less than the length of the tunes repeat 5-8
    5. If the char of tune1 and tune2 at i is the same add one to same_note
    6. If the chars of tune1 and tune2 at i and i+1 is the same add one to same_note_same_pitch
    7. If the chars of tune1 and tune2 at i and i+1 are both different add one to dif_note_dif_pitch
    8. Add one to i
    9. Set similarity to (same_note / half the length of a tune) + same_note_same_pitch - dif_note_dif_tune
    Parameters: string tune1, string tune2
    Returns: similarity
*/

double tuneSimilarity(string tune1, string tune2) {
    double similarity = 0;
    int same_note = 0;
    int same_note_same_pitch = 0;
    int dif_note_dif_pitch = 0;
    
    if (tune1.length() == tune2.length()) {
        for (int i = 0; i < tune1.length(); i += 2) {
            if (tune1[i] == tune2[i]) { // checks to see if same note
                if (tune1[i + 1] == tune2[i + 1]) {
                    ++same_note_same_pitch; // checks to see if same pitch
                }
                    ++same_note;
            }
            else if (tune1[i + 1] != tune2[i + 1]) { // if notes different see if pitch is different
                ++dif_note_dif_pitch;
            }
        }
    }

    similarity = same_note / double(tune1.length()/2) + same_note_same_pitch - dif_note_dif_pitch;
    return similarity;
}

int main() {

    // Test 1 and 3 from examples of github 1-2 being for if the length is the same
    assert(tuneSimilarity("A0B0C0D0", "D1C1B1A1") == -4);
    assert(tuneSimilarity("A1B6G9", "A0B3G9") == 2);
    // Test 3 is if lengths are different
    assert(tuneSimilarity("D5G2", "F7D1E4G4") == 0);

    return 0;
}