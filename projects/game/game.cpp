#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void showStats(string char_name, string gender, string char_race, string char_class, int char_stats[][2]) {

    int const HP = 0;
    int const CURRENTHP = 0;
    int const MAXHP = 1;
    int const MP = 1;
    int const CURRENTMP = 0;
    int const MAXMP = 1;
    int const INT = 2;
    int const VIT = 3;
    int const STR = 4;

    cout << "Name: " << char_name
         << "\nGender: " << gender 
         << "\nRace: " << char_race
         << "\nClass: " << char_class
         << "\n" << char_stats[HP][CURRENTHP] << " HP / " << char_stats[HP][MAXHP] << " HP"
         << "\n" << char_stats[MP][CURRENTMP] << " MP / " << char_stats[MP][MAXMP] << " MP"
         << "\n" << char_stats[INT][0] << " INT"
         << "\n" << char_stats[VIT][0] << " VIT"
         << "\n" << char_stats[STR][0] << " STR" << endl;
}

int menu(string options, int size) { // when using menu("Options\nOptions", 2) seperate options w \n and in size put the number of choices

    string options_arr[size]; // creates an array the size of options, each part of array is an option
    int last_newline = -1; // marks where newlines are to seperate options
    int counter = 0; // used to assign string to option #
    int length;
    for (int i = 0; i < options.length(); i++) {
        if (options.substr(i, 1) == "\n") {
            length = i - last_newline - 1; // length of option being put into array
            options_arr[counter] = options.substr(last_newline + 1, length);
            counter++;
            last_newline = i;
        }
    }

    string input;
    int result = -1;

    do {
        for (int i = 0; i < size; i++) {
            cout << options_arr[i] << "\n"; // shows each option
        }
        cout << "\n";

        getline(cin, input);

        for (int i = 0; i < size; i++) {
        if (input == options_arr[i]) { // converts input string to corresponding #
                result = i;
        }
       }

     if (result == -1) {
            cout << "Invalid input." << "\n\n"; // if user enters strinmg thats not an option
        }
    
    } while (result == -1);

    return result;
}

int main() {
    
    int working_num;
    string char_name = "";
    string gender = "Invalid";
    string char_race = "Invalid";
    string char_class = "Invalid";
    string pronouns[3];
    int const PRONOUN_SUBJ = 0;
    int const PRONOUN_OBJ = 1;
    int const PRONOUN_ADJ = 2;
    int char_base_stats[4]; // {HP, INT, VIT, STR}  
    int char_stats[5][2]; // {Current HP, Max HP}, {Current MP, Max MP}, {INT, 0}, {VIT, 0}, {STR, 0}

    cout << "************************* GAME *************************\n";
    
    working_num = 0;
    do {
    cout << "\n";
    switch (menu("choose gender\nchoose race\nchoose class\nchoose name\nstart game\n", 5)) {
        case 0:
            cout << "\n";
            switch (menu("m\nf\nnb\n", 3)){
                case 0:
                    gender = "Male";
                    pronouns[PRONOUN_SUBJ] = "he";
                    pronouns[PRONOUN_OBJ] = "him";
                    pronouns[PRONOUN_ADJ] = "his";
                    break;
                case 1:
                    gender = "Female";
                    pronouns[PRONOUN_SUBJ] = "she";
                    pronouns[PRONOUN_OBJ] = "her";
                    pronouns[PRONOUN_ADJ] = "hers";
                    break;
                case 2:
                    gender = "Non-Binary";
                    pronouns[PRONOUN_SUBJ] = "they";
                    pronouns[PRONOUN_OBJ] = "them";
                    pronouns[PRONOUN_ADJ] = "theirs";
                    break;
            }
            break;
        case 1:
            cout << "\n";
            switch (menu("human\norc\ndwarf\nelf\n", 4)) {
                case 0:
                    char_race = "Human";
                    char_base_stats[0] = 10; // HP 
                    char_base_stats[1] = 4; // INT
                    char_base_stats[2] = 4; // VIT
                    char_base_stats[3] = 4; // STR
                    break;
                case 1:
                    char_race = "Orc";
                    char_base_stats[0] = 15; // HP 
                    char_base_stats[1] = 1; // INT
                    char_base_stats[2] = 2; // VIT
                    char_base_stats[3] = 7; // STR
                    break;
                case 2:
                    char_race = "Dwarf";
                    char_base_stats[0] = 10; // HP 
                    char_base_stats[1] = 4; // INT
                    char_base_stats[2] = 5; // VIT
                    char_base_stats[3] = 3; // STR
                    break;
                case 3:
                    char_race = "Elf";
                    char_base_stats[0] = 8; // HP 
                    char_base_stats[1] = 7; // INT
                    char_base_stats[2] = 4; // VIT
                    char_base_stats[3] = 2; // STR
                    break;
            }
            break;
        case 2:
            cout << "\n";
            switch (menu("warrior\nmage\ntank\nrogue\n", 4)) {
                case 0:
                    char_class = "Warrior";
                    char_base_stats[0] += 0; // HP 
                    char_base_stats[1] += 0; // INT
                    char_base_stats[2] += 1; // VIT
                    char_base_stats[3] += 2; // STR
                    break;
                case 1:
                    char_class = "Mage";
                    char_base_stats[0] += 0; // HP 
                    char_base_stats[1] += 3; // INT
                    char_base_stats[2] += 0; // VIT
                    char_base_stats[3] += 0; // STR
                    break;
                case 2:
                    char_class = "Tank";
                    char_base_stats[0] += 2; // HP 
                    char_base_stats[1] += 0; // INT
                    char_base_stats[2] += 2; // VIT
                    char_base_stats[3] += 0; // STR
                    break;
                case 3:
                    char_class = "Rogue";
                    char_base_stats[0] += 2; // HP 
                    char_base_stats[1] += 1; // INT
                    char_base_stats[2] += 1; // VIT
                    char_base_stats[3] += 0; // STR
                    break;
            }
            break;
        case 3:
            cout << "\nEnter your name:\n\n";
            getline(cin, char_name);
            break;
        case 4:
            cout << "\n";
            if (gender == "Invalid" || char_race == "Invalid" || char_class == "Invalid" || char_name == "") {
                cout << "You need to first create your character\n";
            }
            else {
                working_num = 1;
            }
            break;
    }
    } while (working_num == 0);

    int const HP = 0;
    int const CURRENTHP = 0;
    int const MAXHP = 1;
    int const MP = 1;
    int const CURRENTMP = 0;
    int const MAXMP = 1;
    int const INT = 2;
    int const VIT = 3;
    int const STR = 4;

    char_stats[HP][CURRENTHP] = char_base_stats[0]; // Current HP
    char_stats[HP][MAXHP] = char_base_stats[0]; // Max HP
    char_stats[MP][CURRENTMP] = char_base_stats[1]; // Current MP
    char_stats[MP][MAXMP] = char_base_stats[1]; // Max MP
    char_stats[INT][0] = char_base_stats[1]; // INT
    char_stats[VIT][0] = char_base_stats[2]; // VIT
    char_stats[STR][0] = char_base_stats[3]; // STR

    showStats(char_name, gender, char_race, char_class, char_stats);

    return 0;
}