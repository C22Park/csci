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

    bool is_valid = false;

    for (int i = 0; i < input.length(); i += 2) {
        if (isValidNote(input.substr(i, 2)) == true) { // splits input into group of 2s to check if theyre all SPN
            is_valid = true;
        }
    }

    return is_valid;
}

int numValidNotes(string input) {

    int number_of_notes = 0;  // start at 0 notes
    if (isValidTune(input) == true) { // if the tune is valid then divide the ength of string by two as each note is two characters
        number_of_notes = input.length() / 2;
    }

    return number_of_notes;
}

double tuneSimilarity(string tune1, string tune2) {
    double similarity = 0;
    int same_note = 0;
    int same_note_same_pitch = 0;
    int dif_note_dif_pitch = 0;
    
    if (numValidNotes(tune1) == numValidNotes(tune2)) {
        for (int i = 0; i < tune1.length(); i += 2) {
            if (tune1[i] == tune2[i]) {
                if (tune1[i + 1] == tune2[i + 1]) {
                    ++same_note_same_pitch;
                }
                    ++same_note;
            }
            else if (tune1[i + 1] != tune2[i + 1]) {
                ++dif_note_dif_pitch;
            }
        }
    }

    similarity = same_note / double(numValidNotes(tune1)) + same_note_same_pitch - dif_note_dif_pitch;
    return similarity;
}

double bestSimilarity(string input_tune, string target_tune) {
    int max_length = input_tune.length() - target_tune.length();
    double similarity = tuneSimilarity(target_tune, input_tune.substr(0, target_tune.length()));

    if (input_tune.length() >= target_tune.length()) {
        for (int i = 0; i < max_length; i +=2) {
            if (tuneSimilarity(target_tune, input_tune.substr(i, target_tune.length())) > similarity) {
                similarity = tuneSimilarity(target_tune, input_tune.substr(i, target_tune.length()));
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