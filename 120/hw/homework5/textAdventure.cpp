/*
	Charles Park
	Section 5
	2/16/23
	Assignment 5	
*/

#include <iostream>

using namespace std;

int questManager(string input, int num) {
    static bool forgot = true;
    if (input == "change_forgot") {
        if (forgot) {
            forgot = false;
        } else {
            forgot = true;
        }
    }
    if (input == "forgot") {
        if (forgot) {
            return 1;
        } else {
            return 0;
        }
    }

    static bool quest = false;
    if (input == "change_quest") {
        if (quest) {
            quest = false;
        } else {
            quest = true;
        }
    }
    if (input == "quest") {
        if (quest) {
            return 1;
        } else {
            return 0;
        }
    }

    static bool kicked_fishdude = false;
    if (input == "change_kick") {
        if (kicked_fishdude) {
            kicked_fishdude = false;
        } else {
            kicked_fishdude = true;
        }
    }
    if (input == "kick") {
        if (kicked_fishdude) {
            return 1;
        } else {
            return 0;
        }
    }

    static bool has_stone = false;
    if (input == "change_stone") {
        if (has_stone) {
            has_stone = false;
        } else {
            has_stone = true;
        }
    }
    if (input == "stone") {
        if (has_stone) {
            return 1;
        } else {
            return 0;
        }
    }

    static int gold = 0;
    if (input == "add_gold") {
        gold += num;
    }
    if (input == "print_gold") {
        cout << "Current Gold: " << gold << "\n";
    }
    if (input == "gold") {
        return gold;
    }
    return 0;
}

int start() {
    int input = 0;
    while (input < 1 || input > 2) {
        system("clear");
        questManager("print_gold", 0);
        if (questManager("forgot", 0)) {
            cout << "You wake up with a searing headache unsure of where you are. ";
            if (questManager("kick", 0)) {
                questManager("change_kick", 0);
            }
        }
        cout << "You are next to a large pond that you can't see the bottom of. Surronding you is thick forest.\n"
             << "What do you do?\n"
             << "1) Take a sip from the pond\n"
             << "2) Venture into the woods\n";
        cin >> input;
        cin.ignore();
        if (input == 1) {
            if (questManager("forgot", 0)){
                questManager("change_forgot", 0);
            }
            return 2;
        } else if (input == 2) {
            if (questManager("forgot", 0)){
                questManager("change_forgot", 0);
            }
            return 3;
        } else {
            cout << "Invalid input. Press enter.\n";
            cin.ignore();
        }
    }
}

int pond() {
    int input = 0;
    while (input < 1 || input > 2) {
        system("clear");
        questManager("print_gold", 0);
        if (questManager("kick", 0) == 0) {
            cout << "You fall into the water and are greeted by a fishman who tries to pull you deeper.\n"
                 << "What do you do?\n"
                 << "1) Follow him down\n"
                 << "2) Kick him away\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                return 4;
            } else if (input == 2) {
                questManager("change_kick", 0);
            } else {
                cout << "Invalid input. Press enter.\n";
                cin.ignore();
            }
        }
        if (questManager("kick", 0)) {
            system("clear");
            questManager("print_gold", 0);
            cout << "The fishman is enraged and chants a spell before you get launched out the pond.\n"
                 << "What do you do?\n"
                 << "1) Flail your arms and scream\n"
                 << "2) Go along for the ride\n";
            cin >> input;
            cin.ignore();
            if (input != 1 && input != 2) {
                cout << "Invalid input. Press enter.\n";
                cin.ignore();
            } else {
                return 1;
            }
        }
    }
}

int forest() {
    int input = 0;
    while (input < 1 || input > 3) {
        system("clear");
        questManager("print_gold", 0);
        cout << "You find a path that heads towards the mountains in one direction and a town in the other direction."
             << "What will you do?\n"
             << "1) Head for the hills\n"
             << "2) Go to town\n"
             << "3) Return from whence you came\n";
        cin >> input;
        cin.ignore();
        if (input == 1) {
            return 5;
        } else if (input == 2) {
            return 6;
        } else if (input == 3) {
            return 1;
        } else {
            cout << "Invalid input. Press enter.\n";
            cin.ignore();
        }
    }
}

