/* To Do:
    1.write all algorithms and comments
    2. balance game
*/
#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <unistd.h>
#include <sstream>
#include "Classes/randomizer.cpp"
#include "Classes/split.cpp"
#include "Classes/activeCheats.cpp"
#include "Classes/Map.cpp"
#include "Classes/Game.cpp"

using namespace std;

int main()
{
    srand(time(NULL));
    system("clear");
    string input = "0";
    ifstream file;
    ofstream ofile;
    string temp_arr[3];
    bool active_cheats[7] = {0, 0, 0, 0, 0, 0, 0};
    int difficulty = 1;

    while (input != "6")
    {
        cout << " _  __ _                    _                      _____              _              \n"
             << "| |/ /(_)                  | |                    |  __ \\            | |            \n"
             << "| ' /  _  _ __    __ _   __| |  ___   _ __ ___    | |__) |_   _  ___ | |__           \n"
             << "|  <  | || '_ \\  / _` | / _` | / _ \\ | '_ ` _ \\   |  _  /| | | |/ __|| '_ \\      \n"
             << "| . \\ | || | | || (_| || (_| || (_) || | | | | |  | | \\ \\| |_| |\\__ \\| | | |    \n"
             << "|_|\\_\\|_||_| |_| \\__, | \\__,_| \\___/ |_| |_| |_|  |_|  \\_\\\\__,_||___/|_| |_| \n"
             << "                  __/ |                                                              \n"
             << "                 |___/                                                               \n"
             << "                                                                                     \n"
             << "                              1. Start Game                                          \n"
             << "                              2. Tutorial                                            \n"
             << "                              3. High Scores                                         \n"
             << "                              4. Settings                                            \n"
             << "                              5. Credits                                             \n"
             << "                              6. Quit Game                                           \n\n";
        
        getline(cin, input);

        if (input == "1") // Start Game
        {
            system("clear");
            cout << "Enter your username:\n";
            getline(cin, input);
            Game* game = new Game(active_cheats, input, difficulty);
            game->playGame();
            delete game;
            system("clear");
            input = "1";

        } else if (input == "2") // Tutorial
        {
            system("clear");
            Game* tutorial = new Game(active_cheats, "", 0);
            tutorial -> howToPlay();
            delete tutorial;
        } else if (input == "3") // High Scores
        {
            system("clear");
            file.open("highscores.txt");
            while (getline(file, input))
            {
                cout << input << "\n";
            }
            file.close();
            cout << "Press enter to go back\n";
            getline(cin, input);
            system("clear");
            input = "0";
        } else if (input == "4") // Settings
        {
            input = "";
            while (input != "3")
            {
                system("clear");
                cout << "Settings:\n"
                    << "1. Difficulty\n"
                    << "2. Reset High Scores\n"
                    << "3. Return to Menu\n\n";
                getline(cin, input);
                if (input == "1")
                {
                    while (input == "1")
                    {
                        system("clear");
                        cout << "Difficulties:\n"
                             << "1. Easy (500 gold, 10 soldiers, 2 enemy armies per year per year, 5 resources per year)\n"
                             << "2. Medium (300 gold, 5 soldiers, 4 enemy armies per year per year, 3 resources per year)\n"
                             << "3. Hard (150 gold, 1 soldier, 6 enemy armies per year per year, 2 resource per year)\n\n";
                        getline(cin, input);
                        system("clear");
                        if (input == "1")
                        {
                            difficulty = 1;
                            input = "0";
                        } else if (input == "2")
                        {
                            difficulty = 2;
                        } else if (input == "3")
                        {
                            difficulty = 3;
                            input = "0";
                        } else
                        {
                            cout << "Invalid Input\n"
                                 << "Press enter to go back\n";
                            getline(cin, input);
                            input = "1";
                        }
                    }
                } else if (input == "2")
                {
                    system("clear");
                    ofile.open("highscores.txt");
                    ofile << "USERNAME | ARMY SIZE | DAYS LASTED | DIFFICULTY\n";
                    ofile.close();
                    cout << "Successfully reset high score list\n"
                         << "Press enter to go back\n";
                    getline(cin, input);
                    input = "2";
                } else if (input == "3")
                {} else if (input == "cheats")
                {
                    while(input != "8")
                    {
                        system("clear");
                        activeCheats(active_cheats);
                        cout << "8. Exit\n";
                        getline(cin, input);
                        if (input == "1")
                        {
                            if (active_cheats[0])
                            {
                                active_cheats[0] = false;
                            } else 
                            {
                                active_cheats[0] = true;
                            }
                        } else if (input == "2")
                        {
                            if (active_cheats[1])
                            {
                                active_cheats[1] = false;
                            } else 
                            {
                                active_cheats[1] = true;
                            }
                        } else if (input == "3")
                        {
                            if (active_cheats[2])
                            {
                                active_cheats[2] = false;
                            } else 
                            {
                                active_cheats[2] = true;
                            }
                        } else if (input == "4")
                        {
                            if (active_cheats[3])
                            {
                                active_cheats[3] = false;
                            } else 
                            {
                                active_cheats[3] = true;
                            }
                        } else if (input == "5")
                        {
                            if (active_cheats[4])
                            {
                                active_cheats[4] = false;
                            } else 
                            {
                                active_cheats[4] = true;
                            }
                        } else if (input == "6")
                        {
                            if (active_cheats[5])
                            {
                                active_cheats[5] = false;
                            } else 
                            {
                                active_cheats[5] = true;
                            }
                        } else if (input == "7")
                        {
                            if (active_cheats[6])
                            {
                                active_cheats[6] = false;
                            } else 
                            {
                                active_cheats[6] = true;
                            }
                        } else if (input == "8")
                        {} else
                        {
                            system("clear");
                            cout << "Invalid Input\n"
                                 << "Press enter to go back\n";
                            getline(cin, input);
                            input = "1";
                        }
                    }
                } else
                {
                    system("clear");
                    cout << "Invalid Input\n"
                         << "Press enter to go back\n";
                    getline(cin, input);
                    input = "0";
                }
            }
            system("clear");
            input = "0";
        } else if (input == "5") // Credits
        {
            system("clear");
            cout << "Game made by Charlie Park\nCSCI 1300 Project 3\n"
                 << "Press enter to go back\n";
            getline(cin, input);
            system("clear");
            input = "0";
        } else if (input == "6") // Quit
        {
            system("clear");
            cout << "Goodbye!\n";
        } else // Invalid Input
        {
            system("clear");
            cout << "Invalid Input\n"
                 << "Press enter to go back\n";
            getline(cin, input);
            system("clear");
            input = "0";
        }
    }


    return 0;
}