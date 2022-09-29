// scientificPitch.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 1 - Problem 7

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

/*
    Algorithm: Finds the highest similarity of a target tune to a part of a input tune 
    1. Accept input_tune and target_tune passed from the function
    2. Declare integer max_length as the length of input_tune - the length of target_tune
    3. Declare double similarity and set equal to tuneSimilarity using the substring of input_tune with length of target_tune and target_tune
    4. If input_tune is longer than or the same length as target_tune move on otherwise return similarity
    5. Declare int i as 0
    6. For i < max_length repeat 7-8
    7. If tuneSimilarity(input_tune.subnstr(i, length of target tune), target_tune) is greater than similarity set this as the new similarity
    8. Add two to i
    Parameters: string input_tune, string target_tune
    Returns: similarity
*/

double bestSimilarity(string input_tune, string target_tune) {
    int max_length = input_tune.length() - target_tune.length();
    double similarity = tuneSimilarity(target_tune, input_tune.substr(0, target_tune.length())); // sets similarity to that of the first part of the tune

    if (input_tune.length() >= target_tune.length()) {
        for (int i = 0; i <= max_length; i +=2) {
            if (tuneSimilarity(target_tune, input_tune.substr(i, target_tune.length())) > similarity) { // if any part of the tune is more similar than first part replace similarity with that one
                similarity = tuneSimilarity(target_tune, input_tune.substr(i, target_tune.length()));
            }
        }
    }

    return similarity;
}

/*
    Algorithm: Finds the best similarity of three tunes compared to a target and rank them
    1. Accept tune1 tune2 tune3 and target_tune passed from the function
    2. Declare strings rank1 rank2 and rank3
    3. Declare doubles similarity1 similarity2 similarity3 as bestSimilarity(tune[1 or 2 or 3], target_tune)
    4. Check if similarity1 is larger than or equal to the other two, if so go to 4b if not go to 5 
    4b. Set rank1 to 'Tune 1' If similarity2 >= similarity3 set rank2 to 'Tune 2' and rank3 to 'Tune 3' if not go to 4c
    4c.Set rank 2 to 'Tune 3' and rank3 to 'Tune 2'
    5. Check if similarity2 is larger than or equal to the other two, if so go to 5b if not go to 6 
    5b. Set rank1 to 'Tune 2' If similarity1 >= similarity3 set rank2 to 'Tune 1' and rank3 to 'Tune 3' if not go to 4c
    5c.Set rank 2 to 'Tune 3' and rank3 to 'Tune 1'
    4. Check if similarity3 is larger than or equal to the other two, if so go to 6b
    4b. Set rank1 to 'Tune 3' If similarity1 >= similarity2 set rank2 to 'Tune 1' and rank3 to 'Tune 2' if not go to 4c
    4c.Set rank 2 to 'Tune 2' and rank3 to 'Tune 1'
    7. Print out "1) rank1, 2) rank2, 3) rank3"
    Parameters: string tune1, string tune2, string tune3, string target_tune
    Returns: nothing its a void function
*/

void printTuneRankings(string tune1, string tune2, string tune3, string target_tune) {
    string rank1, rank2, rank3;
    double similarity1 = bestSimilarity(tune1, target_tune); // finds similarity between target and each tune
    double similarity2 = bestSimilarity(tune2, target_tune);
    double similarity3 = bestSimilarity(tune3, target_tune);
    
    if (similarity1 >= similarity2 && similarity1 >= similarity3) { // >= makes it so that if they are the same value the order they appear takes precedent
        rank1 = "Tune 1";
        if (similarity2 >= similarity3) {
            rank2 = "Tune 2";
            rank3 = "Tune 3";
        }
        else {
            rank2 = "Tune 3";
            rank3 = "Tune 2";
        }
    }
    else if (similarity2 >= similarity1 && similarity2 >= similarity3) {
        rank1 = "Tune 2";
        if (similarity1 >= similarity3) {
            rank2 = "Tune 1";
            rank3 = "Tune 3";
        }
        else {
            rank2 = "Tune 3";
            rank3 = "Tune 1";
        }
    }
    else {
        rank1 = "Tune 3";
        if (similarity1 >= similarity2) {
            rank2 = "Tune 1";
            rank3 = "Tune 2";
        }
        else {
            rank2 = "Tune 2";
            rank3 = "Tune 1";
        }
    }
    
    cout << "1) " << rank1 << ", 2) " << rank2 << ", 3) " << rank3 << endl;
}

int main() {
    
    bool exit_menu = false; // used if user chooses exit to end while loop, closing the menu
    int input; // used for menu picking
    string tune1, tune2, tune3, target_tune; // later used in previous functions based on user input
    cout << setprecision(2) << fixed; // makes answers output two decimal points

    while (exit_menu == false) {
        cout << "--- Menu ---\n" 
             << "1. Calculate similarity between two tunes.\n" 
             << "2. Calculate best similarity between two tunes of potentially different lengths.\n"
             << "3. Print three input tunes in order from most to least similar to the target tune.\n"
             << "4. Exit.\n" 
             << "Please enter your choice (1 - 4):" << endl;
        cin >> input;
        switch (input) {
            case 1:
                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                while (isValidTune(tune1) == false) { // if the last input is not valid SPN display invalid input and have them reenter the string
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                while (isValidTune(tune2) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                }
                cout << "The similarity score is " << tuneSimilarity(tune1, tune2) << endl;
                break;
            case 2:
                cout << "Please enter the input tune:" << endl;
                cin >> tune1;
                while (isValidTune(tune1) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the target tune:" << endl;
                cin >> target_tune;
                while (isValidTune(target_tune) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target_tune;
                }
                cout << "The best similarity score is: " << bestSimilarity(tune1, target_tune) << endl;
                break;
            case 3:
                cout << "Please enter the first tune:" << endl;
                cin >> tune1;
                while (isValidTune(tune1) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune1;
                }
                cout << "Please enter the second tune:" << endl;
                cin >> tune2;
                while (isValidTune(tune2) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune2;
                }
                cout << "Please enter the third tune:" << endl;
                cin >> tune3;
                while (isValidTune(tune3) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> tune3;
                }
                cout << "Please enter the target tune:" << endl;
                cin >> target_tune;
                while (isValidTune(target_tune) == false) {
                    cout << "Invalid input. Please enter a tune in valid SPN:" << endl;
                    cin >> target_tune;
                }
                printTuneRankings(tune1, tune2, tune3, target_tune);
                break;
            case 4:
                exit_menu = true;
                cout << "Goodbye!" << endl;
                break;
            default: // in the case the user puts a number other than 1-4 in the menu
                cout << "Invalid Input." << endl;
                break;
        }
    }

    return 0;
}