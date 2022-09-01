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
    cout << endl;
    if (charGender == "m") {
        pronounSubj = "he";
        pronounObj = "him";
        pronounAdj = "his";
        break;
    }
    else if (charGender == "f") {
        pronounSubj = "she";
        pronounObj = "her";
        pronounAdj = "her";
        break;
    }
    else if (charGender == "nb") {
        pronounSubj = "they";
        pronounObj = "them";
        pronounAdj = "their";
        break;
    }
    }
    cout << endl;
    
    int charLVL = 0; // characters current level
    int charXP = 0; // characters current XP
    int charBaseHP; // characters base HP, determined by race and class
    int charBaseINT; // characters base INT, determined by race and class
    int charBaseVIT; // characters base VIT, determined by race and class
    int charBaseSTR; // characters base STR, determined by race and class
    string charRace; // characters race
    string startKingdom; // starting point for adventure based off of race
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
        startKingdom = "Glasshire";
        break;
    }
        else if (charRace == "orc"){
        charBaseHP = 15;
        charBaseINT = 1;
        charBaseVIT = 2;
        charBaseSTR = 7;
        startKingdom = "Ky'Rizek";
        break;
    }
        else if (charRace == "dwarf"){
        charBaseHP = 10;
        charBaseINT = 3;
        charBaseVIT = 6;
        charBaseSTR = 3;
        startKingdom = "The Iron Order";
        break;
    }
    else if (charRace == "elf"){
        charBaseHP = 8;
        charBaseINT = 7;
        charBaseVIT = 4;
        charBaseSTR = 2;
        startKingdom = "Elysia";
        break;
    }
    }

    string charClass; // characters class
    int charAddHP; // used in conjunction w baseHP to get MaxHP
    int charAddINT; // used in conjunction w baseINT to get MaxMP and INT
    int charAddVIT; // used in conjunction w baseVIT to get VIT
    int charAddSTR; // used in conjunction w baseSTR to get STR
    int charMaxHP; // max HP
    int charHP; // current HP
    int charMaxMP; //max MP
    int charMP; // current MP
    int charINT; // actual INT
    int charVIT; // actual VIT
    int charSTR; // actual STR
    while (true) {
        cout << "Pick your class. warrior, mage, tank, or rogue. Additionally you can type attributes to view the differences." << endl;
        cin >> charClass;
        cout << endl;
    if (charClass == "attributes") {
        cout << "Warriors: +1 VIT, +2 STR\nMages: +3 INT\nTanks: +2 HP, +2 VIT\n"
        <<"Rogues: +1 HP, +1 VIT, +1 INT\n" << endl;
    }
    else if(charClass == "warrior"){
        charAddHP = 0;
        charAddINT = 0;
        charAddVIT = 1;
        charAddSTR = 2;
        break;
    }
        else if(charClass == "mage"){
        charAddHP = 0;
        charAddINT = 3;
        charAddVIT = 0;
        charAddSTR = 0;
        break;
    }
        else if(charClass == "tank"){
        charAddHP = 2;
        charAddINT = 0;
        charAddVIT = 2;
        charAddSTR = 0;
        break;
    }
        else if(charClass == "rogue"){
        charAddHP = 1;
        charAddINT = 1;
        charAddVIT = 1;
        charAddSTR = 0;
        break;
    }
    }
    charMaxHP = charBaseHP + charAddHP;
    charHP = charMaxHP;
    charAddHP = 0;
    charMaxMP = charBaseINT + charAddINT;
    charMP = charMaxMP;
    charINT = charMaxMP;
    charAddINT = 0;
    charVIT = charBaseVIT + charAddVIT;
    charAddVIT = 0;
    charSTR = charBaseSTR + charAddSTR;
    charAddSTR = 0;
    
    if (charGender == "m" || charGender == "f"){
    cout << "This is the story of " << charName << ", " << pronounSubj << " is ";
    }
    else {
    cout << "This is the story of " << charName << ", " << pronounSubj << " are ";
    }
    if (charRace == "human" || charRace == "dwarf"){
    cout << "a " << charRace << " " << charClass << " from the kingdom of " << startKingdom << endl;
    }
    else {
    cout << "an " << charRace << " " << charClass << " from the kingdom of " << startKingdom << endl;
    }

    return 0;
}