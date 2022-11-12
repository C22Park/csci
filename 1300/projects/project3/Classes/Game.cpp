#include "Game.h"
//#include "Map.cpp"

using namespace std;

Game::Game(bool active_cheats[7], string username, int difficulty) // paramaterized constructor
{
    for (int i = 0; i < 7; i++)
    {
        active_cheats_[i] = active_cheats[i];
    }

    if (username == "")
    {
        username_ = "Player";
    } else
    {
        username_ = username;
    }
    day_ = 0;
    enemies_killed_ = 0;
    materials_[0] = 0;
    materials_[1] = 0;
    reserve_view = false;

    if (difficulty == 1)
    {
        map.player_army.setGold(200);
        map.player_army.setArmySize(10);
        enemy_spawn_rate_ = 2;
        resource_spawn_rate_ = 5;
    } else if (difficulty == 2)
    {
        map.player_army.setGold(120);
        map.player_army.setArmySize(5);
        enemy_spawn_rate_ = 4;
        resource_spawn_rate_ = 3;   
    } else if (difficulty == 3)
    {
        map.player_army.setGold(55);
        map.player_army.setArmySize(1);
        enemy_spawn_rate_ = 6;
        resource_spawn_rate_ = 1;
    }
}

/*
    Algorithm:
        - Find the difference in strength between the player and the army on its tile
        - Display amount of enmy soldier
        - If player is stronger kill diference # of enemy soldiers and display that amount
        - If enemy is stronger kill difference # of player soldiers and display that amount
        - Otherwise display they tied
        - returns the number of enemy soldiers killed
*/

