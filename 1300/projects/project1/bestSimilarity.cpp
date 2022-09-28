#include <iostream>
#include <string>
#include <cassert>

using namespace std;

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

bool isValidTune(string input) {

    bool is_valid = true;

    for (int i = 0; i < input.length(); i += 2) {
        if (isValidNote(input.substr(i, 2)) == false) { // splits input into group of 2s to check if theyre all SPN
            is_valid = false;
        }
    }

    return is_valid;
}

int numValidNotes(string input) {

    int number_of_notes = 0;  // start at 0 notes
    for (int i = 0; i < input.length(); ++i) {
        if (isValidNote(input.substr(i,2)) == true) {
            ++number_of_notes;
        }
    }

    return number_of_notes;
}

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

double bestSimilarity(string input_tune, string target_tune) {
    int max_length = input_tune.length() - target_tune.length();
    double similarity = tuneSimilarity(input_tune.substr(0, target_tune.length()), target_tune); // sets similarity to that of the first part of the tune

    if (input_tune.length() >= target_tune.length()) {
        for (int i = 0; i <= max_length; i +=2) {
            if (tuneSimilarity(input_tune.substr(i, target_tune.length()), target_tune) > similarity) { // if any part of the tune is more similar than first part replace similarity with that one
                similarity = tuneSimilarity(input_tune.substr(i, target_tune.length()), target_tune);
            }
        }
    }

    return similarity;
}

int main() {

    string first_tune, second_tune;

    cout << "Enter a tune in SPN and another tune to compare to it:" << endl;
    cin >> first_tune >> second_tune;
    cout << bestSimilarity(first_tune, second_tune) << endl;

    return 0;
}