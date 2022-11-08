/* To Do:
    1. Combat from current location
    2. Fix how to play
    3. Display current reserve in buildings while on map (Position marker and map showing values of squares if hotkey pressed)
    4. balance resources
    5. implement crafting
        -materials from fights or resources
        -You can only "craft" by upgrading a building to a second tier form
            -Barracks -(2 Stone 2 Wood)-> Military Acadamy | 2 soldier per year .1x strength per year
            -Barracks -(2 Food 1 Wood)-> Conquering Party | 1 soldier per year 100 gold per year
            -Gold Mine -(2 Wood)-> Market | 5 gold per turn
            -Blacksmith -(2 stone 5 soldier)-> Sweatshop | .3x strength per year -25 gold per year
    6. New cheats!!
*/

#include "Classes/Map.cpp"
#include "Classes/randomizer.cpp"
#include "Classes/split.cpp"
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
    cout << "\n2. Scrooge McDuck";
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
    cout << "\n6. Cornucopia";
    if (active_cheats[5]) 
    {
        cout << " [ACTIVE]";
    }
    cout << "\n";
}

int fightEnemy(Map map[1])
{
    int difference = 0;
    string input;
    for (int i = 0; i < map[0].enemy_armies.size(); i++)
    {
        if (map[0].enemy_armies[i].isPosition(map[0].player_army.getRow(), map[0].player_army.getCol()))
        {
            difference = map[0].player_army.getArmyStrength() - map[0].enemy_armies[i].getArmyStrength();
            if (difference < 0)
            {
                if (difference > map[0].player_army.getArmySize())
                {
                    cout << "You run into " << map[0].enemy_armies[i].getArmySize() << " enemies and lose " << map[0].player_army.getArmySize() << " soldiers.\n"
                        << "Press enter to continue\n";
                    getline(cin, input);
                } else
                {
                    cout << "You run into " << map[0].enemy_armies[i].getArmySize() << " enemies and lose " << -difference << " soldiers.\n"
                        << "Press enter to continue\n";
                    getline(cin, input);
                }
                map[0].player_army.setArmySize(map[0].player_army.getArmySize() + difference);
                return 0;
            } else if (difference > 0)
            {
                if (difference > map[0].enemy_armies[i].getArmySize())
                {
                    cout << "You run into " << map[0].enemy_armies[i].getArmySize() << " enemies and kill " << map[0].enemy_armies[i].getArmySize() << " soldiers.\n"
                    << "Press enter to continue\n";
                    getline(cin, input);
                    map[0].player_army.setGold(map[0].player_army.getGold() + map[0].enemy_armies[i].getGold());
                    map[0].enemy_armies.erase(map[0].enemy_armies.begin() + i);
                } else
                {
                    cout << "You run into " << map[0].enemy_armies[i].getArmySize() << " enemies and kill " << difference << " soldiers.\n"
                    << "Press enter to continue\n";
                    getline(cin, input);
                    map[0].player_army.setGold(map[0].player_army.getGold() - difference);  
                    map[0].enemy_armies[i].setArmySize(map[0].enemy_armies[i].getArmySize() - difference);
                }
                return difference;
            } else
            {
                cout << "You run into " << map[0].enemy_armies[i].getArmySize() << " enemies and tie in battle.\n"
                    << "Press enter to continue\n";
                getline(cin, input);
                return 0;
            }
        }
    }
    return 0;
}