int fishCity() {
    int input = 0;
    static bool first = true;
    while (input < 1 || input > 2) {
        system("clear");
        questManager("print_gold", 0);
        cout << "The fishman brought you to his underwater village where you can surprisingly breath.\n";
        if (first) {
            cout << "The village elder asks you to find a magic stone and bring it back for a reward.\n";
            questManager("change_quest", 0);
            first = false;
        }
        cout << "What will you do?\n";
        if (questManager("quest", 0)) {
            cout << "1) Turn in magic stone\n"
                 << "2) Leave to the surface\n";
            cin >> input;
            cin.ignore();
            if (input != 1 && input != 2) {
                cout << "Invalid input. Press enter.\n";
                cin.ignore();
            }
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                if (questManager("stone", 0)) {
                    cout << "The village elder thanks you and gives you 50 gold as a reward.\n"
                        << "Press enter to continue.\n";
                    questManager("add_gold", 50);
                    questManager("change_quest", 0);
                    questManager("change_stone", 0);
                    input = 0;
                } else {
                    cout << "The village elder is mad at you for lying about the stone.\n"
                         << "Press enter to continue.\n";
                    input = 0;
                }
                cin.ignore();
            } else if (input == 2) {
                return 1;
            }
        } else {
            cout << "1) Leave to the surface\n";
            cin >> input;
            cin.ignore();
            if (input != 1) {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            } else {
                return 1;
            }
        }
    }
}

int goblinCamp() {
    static bool looted = false;
    int input = 0;
    while (input != 5) {
        system("clear");
        questManager("print_gold", 0);
        cout << "You find an abandoned goblin camp at the base of a pecuiliar waterfall.\n"
             << "What do you do?\n";
        if (looted == false && questManager("quest", 0) == 0) {
            cout << "1) Loot the camp\n"
                 << "2) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                cout << "You didn't find much of value except a chest full of 25 gold.\n"
                     << "Press enter to continue.\n";
                looted = true;
                questManager("add_gold", 25);
                cin.ignore();
            } else if (input == 2) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        } else if (looted == false && questManager("quest", 0) && questManager("stone", 0) == 0) {
            cout << "1) Loot the camp\n"
                 << "2) Enter the waterfall\n"
                 << "3) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                cout << "You didn't find much of value except a chest full of 25 gold.\n"
                     << "Press enter to continue.\n";
                looted = true;
                questManager("add_gold", 25);
                cin.ignore();
            } else if (input == 2) {
                system("clear");
                questManager("print_gold", 0);
                cout << "At the back of the waterfall you find a blue gem full of magic energy.\n"
                     << "Press enter to take it.\n";
                questManager("change_stone", 0);
                cin.ignore();
                system("clear");
                questManager("print_gold", 0);
                cout << "The opening behind the waterfall begins to close.\n"
                     << "Press enter to continue.\n";
                cin.ignore();
            } else if (input == 3) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        } else if (looted && questManager("quest", 0) == 0) {
            cout << "1) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        } else if (looted && questManager("quest", 0) && questManager("stone", 0) == 0) {
            cout << "1) Enter the waterfall\n"
                 << "2) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                cout << "At the back of the waterfall you find a blue gem full of magic energy.\n"
                     << "Press enter to take it.\n";
                questManager("change_stone", 0);
                cin.ignore();
                system("clear");
                questManager("print_gold", 0);
                cout << "The opening behind the waterfall begins to close.\n"
                     << "Press enter to continue.\n";
                cin.ignore();
            } else if (input == 2) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        } else if (looted && questManager("stone", 0)) {
            cout << "1) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        } else if (looted = false && questManager("stone", 0)) {
            cout << "1) Loot the camp\n"
                 << "2) Head back to the path\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                cout << "You didn't find much of value except a chest full of 25 gold.\n"
                     << "Press enter to continue.\n";
                looted = true;
                questManager("add_gold", 25);
                cin.ignore();
            } else if (input == 2) {
                return 3;
            } else {
                cout << "Invalid input. Press enter.\n";
                input = 0;
                cin.ignore();
            }
        }
    }
}

