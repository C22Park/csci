#include <iostream>
#include <string>


using namespace std;

int main(){
    
    cout << "Hundreds of years ago conflict broke out across the continent of Terrassa. Now the world is in a state of unparralled peace,\nhowever dark forces are vying for control. This is the story of you and your quest to save Terrassa.\n" << endl;

    string charName;
    cout << "Please enter your name" << endl;
    cin >> charName;
    cout << endl;

    string charGender; // used by user to choose gender
    string pronounSubj; // used when displaying dialog for subject pronoun i.e. he/she/they
    string pronounObj; // used when displaying dialog for subject object i.e. him//her/them
    string pronounAdj; // used when displaying dialog for subject adjective i.e. his/theirs/hers
    while (true) {
    cout << "What is your gender? m/f/nb" << endl;
    cin >> charGender;
    if (charGender == "m") {
        pronounSubj = "he";
        pronounObj = "him";
        pronounAdj = "his";
        break;
    }
    else if (charGender == "f") {
        pronounSubj = "she";
        pronounObj = "her";
        pronounAdj = "hers";
        break;
    }
    else if (charGender == "nb") {
        pronounSubj = "they";
        pronounObj = "them";
        pronounAdj = "theirs";
        break;
    }
    }
    cout << endl;
    
    int charLVL = 0;
    int charXP = 0;
    int charBaseHP;
    int charBaseINT;
    int charBaseVIT;
    int charBaseSTR;
    string charRace;
    while (true) {
    cout << "What is your race? human, orc, dwarf, or elf? Additionally type attributes to view the differences." << endl;
    cin >> charRace;
    cout << endl;
    if (charRace == "attributes"){
        cout << "Humans: 10 HP, 4 INT, 4 VIT, 4 STR\nOrcs: 15 HP, 1 INT, 2 VIT, 7 STR\n"
        << "Dwarves: 10 HP, 3 INT, 6 VIT, 3 STR\nElves: 8 HP, 7 INT, 4 VIT, 2 STR\n" << endl;
    }
    else if (charRace == "human"){
        charBaseHP = 10;
        charBaseINT = 4;
        charBaseVIT = 4;
        charBaseSTR = 4;
        break;
    }
        else if (charRace == "orc"){
        charBaseHP = 15;
        charBaseINT = 1;
        charBaseVIT = 2;
        charBaseSTR = 7;
        break;
    }
        else if (charRace == "dwarf"){
        charBaseHP = 10;
        charBaseINT = 3;
        charBaseVIT = 6;
        charBaseSTR = 3;
        break;
    }
    else if (charRace == "elf"){
        charBaseHP = 8;
        charBaseINT = 7;
        charBaseVIT = 4;
        charBaseSTR = 2;
        break;
    }
    }
    

    return 0;
}