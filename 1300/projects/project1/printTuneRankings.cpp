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

void printTuneRankings(string tune1, string tune2, string tune3, string target_tune) {
    string rank1, rank2, rank3;
    double similarity1 = bestSimilarity(tune1, target_tune);
    double similarity2 = bestSimilarity(tune2, target_tune);
    double similarity3 = bestSimilarity(tune3, target_tune);
    if (tune1.length() < target_tune.length()) {
        similarity1 = 0;
        cout << "1" << endl;
    }
    if (tune2.length() < target_tune.length()) {
        similarity2 = 0;
        cout << "2" << endl;
    }
    if (tune3.length() < target_tune.length()) {
        similarity3 = 0;
        cout << "3" << endl;
    }

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

    string first_tune, second_tune, third_tune, target_tune;

    cout << "Enter three tunes and a target tune to compare them with in SPN:" << endl;
    cin >> first_tune >> second_tune >> third_tune >> target_tune;
    printTuneRankings(first_tune, second_tune, third_tune, target_tune);

    return 0;
}