void Game::fightEnemy() // calculates fighting mechanics on tile player is on
{
    int difference = 0;
    string input;

    for (int i = 0; i < map.enemy_armies.size(); i++)
    {
        if (map.enemy_armies[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
        {
            difference = map.player_army.getArmyStrength() - map.enemy_armies[i].getArmyStrength();
            if (difference < 0)
            {
                if (-difference >= map.player_army.getArmySize())
                {
                    cout << "You run into " << map.enemy_armies[i].getArmySize() << " enemies and lose " << map.player_army.getArmySize() << " soldiers.\n"
                        << "Press enter to continue\n";
                    getline(cin, input);
                } else
                {
                    cout << "You run into " << map.enemy_armies[i].getArmySize() << " enemies and lose " << -difference << " soldiers.\n"
                        << "Press enter to continue\n";
                    getline(cin, input);
                }
                map.player_army.setArmySize(map.player_army.getArmySize() + difference);
            } else if (difference > 0)
            {
                if (difference >= map.enemy_armies[i].getArmySize())
                {
                    cout << "You run into " << map.enemy_armies[i].getArmySize() << " enemies and kill " << map.enemy_armies[i].getArmySize() << " soldiers.\n"
                         << "You loot " << map.enemy_armies[i].getGold() << " gold.\n"
                         << "Press enter to continue\n";
                    getline(cin, input);
                    map.player_army.setGold(map.player_army.getGold() + map.enemy_armies[i].getGold());
                    enemies_killed_ += map.enemy_armies[i].getArmySize();
                    map.enemy_armies.erase(map.enemy_armies.begin() + i);
                } else
                {
                    cout << "You run into " << map.enemy_armies[i].getArmySize() << " enemies and kill " << difference << " soldiers.\n"
                    << "Press enter to continue\n";
                    getline(cin, input);
                    map.enemy_armies[i].setArmySize(map.enemy_armies[i].getArmySize() - difference);
                    enemies_killed_ += difference;
                }
            } else
            {
                cout << "You run into " << map.enemy_armies[i].getArmySize() << " enemies and tie in battle.\n"
                    << "Press enter to continue\n";
                getline(cin, input);
            }
        }
    }
}

string Game::gameMenu() // map and menu, returns players input 
{
    string input;
    int row = map.player_army.getRow();
    int col = map.player_army.getCol();
    int num_conquering_parties = 0;
    int num_banks = 0;
    int num_sweatshops = 0;

    // STATS AND MAP

    for (int i = 0; i < map.buildings.size(); i++)
    {
        if (map.buildings[i].getName() == "Conquering Party")
        {
            num_conquering_parties++;
        } else if (map.buildings[i].getName() == "Bank")
        {
            num_banks++;
        } else if (map.buildings[i].getName() == "Sweatshop")
        {
            num_sweatshops++;
        }
    }

    cout << username_ << "'s Kingdom | " << map.player_army.getGold() << " Gold | " << (num_conquering_parties * 40) + (num_banks * 50) - (num_sweatshops * 75) - map.player_army.getArmySize() << " Gold/year | " << materials_[0] << " Stone | " << materials_[1] << " Wood" << "\n"
         << map.player_army.getArmySize() << " Soldiers | " << map.player_army.getArmyStrength() << " Strength | Day " << (day_ % 20) + 1 << " Year " << day_ / 20 << " | Position: (" << map.player_army.getRow() + 1 << ", " << map.player_army.getCol() + 1 << ") ";
    for (int i = 0; i < map.resources.size(); i++)
    {
        if (map.resources[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
        {
            cout << map.resources[i].getName();
        }
    }
    for (int i = 0; i < map.buildings.size(); i++)
    {
        if (map.buildings[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
        {
            cout << map.buildings[i].getName();
            if (map.buildings[i].getName() == "Barracks")
            {
                cout << " - " << map.buildings[i].getReserve() << " Soldiers";
            } else if (map.buildings[i].getName() == "Gold Mine")
            {
                cout << " - " << map.buildings[i].getReserve() << " Gold";
            } else if (map.buildings[i].getName() == "Military Acadamy")
            {
                cout << " - " << map.buildings[i].getReserve() << " Soldiers";
            } else if (map.buildings[i].getName() == "Quarry")
            {
                cout << " - " << map.buildings[i].getReserve() << " Stone";
            }else if (map.buildings[i].getName() == "Lumber Camp")
            {
                cout << " - " << map.buildings[i].getReserve() << " Wood";
            }
        }
    }
    for (int i = 0; i < map.enemy_armies.size(); i++)
    {
        if (map.enemy_armies[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
        {
            cout << map.enemy_armies[i].getName() << " - " << map.enemy_armies[i].getArmySize() << " Soldiers";
        }
    }
    cout << "\n";

    if (reserve_view)
    {
        for (int i = 0; i < map.buildings.size(); i++)
                {
                    for (int j = 0; j < map.getNumRows(); j++)
                    {
                        for (int k = 0; k < map.getNumCols(); k++)
                        {
                            if (map.buildings[i].isPosition(j, k))
                            {
                                if (map.buildings[i].getReserve() >= 10)
                                {
                                    map.changeMapData("F", j, k);
                                } else
                                {
                                    map.changeMapData(to_string(map.buildings[i].getReserve()), j, k);
                                }
                            }
                            if (map.player_army.isPosition(j, k))
                            {
                                map.changeMapData("X", j, k);
                            }
                        }
                    }
                }
    }
    map.displayMap();


    // COMMANDS
    cout << "Use w/a/s/d to move | Commands: ";
    if (map.trueSpace(row, col) == map.RESOURCE || map.trueSpace(row, col) == map.BUILDING)
    {
        cout << "investigate | ";
        for (int i = 0; i < map.buildings.size(); i++)
        {
            if (map.buildings[i].isPosition(row, col))
            {
                if (map.buildings[i].getName() == "Barracks" || map.buildings[i].getName() == "Gold Mine" || map.buildings[i].getName() == "Blacksmith")
                {
                    cout << "upgrade | ";
                }
            }
        }
    } else if (map.trueSpace(row, col) == map.EXPLORED)
    {
        cout << "build | ";
    }  else if (map.trueSpace(row, col) == map.ENEMY_ARMY)
    {
        cout << "fight | ";
    }
    cout << "options\n\n";

    // USER INPUT
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
    } else if (input == "options") // Option Menu
    {
        while (input == "options")
        {
            system("clear");
            cout << "Settings:\n"
                 << "1. Information\n"
                 << "2. Return to Game\n"
                 << "3. Quit to Main Menu\n\n";
            getline(cin, input);
            if (input == "1")
            {
                input = "cheats";
                while (input == "cheats")
                {
                    system("clear");
                    cout << map.player_army.getName() << "'s Kingdom:\n"
                         << "Max army size: " << max_army_size_ << "\n"
                         << "Gold: " << map.player_army.getGold() << "\n"
                         << "Buildings: " << map.buildings.size() << "\n"
                         << "Resources per year: " << resource_spawn_rate_ << "\n"
                         << "Enemy spawns per year: " << enemy_spawn_rate_ << "\n"
                         << "Enemies killed: " << enemies_killed_ << "\n"
                         << "Press enter to go back\n";
                    getline(cin, input);
                    if (input == "cheats")
                    {
                        system("clear");
                        activeCheats(active_cheats_);
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
        if (map.trueSpace(row, col) != map.RESOURCE && map.trueSpace(row, col) != map.BUILDING)
        {
            cout << "Invalid Input\n"
                << "Press enter to continue\n";
            getline(cin, input);
            input = "";    
        }
    } else if (input == "upgrade")
    {
        for (int i = 0; i < map.buildings.size(); i++)
        {
            if (map.buildings[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
            {
                if (map.buildings[i].getName() != "Barracks" && map.buildings[i].getName() != "Gold Mine" && map.buildings[i].getName() != "Blacksmith")
                {
                    cout << "Invalid Input\n"
                        << "Press enter to continue\n";
                    getline(cin, input);
                    input = "";       
                }
            }
        }
    } else if (input == "build")
    {
        if (map.trueSpace(row, col) != map.EXPLORED)
        {
            cout << "Invalid Input\n"
                << "Press enter to continue\n";
            getline(cin, input);
            input = "";    
        }
    } else if (input == "fight")
    {
        if (map.trueSpace(row, col) != map.ENEMY_ARMY)
        {
            cout << "Invalid Input\n"
                << "Press enter to continue\n";
            getline(cin, input);
            input = "";    
        }
    } else if (input == "r")
    {} else
    {
        cout << "Invalid Input\n"
                << "Press enter to continue\n";
        getline(cin, input);
        input = "";
    }
    
    return input;
}

void Game::playGame() // runs game
{
    int year = 0;
    bool new_year = false;
    bool didMove = false;
    string input;
    fstream file;
    ofstream ofile;
    string temp_arr[3];

    // CREATE MAP
    if (active_cheats_[5])
    {
        resource_spawn_rate_ = 15;
    }
    int row;
    int col;
    int resource;
    for (int i = 0; i < resource_spawn_rate_; i++)
    {
        bool successfully_placed = false;
        while (!successfully_placed)
        {
            row = randomNum(0, map.getNumRows() - 1);
            col = randomNum(0, map.getNumCols() - 1);
            resource = randomNum(1, 12);
            if (map.trueSpace(row, col) == map.EXPLORED)
            {
                if (resource >= 1 && resource <= 4)
                {
                    file.open("Resources/Boulder.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 5 && resource <= 8)
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
                map.resources.push_back(Resource(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), row, col));
                if (map.isExplored(row, col))
                {
                    map.setMap(row, col);
                }
                successfully_placed = true;
            }
        }
    }

    // CHEATS
    if (active_cheats_[0])
    {
        for (int i = 0; i < map.getNumRows(); i++)
        {
            for (int j = 0; j < map.getNumCols(); j++)
            {
                map.setMap(i, j);
            }
        }
    }
    if (active_cheats_[1])
    {
        map.player_army.setGold(1000000);
    }
    if (active_cheats_[2])
    {
        map.player_army.setArmySize(200000);
    }
    if (active_cheats_[3])
    {
        map.player_army.setStrengthMultiplier(10);
    }
    if (active_cheats_[4])
    {
        enemy_spawn_rate_ = 5;
    }
    if (active_cheats_[6])
    {
        materials_[0] = 100;
        materials_[1] = 100;
    }

    // GAME
    bool new_highscore = true;
    while (input != "exit")
    {
        if (map.player_army.getGold() <= 0 || map.player_army.getArmySize() <= 0) // Lose Condition
        {
            system("clear");
            cout << "GAME OVER\n";
            cout << "Max Soldiers: " << max_army_size_ << "\n"
                << "Days Lasted: " << day_ << "\n"
                << "Press enter to continue\n";
            getline(cin, input);
            system("clear");

            file.open("highscores.txt");
            getline(file, input);
            while(getline(file, input))
            {
                split(input, '|', temp_arr, 3);
                if (max_army_size_ <= stoi(temp_arr[1]))
                {
                    new_highscore = false;
                } 
            }
            if (new_highscore)
            {
                cout << "***NEW HIGHSCORE***\n"
                     << "Press enter to continue\n";
                getline(cin, input);
                system("clear");
            }
            file.close();

            ofile.open("highscores.txt", ios::app);
            ofile << username_ << " | " << max_army_size_ << " | " << day_ << " | ";
            if (active_cheats_[0] || active_cheats_[1] || active_cheats_[2] || active_cheats_[3] || active_cheats_[4] || active_cheats_[5] || active_cheats_[6])
            {
                ofile << "CHEATER\n";
            } else if (resource_spawn_rate_ == 5)
            {
                ofile << "EASY\n";
            } else if (resource_spawn_rate_ == 3)
            {
                ofile << "MEDIUM\n";
            } else if (resource_spawn_rate_ == 1)
            {
                ofile << "HARD\n";
            }
            ofile.close();
            return;
        }

        system("clear");

        if (map.player_army.getArmySize() > max_army_size_) // High Score
        {
            max_army_size_ = map.player_army.getArmySize();
        }

        // MENU AND PLAYER INPUT
        input = Game::gameMenu();

        if (input == "w")
        {
            if (map.move('w'))
            {
                didMove = true;
            }
        } else if (input == "a")
        {
            if (map.move('a'))
            {
                didMove = true;
            }
        } else if (input == "s")
        {
            if (map.move('s'))
            {
                didMove = true;
            }
        } else if (input == "d")
        {
            if (map.move('d'))
            {
                didMove = true;
            }
        } else if (input == "investigate")
        {
            system ("clear");
            
            for (int i = 0; i < map.resources.size(); i++)
            {
                if (map.resources[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
                {
                    cout << map.resources[i].getName() << "\n"
                         << map.resources[i].getResourceDescription() << "\n\n";
                    if (map.resources[i].getName() == "Boulder" || map.resources[i].getName() == "Forest" || map.resources[i].getName() == "Chest")
                    {
                        cout << "You collect " << map.resources[i].getReward() << " gold.\n";
                        if (map.resources[i].getName() == "Boulder")
                        {
                            materials_[0]++;
                            cout << "You collect 1 stone.\n";
                        }
                        if (map.resources[i].getName() == "Forest")
                        {
                            materials_[1]++;
                            cout << "You collect 1 wood.\n";
                        }
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setGold(map.player_army.getGold() + map.resources[i].getReward());
                        map.resources.erase(map.resources.begin() + i);
                    } else if (map.resources[i].getName() == "Ransacked Village")
                    {
                        cout << "You gain 2 soldiers.\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setArmySize(map.player_army.getArmySize() + 2);
                        map.resources.erase(map.resources.begin() + i);
                    } else if (map.resources[i].getName() == "Ancient Temple")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .1);
                        map.resources.erase(map.resources.begin() + i);   
                    } else if (map.resources[i].getName() == "Dragon's Hoard")
                    {
                        cout << "You collect " << map.resources[i].getReward() << " gold.\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setGold(map.player_army.getGold() + map.resources[i].getReward());
                        map.resources.erase(map.resources.begin() + i);   
                    }
                }
            }

            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
                {
                    cout << map.buildings[i].getName() << "\n"
                         << map.buildings[i].getBuildingDescription() << "\n\n";
                    if (map.buildings[i].getName() == "Barracks")
                    {
                        cout << map.buildings[i].getReserve() << " soldiers picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setArmySize(map.player_army.getArmySize() + map.buildings[i].getReserve());
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Military Acadamy")
                    {
                        cout << map.buildings[i].getReserve() << " soldiers picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setArmySize(map.player_army.getArmySize() + map.buildings[i].getReserve());
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Conquering Party")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Gold Mine")
                    {
                        cout << map.buildings[i].getReserve() << " gold picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setGold(map.player_army.getGold() + map.buildings[i].getReserve());
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Market")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Bank")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Blacksmith")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Sweatshop")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Quarry")
                    {
                        cout << map.buildings[i].getReserve() << " stone picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        materials_[0] += map.buildings[i].getReserve();
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Lumber Camp")
                    {
                        cout << map.buildings[i].getReserve() << " wood picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        materials_[0] += map.buildings[i].getReserve();
                        map.buildings[i].setReserve(0);
                    }
                }
            }
        } else if (input == "upgrade")
        {
            system("clear");
            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
                {
                    cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                         << map.buildings[i].getName() << " Upgrades\n";
                    if (map.buildings[i].getName() == "Barracks")
                    {
                        while (input != "3")
                        {
                            cout << "1. Barracks -(1 Stone 2 Wood)-> Military Acadamy\n"
                                 << "   Makes 3 soldiers per year\n"
                                 << "2. Barracks -(2 Soldiers 1 Stone 1 Wood)-> Conquering Party\n"
                                 << "   Costs 2 soldiers a year and automatically collects 40 gold per year\n"
                                 << "3. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && materials_[0] >= 1 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Military Acadamy", "Makes 3 soldiers per year", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0]--;
                                materials_[1] -= 2;
                                input = "3";
                            } else if (input == "2" && map.player_army.getArmySize() > 2 && materials_[0] >= 1 && materials_[1] >= 1)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Conquering Party", "Costs 2 soldiers a year and automatically collects 40 gold per year", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setArmySize(map.player_army.getArmySize() - 2);
                                materials_[0]--;
                                materials_[1]--;
                                input = "3";
                            } else if (input == "3")
                            {} else
                            {
                                system("clear");
                                cout << "Invalid Input\n"
                                     << "Press enter to continue\n";
                                getline(cin, input);
                                input = "upgrade";    
                            }
                        }
                    } else if (map.buildings[i].getName() == "Gold Mine")
                    {
                        while (input != "3")
                        {
                            cout << "1. Gold Mine -(2 Stone 2 Wood)-> Market\n"
                                 << "   2 gold per turn with automatic collection\n"
                                 << "2. Gold Mine -(5 Stone)-> Bank\n"
                                 << "   50 gold per year with automatic collection\n"
                                 << "3. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Market", "2 gold per turn with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                input = "3";
                            } else if (input == "2" && materials_[0] >= 5)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Bank", "50 gold per year with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 5;
                                input = "3";
                            } else if (input == "3")
                            {} else
                            {
                                system("clear");
                                cout << "Invalid Input\n"
                                     << "Press enter to continue\n";
                                getline(cin, input);
                                input = "upgrade";    
                            }
                        }
                    } else if (map.buildings[i].getName() == "Blacksmith")
                    {
                        while (input != "4")
                        {
                            cout << "1. Blacksmith -(5 Soldiers 2 Stone 2 Wood)-> Sweatshop\n"
                                 << "   .1x multiplier per year -75 gold per year\n"
                                 << "2. Blacksmith -(3 Stone 1 Wood)-> Quarry\n"
                                 << "   2 stone per year\n"
                                 << "3. Blacksmith -(1 Stone 3 Wood)-> Lumber Camp\n"
                                 << "   2 wood per year\n"
                                 << "4. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && map.player_army.getArmySize() > 5 && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Sweatshop", ".1x multiplier per year -75 gold per year", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setArmySize(map.player_army.getArmySize() - 5);
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                input = "4";
                            } else if (input == "2" && materials_[0] >= 3 && materials_[1] >= 1)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Quarry", "2 stone per year", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 3;
                                materials_[1]--;
                                input = "4";
                            } else if (input == "3" && materials_[0] >= 1 && materials_[1] >= 3)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Lumber Camp", "2 wood per year", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] --;
                                materials_[1] -= 3;
                                input = "4";
                            } else if (input == "4")
                            { 
                            }else
                            {
                                system("clear");
                                cout << "Invalid Input\n"
                                     << "Press enter to continue\n";
                                getline(cin, input);
                                input = "upgrade";    
                            }
                        }
                    }
                }
            }
        } else if (input == "build")
        {
            while (input == "build")
            {
                system("clear");
                cout << "Gold: " << map.player_army.getGold() << "\n"
                     << "Buildings:\n"
                     << "1. Barracks 25g (Makes 1 soldier per year)\n"
                     << "2. Gold Mine 50g (Makes 1 gold every day, stores 15 gold max)\n"
                     << "3. Blacksmith 150g (Increases your strength multiplier by .1x)\n"
                     << "4. Exit\n\n";
                getline(cin, input);
                if (input == "1" && map.player_army.getGold() >= 25)
                {
                    map.buildings.push_back(Building("Barracks", "Makes 1 soldiers per year", map.player_army.getRow(), map.player_army.getCol()));
                    map.player_army.setGold(map.player_army.getGold() - 25);
                } else if (input == "2" && map.player_army.getGold() >= 50)
                {
                    map.buildings.push_back(Building("Gold Mine", "Makes 1 gold every day, stores 15 gold max", map.player_army.getRow(), map.player_army.getCol()));
                    map.player_army.setGold(map.player_army.getGold() - 50);
                } else if (input == "3" && map.player_army.getGold() >= 150)
                {
                    map.buildings.push_back(Building("Blacksmith", "Increses your strength multiplier by .1x", map.player_army.getRow(), map.player_army.getCol()));
                    map.player_army.setGold(map.player_army.getGold() - 150);
                    map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .1);
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
        } else if (input == "fight")
        {
            system("clear");
            Game::fightEnemy();
        } else if (input == "r")
        {
            if (reserve_view)
            {
                reserve_view = false;
                for (int i = 0; i < map.buildings.size(); i++)
                {
                    for (int j = 0; j < map.getNumRows(); j++)
                    {
                        for (int k = 0; k < map.getNumCols(); k++)
                        {
                            if (map.buildings[i].isPosition(j, k))
                            {
                                map.setMap(j, k);
                            }
                        }
                    }
                }
            } else
            {
                reserve_view = true;
            }
        }

        // END OF TURN ACTIONS
        if (didMove)
        {
            if (map.trueSpace(map.player_army.getRow(), map.player_army.getCol()) == map.ENEMY_ARMY) // If user walks on enemy tile
            {
                system("clear");
                Game::fightEnemy();
                system("clear");
            } 

            didMove = false;
            day_++;
            year = day_ / 20;
            if (day_ % 20 == 0)
            {
                new_year = true;
            } else
            {
                new_year = false;
            }

            if (new_year) // Upkeep Cost
            {
                map.player_army.setGold(map.player_army.getGold() - map.player_army.getArmySize());
            }



            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].getName() == "Barracks" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 1);
                } else if (map.buildings[i].getName() == "Gold Mine" && map.buildings[i].getReserve() < 15)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 1);
                } else if (map.buildings[i].getName() == "Military Acadamy" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 3);
                } else if (map.buildings[i].getName() == "Conquering Party" && new_year)
                {
                    map.player_army.setArmySize(map.player_army.getArmySize() - 2);
                    map.player_army.setGold(map.player_army.getGold() + 40);
                } else if (map.buildings[i].getName() == "Market")
                {
                    map.player_army.setGold(map.player_army.getGold() + 2);
                } else if (map.buildings[i].getName() == "Bank" && new_year)
                {
                    map.player_army.setGold(map.player_army.getGold() + 50);
                } else if (map.buildings[i].getName() == "Sweatshop" && new_year)
                {
                    map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .1);
                    map.player_army.setGold(map.player_army.getGold() - 75);
                } else if (map.buildings[i].getName() == "Quarry" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 2);
                } else if (map.buildings[i].getName() == "Lumber Camp" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 2);
                }
            }

            if (new_year && year % 10 == 0)
            {
                enemy_spawn_rate_++;
            }

            if (new_year)
            {
                for (int i = 0; i < enemy_spawn_rate_; i++)
                {
                    row = randomNum(0, map.getNumRows() - 1);
                    col = randomNum(0, map.getNumCols() - 1);
                    if (map.trueSpace(row, col) == map.EXPLORED)
                    {
                        map.enemy_armies.push_back(Army("Enemy", ((year / 10) + 2) * year, 1 + (year / 25.0), 2 * year,row,col));
                        if (map.isExplored(row, col))
                        {
                            map.setMap(row, col);
                        }
                    } else if (map.trueSpace(row, col) == map.ENEMY_ARMY)
                    {
                        for (int j = 0; j < map.enemy_armies.size(); j++)
                        {
                            if (map.enemy_armies[j].isPosition(row, col))
                            {
                                map.enemy_armies[j].setArmySize(map.enemy_armies[j].getArmySize() + (((year / 10) + 2) * year));
                                map.enemy_armies[j].setStrengthMultiplier(1 + (year / 25.0));
                                map.enemy_armies[j].setGold(map.enemy_armies[j].getGold() + (2 * year));
                            }
                        }
                    } else if (map.trueSpace(row, col) == map.BUILDING)
                    {
                        system("clear");
                        cout << "Enenmy forces ransacked one of your buildings. You lose " << 5 * year << " gold.\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "";
                        map.player_army.setGold(map.player_army.getGold() - (5 * year));
                        system("clear");
                    }
                }

                for (int i = 0; i < resource_spawn_rate_; i++)
                {
                    row = randomNum(0, map.getNumRows() - 1);
                    col = randomNum(0, map.getNumCols() - 1);
                    resource = randomNum(1, 12);
                    if (map.trueSpace(row, col) == map.EXPLORED)
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
                        map.resources.push_back(Resource(temp_arr[0], temp_arr[1], stoi(temp_arr[2]), row, col));
                        if (map.isExplored(row, col))
                        {
                            map.setMap(row, col);
                        }
                    }
                }
            }
        }
    }
    
    system("clear");
    file.open("highscores.txt");
    getline(file, input);
    while(getline(file, input))
    {
        split(input, '|', temp_arr, 3);
        if (max_army_size_ <= stoi(temp_arr[1]))
        {
            new_highscore = false;
        } 
    }
    if (new_highscore)
    {
        cout << "***NEW HIGHSCORE***\n"
                << "Press enter to continue\n";
        getline(cin, input);
        system("clear");
    }
    file.close();

    ofile.open("highscores.txt", ios::app);
    ofile << username_ << " | " << max_army_size_ << " | " << day_ << " | ";
    if (active_cheats_[0] || active_cheats_[1] || active_cheats_[2] || active_cheats_[3] || active_cheats_[4] || active_cheats_[5])
    {
        ofile << "CHEATER\n";
    } else if (resource_spawn_rate_ == 5)
    {
        ofile << "EASY\n";
    } else if (resource_spawn_rate_ == 3)
    {
        ofile << "MEDIUM\n";
    } else if (resource_spawn_rate_ == 1)
    {
        ofile << "HARD\n";
    }
    ofile.close();
}

