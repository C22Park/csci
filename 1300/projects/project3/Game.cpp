#include "Map.cpp"
#include "randomizer.cpp"
#include "split.cpp"
#include <fstream> 
#include <ctype.h>

using namespace std;

void activeCheats(bool active_cheats[6])
{
    cout << "Cheats:\n"
                            << "1. I can see my house from here";
                        if (active_cheats[0]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n2. Money Bags";
                        if (active_cheats[1]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n3. 501st";
                        if (active_cheats[2]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n4. Super Soldiers";
                        if (active_cheats[3]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n5. Zerg Rush";
                        if (active_cheats[4]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n6. Money Bags";
                        if (active_cheats[5]) 
                        {
                            cout << " [ACTIVE]";
                        }
                        cout << "\n";
}

string gameMenu(string username, Map map[1],  int enemy_spawn_rate, int resource_spawn_rate, int day, bool active_cheats[6], int max_army_size, int enemies_killed)
{
    string input;
    cout << username << "'s Kingom | " << map[0].player_army.getGold() << " Gold | " << (day + 1) % 10 << " day of the year " << day / 10 << "\n"
         << "Use w/a/s/d to move | Commands: ";
    int row = map[0].player_army.getRow();
    int col = map[0].player_army.getCol();
    string temp_string;
    if (map[0].trueSpace(row, col) == map[0].RESOURCE)
    {
        cout << "investigate resource | ";
    }
    cout << "options\n";
    getline(cin, input);
    if (input == "w" || input == "W")
    {
        input = "w";
    } else if (input == "a" || input == "A")
    {
        input ="a";
    } else if (input == "s" || input == "S")
    {
        input ="s";
    } else if (input == "d" || input == "D")
    {
        input ="d";
    } else if (input == "options")
    {
        while (input == "options")
        {
            system("clear");
            cout << "Settings:\n"
                 << "1. Information\n"
                 << "2. Quit Game\n";
            getline(cin, input);
            if (input == "1")
            {
                input = "cheats";
                while (input == "cheats")
                {
                    system("clear");
                    cout << map[0].player_army.getName() << "'s Kingdom:\n"
                         << "Max army size: " << max_army_size << "\n"
                         << "Gold: " << map[0].player_army.getGold() << "\n"
                         << "Buildings: " << map[0].buildings.size() << "\n"
                         << "Resources per year: " << resource_spawn_rate << "\n"
                         << "Enemy spawns per year: " << enemy_spawn_rate << "\n"
                         << "Enemies killed: " << enemies_killed << "\n"
                         << "Press enter to go back\n";
                    getline(cin, input);
                    if (input == "cheats")
                    {
                        system("clear");
                        activeCheats(active_cheats);
                        cout << "Press enter to go back\n";
                        getline(cin, input);
                        input = "cheats";
                    }
                }
                input = "options";
            } else if (input == "2")
            {
                input = "exit";
            } else
            {
                system("clear");
                cout << "Invalid Input\n"
                << "Press enter to continue\n";
                getline(cin, input);
                input = "options";
            }
        }
    } else if (input == "investigate resource" && map[0].trueSpace(row, col) == map[0].RESOURCE)
    {
        system("clear");
        for (int i = 0; i < map[0].resources.size(); i++)
        {
            if (map[0].resources[i].isPosition(row, col))
            {
                cout << map[0].resources[i].getName() << ":\n"
                     << map[0].resources[i].getResourceDescription() << "\n"
                     << "You collect " << map[0].resources[i].getReward() << " gold.\n"
                     << "Press enter to continue\n";
                getline(cin, input);
                input = "investigate resource";
                map[0].player_army.setGold(map[0].player_army.getGold() + map[0].resources[i].getReward());
                map[0].resources.erase(map[0].resources.begin() + i);
            }
        }
    } else
    {
        cout << "Invalid Input\n"
                << "Press enter to continue\n";
        getline(cin, input);
        input = "";
    }
    
    return input;
}

void playGame(string username, Map map, int enemy_spawn_rate, int resource_spawn_rate, bool active_cheats[6])
{
    int day = 0;
    string input;
    fstream file;
    Map game[1] = {map};
    if (username == "")
    {
        username = "Player";
    }
    game[0].player_army.setName(username);
    int max_army_size = game[0].player_army.getArmySize();
    int enemies_killed = 0;

    for (int i = 0; i < resource_spawn_rate; i++)
    {
        system("clear");
        cout << "Loading Resources... " << i * 100 / static_cast<double>(resource_spawn_rate) << "%\n";
        bool successfully_placed = false;
        int row;
        int col;
        int resource;
        string temp_arr[3];
        while (!successfully_placed)
        {
            row = randomNum(0, game[0].getNumRows() - 1);
            col = randomNum(0, game[0].getNumCols() - 1);
            if (game[0].trueSpace(row, col) == ' ')
            {
                resource = randomNum(0, 1);
                if (resource)
                {
                    file.open("Boulder.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                } else 
                {
                    resource = randomNum(0, 1);
                    file.open("Forest.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                }
                game[0].resources.push_back(Resource(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), row, col));
                successfully_placed = true;
            }
        }
    }

    if (active_cheats[0])
    {
        for (int i = 0; i < game[0].getNumRows(); i++)
        {
            for (int j = 0; j < game[0].getNumCols(); j++)
            {
                game[0].setMap(i, j);
            }
        }
    }
    if (active_cheats[1])
    {
        game[0].player_army.setGold(1000000);
    }
    
    while (input != "exit")
    {
        system("clear");
        if (game[0].player_army.getArmySize() > max_army_size)
        {
            max_army_size = game[0].player_army.getArmySize();
        }
        game[0].displayMap();
        input = gameMenu(username, game, enemy_spawn_rate, resource_spawn_rate, day, active_cheats, max_army_size, enemies_killed);
        if (input == "w")
        {
            if (game[0].move('w'))
            {
                day++;
            }
        } else if (input == "a")
        {
            if (game[0].move('a'))
            {
                day++;
            }
        } else if (input == "s")
        {
            if (game[0].move('s'))
            {
                day++;
            }
        } else if (input == "d")
        {
            if (game[0].move('d'))
            {
                day++;
            }
        }
    }
}

int main()
{
    system("clear");
    Map game;
    game.player_army.setGold(125);
    game.player_army.setArmySize(10);
    int enemy_spawn_rate = 1;
    int resource_spawn_rate = 15;
    bool active_cheats[6] = {0,0,0,0,0,0};
    string input = "0";
    ifstream file;
    ofstream ofile;
    while (input != "6")
    {
        cout << "KINGDOM RUSH\n"
             << "1. Start Game\n"
             << "2. How to Play\n"
             << "3. High Scores\n"
             << "4. Settings\n"
             << "5. Credits\n"
             << "6. Quit\n";
        
        getline(cin, input);

        if (input == "1") // Start Game
        {
            system("clear");
            cout << "Enter the name of your kingdom:\n";
            getline(cin, input);
            playGame(input, game, enemy_spawn_rate, resource_spawn_rate, active_cheats);
            system("clear");
        } else if (input == "2") // How to Play
        {
            system("clear");
            cout << "How to play Kingdom Rush\n"
                 << "Explore the map using WASD\n"
                 << "If you find resource nodes you can get gold from them\n"
                 << "Use gold to construct buildings and grow your army\n"
                 << "Try to get the largest army possible before your gold reaches 0\n"
                 << "See how long you can last!\n"
                 << "Press enter to go back\n";
            getline(cin, input);
            system("clear");
            input = "0";
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
                             << "1. Easy (125 gold, 10 soldiers, 1 enemy per day, 15 resources per year)\n"
                             << "2. Medium (25 gold, 5 soldiers, 2 enemies per day, 10 resources per year)\n"
                             << "3. Hard (10 gold, 1 soldier, 3 enemies per day, 1 resource per year)\n";
                        getline(cin, input);
                        system("clear");
                        if (input == "1")
                        {
                            game.player_army.setGold(125);
                            game.player_army.setArmySize(10);
                            enemy_spawn_rate = 1;
                            resource_spawn_rate = 15;
                            input = "0";
                        } else if (input == "2")
                        {
                            game.player_army.setGold(25);
                            game.player_army.setArmySize(5);
                            enemy_spawn_rate = 2;
                            resource_spawn_rate = 10;
                        } else if (input == "3")
                        {
                            game.player_army.setGold(10);
                            game.player_army.setArmySize(1);
                            enemy_spawn_rate = 3;
                            resource_spawn_rate = 5;
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
                    ofile << "USERNAME | ARMY SIZE | DAYS LASTED\n";
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