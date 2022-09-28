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

void printTuneRankings(string tune1, string tune2, string tune3, string target_tune) {
    double similarity1, similarity2, similarity3;
    string rank1, rank2, rank3;
    similarity1 = bestSimilarity(tune1, target_tune);
    similarity2 = bestSimilarity(tune2, target_tune);
    similarity3 = bestSimilarity(tune3, target_tune);
    
    if (similarity1 >= similarity2 && similarity1 >= similarity3) {
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
        if (similarity1 >= similarity3) {
            rank2 = "Tune 1";
            rank3 = "Tune 2";
        }
        else {
            rank2 = "Tune 2";
            rank3 = "Tune 1";
        }
    }

    cout << "1) " << rank1 << ", 2) " << rank2 << ", 3) " << rank3 << endl;
    cout << similarity1 << endl << similarity2 << endl << similarity3 << endl;
}

int main() {

    string first_tune, second_tune, third_tune, target_tune;

    cout << "Enter three tunes and a target tune to compare them with in SPN:" << endl;
    cin >> first_tune >> second_tune >> third_tune >> target_tune;
    printTuneRankings(first_tune, second_tune, third_tune, target_tune);

    return 0;
}