void Game::howToPlay()
{
    string input;

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 1 Year 1 | Position: (7, 7)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "This is the starting state of the map\n"
            << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    map.enemy_armies.push_back(Army("Enemy", 0, 0, 0, 6, 6)); // spawns an enemy above the player
    map.setMap(6, 6);
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 1 Year 1 | Position: (7, 7)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Enemies that spawn on the map look like E\n"
            << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    map.buildings.push_back(Building("Building", "Building Description", 6, 7)); // spawns a building above the player
    map.setMap(6, 7);
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 1 Year 1 | Position: (7, 7)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Buildings the player make look like B\n"
            << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    map.resources.push_back(Resource("Resource", "Resource Description", 0, 6, 8)); // spawns a resource above the player
    map.setMap(6, 8);
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 1 Year 1 | Position: (7, 7)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Resources the player can collect look like R\n"
            << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 1 Year 1 | Position: (7, 7)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "The player moves with w a s d, every time you move one day passes in game\n";
    sleep(1);
    system("clear");

    map.move('d');
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 2 Year 1 | Position: (7, 8)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "The player moves with w a s d, every time you move one day passes in game\n";
    sleep(1);
    system("clear");

    map.resources.push_back(Resource("Resource", "Resource Description", 10, 7, 9));
    map.move('d');
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 3 Year 1 | Position: (7, 9) Boulder\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: investigate | options\n\n";
    cout << "The player moves with w a s d, every time you move one day passes in game\n";
    sleep(1);
    system("clear");

    map.move('d');
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 4 Year 1 | Position: (7, 10)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "The player moves with w a s d, every time you move one day passes in game\n";
    sleep(1);
    system("clear");

    map.move('d');
    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "When the player reahces an unexplored space, '-', they explore it and any objects there will be exposed\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Using the commands below the map the player can build or interact with objects. This interaction can result in\n"
         << "getting gold or soldiers from the players buildings, rewards from resources, or looted gold if the successfully fight an enemy\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.changeMapData("5", 6, 7);
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Entering 'r' as a command will toggle reserve view, in reserve view you can see how many soldiers\n" 
         << "or gold are in your buildings,any value over 10 shows up as F\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.changeMapData("B", 6, 7);
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Every year is 20 days, each year you pay 1 gold for every soldier for upkeep\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Additionally, every year more enemies and resources spawn, enemies can spawn on your buildings stealing gold from you\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "The game ends when your gold or the size of your army is 0. Good Luck!!!\n"
         << "Press enter to go back to the main menu\n";
    getline(cin, input);
    system("clear");
}