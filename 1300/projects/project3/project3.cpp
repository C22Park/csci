/* To Do:
    1. Display current reserve in buildings as special view if hotkey is pressed, idek if this one possible
    2. Write code skeleton driver
    3.write all algorithms and comments
        -For code skeleton
        -For full game
    4. balance game
    5. implement upgrades
        -You can only upgrade a building to a second tier form
            -Barracks -(2 Stone 2 Wood)-> Military Acadamy | 4 soldier per year .1x strength per year
            -Barracks -(2 Food 1 Wood)-> Conquering Party | 2 soldier per year 100 gold per year
            -Gold Mine -(2 Wood 2 stone)-> Market | 5 gold per turn
            -Blacksmith -(2 stone 5 soldiers)-> Sweatshop | .1x multiplier per year -100 gold per year
    6. New cheats!!
*/
#include <iostream>
#include <fstream> 
#include <ctype.h>
#include <unistd.h>
#include "Classes/randomizer.cpp"
#include "Classes/split.cpp"
#include "Classes/activeCheats.cpp"
#include "Classes/Map.cpp"
#include "Classes/Game.cpp"

using namespace std;

void howToPlay()
{
    Map map;

    map.displayMap();
        cout << "This is the starting state of the map\n"
             << "Press enter to continue\n";
        string input;
        getline(cin, input);
        system("clear");

        map.enemy_armies.push_back(Army("Enemy", 0, 0, 0, 6, 6)); // spawns an enemy above the player
        map.setMap(6, 6);
        map.displayMap();
        cout << "Enemies that spawn on the map look like E\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.buildings.push_back(Building("Building", "Building Description", 6, 7)); // spawns a building above the player
        map.setMap(6, 7);
        map.displayMap();
        cout << "Buildings the player make look like B\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.resources.push_back(Resource("Resource", "Resource Description", 0, 6, 8)); // spawns a resource above the player
        map.setMap(6, 8);
        map.displayMap();
        cout << "Resources the player can collect look like R\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.displayMap();
        cout << "The player moves with w a s d\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.buildings.push_back(Building("Building", "Building Description", 7, 9));
        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.move('d');
        map.displayMap();
        cout << "When the player reahces an unexplored space, '-', they explore it and any objects there will be exposed\n"
             << "Press enter to go back to menu\n";
        getline(cin, input);
        system("clear");
}

int main()
{
    system("clear");
    string input = "0";
    ifstream file;
    ofstream ofile;
    string temp_arr[3];
    bool active_cheats[6] = {0, 0, 0, 0, 0, 0};
    int difficulty = 1;

    while (input != "6")
    {
        cout << "KINGDOM RUSH\n"
             << "1. Start Game\n"
             << "2. How to Play\n"
             << "3. High Scores\n"
             << "4. Settings\n"
             << "5. Credits\n"
             << "6. Quit Game\n";
        
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

        } else if (input == "2") // How to Play
        {
            system("clear");
            cout << "How to play Kingdom Rush\n"
                 << "Explore the map using wasd\n"
                 << "Investigating resource nodes can net you gold or power\n"
                 << "Make buildings to gain gold or grow your army\n"
                 << "Enemies will try to steal from your buildings and fight you on the map\n"
                 << "Your soldiers require 1 gold each every year\n"
                 << "The game ends when your gold reaches 0 or your army is completely wiped out\n"
                 << "See how long you can last!\n"
                 << "Press enter to see the game\n";
            getline(cin, input);
            system("clear");
            input = "0";
            howToPlay();
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
                    << "3. Return to Menu\n";
                getline(cin, input);
                if (input == "1")
                {
                    while (input == "1")
                    {
                        system("clear");
                        cout << "Difficulties:\n"
                             << "1. Easy (200 gold, 10 soldiers, 2 enemy armies per year per year, 5 resources per year)\n"
                             << "2. Medium (120 gold, 5 soldiers, 4 enemy armies per year per year, 3 resources per year)\n"
                             << "3. Hard (55 gold, 1 soldier, 6 enemy armies per year per year, 1 resource per year)\n";
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
                    while(input != "7")
                    {
                        system("clear");
                        activeCheats(active_cheats);
                        cout << "7. Exit\n";
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