int town() {
    int input = 0;
    while (input < 1 || input > 3) {
        system("clear");
        questManager("print_gold", 0);
        cout << "You enter the town of Longboum, there's a large tavern in front of you and behind it is an imposing marble tower.\n"
            << "What do you do?\n"
            << "1) Head to the tavern\n"
            << "2) Go to the magic tower\n"
            << "3) Return to the path\n";
        cin >> input;
        cin.ignore();
        if (input == 1) {
            return 7;
        } else if (input == 2) {
            return 8;
        } else if (input == 3) {
            return 3;
        } else {
            cout << "Invalid input. Press enter.\n";
            cin.ignore();
        }
    }
}

int tavern() {
    static bool bet_taken = false;
    int input = 0;
    while (1) {
        system("clear");
        questManager("print_gold", 0);
        cout << "You enter a dark tavern packed full of people. In the corner there's a group making card bets.\n"
             << "What do you do?\n";
        if (bet_taken == false) {
            cout << "1) Drink\n"
                 << "2) Make a bet\n"
                 << "3) Head back to town\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                cout << "You begin to drink all night at the tavern. At some point you black out.\n"
                     << "Press enter to continue.\n";
                questManager("change_forgot", 0);
                if (questManager("kick", 0)) {
                    questManager("change_kick", 0);
                }
                cin.ignore();
                return 1;
            } else if (input == 2) {
                system("clear");
                questManager("print_gold", 0);
                if (questManager("gold", 0) >= 10) {
                    cout << "You put in 10 gold on a game of blackjack and win 35 gold in return.\n"
                         << "Press enter to continue.\n";
                    questManager("add_gold", 25);
                    bet_taken = true;
                    cin.ignore();
                } else {
                    cout << "You don't have enough gold to make a bet.\n"
                         << "Press enter to continue.\n";
                    cin.ignore();
                }
            } else if (input == 3) {
                return 6;
            } else {
                cout << "Invalid input. Press enter.\n";
                cin.ignore();
            }
        } else {
            cout << "1) Drink\n"
                 << "2) Head back to town\n";
            cin >> input;
            cin.ignore();
            if (input == 1) {
                system("clear");
                questManager("print_gold", 0);
                cout << "You begin to drink all night at the tavern. At some point you black out.\n"
                     << "Press enter to continue.\n";
                questManager("change_forgot", 0);
                if (questManager("kick", 0)) {
                    questManager("change_kick", 0);
                }
                cin.ignore();
                return 1;
            } else if (input == 2) {
                return 6;
            } else {
                cout << "Invalid input. Press enter.\n";
                cin.ignore();
            }
        }
    }
}

int mageTower() {
    int input;
    bool run = true;
    while (run) {
        system ("clear");
        questManager("print_gold", 0);
        cout << "You enter the magic tower and an old man with a long white beard comes up to you.\n"
             << "He tells you have a curse which sends you back in time whenever you drink.\n"
             << "What do you do?\n"
             << "1) Ask him to remove the curse\n"
             << "2) Go back to town\n";
        cin >> input;
        cin.ignore();
        if (input == 1) {
            system("clear");
            questManager("print_gold", 0);
            if (questManager("gold", 0) >= 100) {
                cout << "The wizard charges you 100 gold and promptly removes the curse. You are now free!\n"
                     << "Thanks for playing. Press enter to quit.\n";
                cin.ignore();
                return 9;
            } else {
                cout << "The wizard wants to charge you 100 gold for the service. Come back when you get your money up.\n"
                     << "Press enter to continue\n";
                cin.ignore();
            }
        } else if (input == 2) {
            return 6;
        } else {
            cout << "Invalid input. Press enter.\n";
            cin.ignore();
        }
    }   
}

int main() {
    int path = start();
    bool run = true;
    while (run) {
        switch (path) {
            case 1:
                path = start();
                break;
            case 2:
                path = pond();
                break;
            case 3:
                path = forest();
                break;
            case 4:
                path = fishCity();
                break;
            case 5:
                path = goblinCamp();
                break;
            case 6:
                path = town();
                break;
            case 7:
                path = tavern();
                break;
            case 8:
                mageTower();
                break;
            case 9:
                run = false;
                break;
        }
    }
}