string gameMenu(string username, Map map[1], int enemy_spawn_rate, int resource_spawn_rate, int day, bool active_cheats[6], int max_army_size, int enemies_killed)
{
    string input;
    int row = map[0].player_army.getRow();
    int col = map[0].player_army.getCol();
    if (map[0].trueSpace(row, col) == map[0].ENEMY_ARMY)
    {
        system("clear");
        enemies_killed = fightEnemy(map);
        system("clear");
        if (map[0].player_army.getArmySize() <= 0)
        {
            return "exit";
        }
        map[0].displayMap();
    }

    cout << username << "'s Kingdom | " << map[0].player_army.getGold() << " Gold | " << "day " << (day % 20) + 1 << " of the year " << day / 20 << "\n"
         << map[0].player_army.getArmySize() << " Soldiers | " << map[0].player_army.getArmyStrength() << " Strength | Position: " << map[0].player_army.getRow() << ", " << map[0].player_army.getCol() << " ";
    for (int i = 0; i < map[0].resources.size(); i++)
    {
        if (map[0].resources[i].isPosition(map[0].player_army.getRow(), map[0].player_army.getCol()))
        {
            cout << map[0].resources[i].getName();
        }
    }
    for (int i = 0; i < map[0].buildings.size(); i++)
    {
        if (map[0].buildings[i].isPosition(map[0].player_army.getRow(), map[0].player_army.getCol()))
        {
            cout << map[0].buildings[i].getName();
        }
    }
    cout << "\nUse w/a/s/d to move | Commands: ";
    string temp_string;
    if (map[0].trueSpace(row, col) == map[0].RESOURCE || map[0].trueSpace(row, col) == map[0].BUILDING)
    {
        cout << "investigate | ";
    } else if (map[0].trueSpace(row, col) == map[0].EXPLORED)
    {
        cout << "build | ";
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
                 << "2. Return to Game\n"
                 << "3. Quit Game\n";
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
            {} else if (input == "3")
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
    } else if (input == "investigate")
    {
        if (map[0].trueSpace(row, col) != map[0].RESOURCE && map[0].trueSpace(row, col) != map[0].BUILDING)
        {
            cout << "Invalid Input\n"
                << "Press enter to continue\n";
            getline(cin, input);
            input = "";    
        }
    } else if (input == "build")
    {
        if (map[0].trueSpace(row, col) != map[0].EXPLORED)
        {
            cout << "Invalid Input\n"
                << "Press enter to continue\n";
            getline(cin, input);
            input = "";    
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

void playGame(string username, Map map, int enemy_spawn_rate, int resource_spawn_rate, bool active_cheats[6], int data[2])
{
    int day = 0;
    int year = 0;
    bool didMove = false;
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
    int row;
    int col;
    int resource;
    string temp_arr[3];

    if (active_cheats[5])
    {
        resource_spawn_rate = 25;
    }
    for (int i = 0; i < resource_spawn_rate; i++)
    {
        system("clear");
        cout << "Loading Resources... " << i * 100 / static_cast<double>(resource_spawn_rate) << "%\n";
        bool successfully_placed = false;
        while (!successfully_placed)
        {
            row = randomNum(0, game[0].getNumRows() - 1);
            col = randomNum(0, game[0].getNumCols() - 1);
            resource = randomNum(1, 12);
            if (game[0].trueSpace(row, col) == ' ')
            {
                if (resource >= 1 && resource <= 5)
                {
                    file.open("Resources/Boulder.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 6 && resource <= 8)
                {
                    file.open("Resources/Forest.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 8 && resource <= 9)
                {
                    file.open("Resources/Chest.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource == 10)
                {
                    file.open("Resources/Ransacked_Village.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource == 11)
                {
                    file.open("Resources/Ancient_Temple.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else
                {
                    file.open("Resources/Dragons_Hoard.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
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
    if (active_cheats[2])
    {
        game[0].player_army.setArmySize(200000);
    }
    if (active_cheats[3])
    {
        game[0].player_army.setStrengthMultiplier(10);
    }
    if (active_cheats[4])
    {
        enemy_spawn_rate = 5;
    }

    
    while (input != "exit")
    {
        system("clear");
        if (game[0].player_army.getArmySize() > max_army_size)
        {
            max_army_size = game[0].player_army.getArmySize();
        }
        system("clear");
        if (game[0].trueSpace(game[0].player_army.getRow(), game[0].player_army.getRow()) == game[0].ENEMY_ARMY)
        {
            enemies_killed = fightEnemy(game);
            system("clear");
        } 
        game[0].displayMap();
        input = gameMenu(username, game, enemy_spawn_rate, resource_spawn_rate, day, active_cheats, max_army_size, enemies_killed);
        if (input == "w")
        {
            if (game[0].move('w'))
            {
                didMove = true;
            }
        } else if (input == "a")
        {
            if (game[0].move('a'))
            {
                didMove = true;
            }
        } else if (input == "s")
        {
            if (game[0].move('s'))
            {
                didMove = true;
            }
        } else if (input == "d")
        {
            if (game[0].move('d'))
            {
                didMove = true;
            }
        } else if (input == "investigate")
        {
            system("clear");
            for (int i = 0; i < game[0].resources.size(); i++)
            {
                if (game[0].resources[i].isPosition(game[0].player_army.getRow(), game[0].player_army.getCol()))
                {
                    cout << game[0].resources[i].getName() << ":\n"
                        << game[0].resources[i].getResourceDescription() << "\n";
                    if (game[0].resources[i].getName() == "Boulder" || game[0].resources[i].getName() == "Forest" || game[0].resources[i].getName() == "Chest")
                    {
                        cout << "You collect " << game[0].resources[i].getReward() << " gold.\n"
                            << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setGold(game[0].player_army.getGold() + game[0].resources[i].getReward());
                        game[0].resources.erase(game[0].resources.begin() + i);
                    } else if (game[0].resources[i].getName() == "Ransacked Village")
                    {
                        cout << "You gain 2 soldiers.\n"
                            << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setArmySize(game[0].player_army.getArmySize() + 2);
                        game[0].resources.erase(game[0].resources.begin() + i);
                    } else if (game[0].resources[i].getName() == "Ancient Temple")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setStrengthMultiplier(game[0].player_army.getStrengthMultiplier() + .1);
                        game[0].resources.erase(game[0].resources.begin() + i);   
                    } else if (game[0].resources[i].getName() == "Dragon's Hoard")
                    {
                        cout << "You collect " << game[0].resources[i].getReward() << " gold.\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setGold(game[0].player_army.getGold() + game[0].resources[i].getReward());
                        game[0].resources.erase(game[0].resources.begin() + i);   
                    }
                }
            }
            for (int i = 0; i < game[0].buildings.size(); i++)
            {
                if (game[0].buildings[i].isPosition(game[0].player_army.getRow(), game[0].player_army.getCol()))
                {
                    cout << game[0].buildings[i].getName() << ";\n"
                         << game[0].buildings[i].getBuildingDescription() << "\n";
                    if (game[0].buildings[i].getName() == "Barracks")
                    {
                        cout << game[0].buildings[i].getReserve() << " soldiers picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setArmySize(game[0].player_army.getArmySize() + game[0].buildings[i].getReserve());
                        game[0].buildings[i].setReserve(0);
                    } else if (game[0].buildings[i].getName() == "Gold Mine")
                    {
                        cout << game[0].buildings[i].getReserve() << " gold picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        game[0].player_army.setGold(game[0].player_army.getGold() + game[0].buildings[i].getReserve());
                        game[0].buildings[i].setReserve(0);
                    } else if (game[0].buildings[i].getName() == "Blacksmith")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    }
                }
            }
        } else if (input == "build")
        {
            while (input == "build")
            {
                system("clear");
                cout << "Gold: " << game[0].player_army.getGold() << "\n"
                     << "Buildings:\n"
                     << "1. Barracks 20g (Makes one soldier per year)\n"
                     << "2. Gold Mine 50g (Makes 3 gold per day)\n"
                     << "3. Blacksmith 75g (Increases strength by .1x per year)\n"
                     << "4. Exit\n";
                getline(cin, input);
                if (input == "1" && game[0].player_army.getGold() >= 20)
                {
                    game[0].buildings.push_back(Building("Barracks", "Makes one soldier per year", game[0].player_army.getRow(), game[0].player_army.getCol()));
                    game[0].player_army.setGold(game[0].player_army.getGold() - 20);
                } else if (input == "2" && game[0].player_army.getGold() >= 50)
                {
                    game[0].buildings.push_back(Building("Gold Mine", "Makes 3 gold per day", game[0].player_army.getRow(), game[0].player_army.getCol()));
                    game[0].player_army.setGold(game[0].player_army.getGold() - 50);
                } else if (input == "3" && game[0].player_army.getGold() >= 75)
                {
                    game[0].buildings.push_back(Building("Blacksmith", "Increses strength by .1x per year", game[0].player_army.getRow(), game[0].player_army.getCol()));
                    game[0].player_army.setGold(game[0].player_army.getGold() - 75);
                } else if (input == "4")
                {} else
                {
                    system("clear");
                    cout << "Invalid Input\n"
                         << "Press enter to continue\n";
                    getline(cin, input);
                    input = "build";    
                }
            }
        }
        if (didMove)
        {
            didMove = false;
            day++;
            year = day / 20;
            if (day % 2 == 0)
            {
                game[0].player_army.setGold(game[0].player_army.getGold() - game[0].player_army.getArmySize());
            }
            if (game[0].player_army.getGold() <= 0 || game[0].player_army.getArmySize() <= 0)
            {
                system("clear");
                cout << "GAME OVER\n"
                    << "Max Soldiers: " << max_army_size << "\n"
                    << "Days Lasted: " << day << "\n"
                    << "Press enter to continue\n";
                getline(cin, input);
                input = "exit";
            }
            for (int i = 0; i < game[0].buildings.size(); i++)
            {
                if (game[0].buildings[i].getName() == "Barracks" && day % 20 == 0)
                {
                    game[0].buildings[i].setReserve(game[0].buildings[i].getReserve() + 1);
                } else if (game[0].buildings[i].getName() == "Gold Mine")
                {
                    game[0].buildings[i].setReserve(game[0].buildings[i].getReserve() + 3);
                } else if (game[0].buildings[i].getName() == "Blacksmith" && day % 20 == 0)
                {
                    game[0].player_army.setStrengthMultiplier(game[0].player_army.getStrengthMultiplier() + .1);
                }
            }
            if (day % 20 == 0)
            {
                for (int i = 0; i < enemy_spawn_rate * (1 + (year / 10)); i++)
                {
                    row = randomNum(0, game[0].getNumRows() - 1);
                    col = randomNum(0, game[0].getNumCols() - 1);
                    if (game[0].trueSpace(row, col) == game[0].EXPLORED)
                    {
                        game[0].enemy_armies.push_back(Army("Enemy", 5 * (year + 1), 1 + (year / 10), 10 * (year + 1),row,col));
                        if (game[0].isExplored(row, col))
                        {
                            game[0].setMap(row, col);
                        }
                    } else if (game[0].trueSpace(row, col) == game[0].ENEMY_ARMY)
                    {
                        for (int j = 0; j < game[0].enemy_armies.size(); j++)
                        {
                            if (game[0].enemy_armies[j].isPosition(row, col))
                            {
                                game[0].enemy_armies[j].setArmySize(game[0].enemy_armies[j].getArmySize() + (5 * (year + 1)));
                                game[0].enemy_armies[j].setStrengthMultiplier(1 + (year / 10));
                                game[0].enemy_armies[j].setGold(game[0].enemy_armies[j].getGold() + 10 * (year + 1));
                            }
                        }
                    }
                }
                for (int i = 0; i < resource_spawn_rate; i++)
                {
                    row = randomNum(0, game[0].getNumRows() - 1);
                    col = randomNum(0, game[0].getNumCols() - 1);
                    resource = randomNum(1, 12);
                    if (game[0].trueSpace(row, col) == ' ')
                    {
                        if (resource >= 1 && resource <= 5)
                        {
                            file.open("Resources/Boulder.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 6 && resource <= 8)
                        {
                            file.open("Resources/Forest.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 8 && resource <= 9)
                        {
                            file.open("Resources/Chest.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource == 10)
                        {
                            file.open("Resources/Ransacked_Village.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource == 11)
                        {
                            file.open("Resources/Ancient_Temple.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else
                        {
                            file.open("Resources/Dragons_Hoard.txt");
                                    getline(file, input);
                                    split(input, ',', temp_arr, 3);
                                    file.close();
                        }
                        game[0].resources.push_back(Resource(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), row, col));
                        if (game[0].isExplored(row, col))
                        {
                            game[0].setMap(row, col);
                        }
                    }
                }
            }
        }
    }
    data[0] = max_army_size;
    data[1] = day;
}

int main()
{
    system("clear");
    Map game;
    game.player_army.setGold(500);
    game.player_army.setArmySize(10);
    int enemy_spawn_rate = 1;
    int resource_spawn_rate = 15;
    bool active_cheats[6] = {0,0,0,0,0,0};
    string input = "0";
    ifstream file;
    ofstream ofile;
    int temp_data[2];
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
            cout << "Enter your username:\n";
            getline(cin, input);
            playGame(input, game, enemy_spawn_rate, resource_spawn_rate, active_cheats, temp_data);
            system("clear");
            ofile.open("highscores.txt", ios::app);
            if (input == "")
            {
                input = "Player";
            }
            ofile << input << " | " << temp_data[0] << " | " << temp_data[1] << "\n";
            ofile.close();
            input = "1";
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
                             << "1. Easy (500 gold, 10 soldiers, 1 enemies per year per year, 15 resources per year)\n"
                             << "2. Medium (250 gold, 5 soldiers, 2 enemies per year per year, 10 resources per year)\n"
                             << "3. Hard (50 gold, 1 soldier, 3 enemies per year per year, 1 resource per year)\n";
                        getline(cin, input);
                        system("clear");
                        if (input == "1")
                        {
                            game.player_army.setGold(500);
                            game.player_army.setArmySize(10);
                            enemy_spawn_rate = 1;
                            resource_spawn_rate = 15;
                            input = "0";
                        } else if (input == "2")
                        {
                            game.player_army.setGold(250);
                            game.player_army.setArmySize(5);
                            enemy_spawn_rate = 2;
                            resource_spawn_rate = 10;
                        } else if (input == "3")
                        {
                            game.player_army.setGold(50);
                            game.player_army.setArmySize(1);
                            enemy_spawn_rate = 3;
                            resource_spawn_rate = 5;
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