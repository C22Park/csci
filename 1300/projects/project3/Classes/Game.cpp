#include "Game.h"

using namespace std;

Game::Game(bool active_cheats[6], string username, int difficulty)
{
    for (int i = 0; i < 6; i++)
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

void Game::fightEnemy()
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

string Game::gameMenu()
{
    string input;
    int row = map.player_army.getRow();
    int col = map.player_army.getCol();

    map.displayMap();
    cout << username_ << "'s Kingdom | " << map.player_army.getGold() << " Gold | " << -map.player_army.getArmySize() << " Gold/year | " << materials_[0] << " Stone | " << materials_[1] << " Wood" << "\n"
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
    cout << "\nUse w/a/s/d to move | Commands: ";
    if (map.trueSpace(row, col) == map.RESOURCE || map.trueSpace(row, col) == map.BUILDING)
    {
        cout << "investigate | ";
    } else if (map.trueSpace(row, col) == map.EXPLORED)
    {
        cout << "build | ";
    }  else if (map.trueSpace(row, col) == map.ENEMY_ARMY)
    {
        cout << "fight | ";
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
                 << "3. Quit to Main Menu\n";
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
    } else
    {
        cout << "Invalid Input\n"
                << "Press enter to continue\n";
        getline(cin, input);
        input = "";
    }
    
    return input;
}

void Game::playGame()
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
            return;
        }

        system("clear");
        if (map.player_army.getArmySize() > max_army_size_)
        {
            max_army_size_ = map.player_army.getArmySize();
        }
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
                    cout << map.resources[i].getName() << ":\n"
                         << map.resources[i].getResourceDescription() << "\n";
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
                    cout << map.buildings[i].getName() << ";\n"
                         << map.buildings[i].getBuildingDescription() << "\n";
                    if (map.buildings[i].getName() == "Barracks")
                    {
                        cout << map.buildings[i].getReserve() << " soldiers picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setArmySize(map.player_army.getArmySize() + map.buildings[i].getReserve());
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Gold Mine")
                    {
                        cout << map.buildings[i].getReserve() << " gold picked up\n"
                             << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                        map.player_army.setGold(map.player_army.getGold() + map.buildings[i].getReserve());
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Blacksmith")
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
                cout << "Gold: " << map.player_army.getGold() << "\n"
                     << "Buildings:\n"
                     << "1. Barracks 20g (Makes 2 soldier per year)\n"
                     << "2. Gold Mine 50g (Makes 1 gold every day, stores 25 gold max)\n"
                     << "3. Blacksmith 150g (Increases your strength multiplier by .1x)\n"
                     << "4. Exit\n";
                getline(cin, input);
                if (input == "1" && map.player_army.getGold() >= 20)
                {
                    map.buildings.push_back(Building("Barracks", "Makes 2 soldiers per year", map.player_army.getRow(), map.player_army.getCol()));
                    map.player_army.setGold(map.player_army.getGold() - 20);
                } else if (input == "2" && map.player_army.getGold() >= 50)
                {
                    map.buildings.push_back(Building("Gold Mine", "Makes 1 gold every day, stores 25 gold max", map.player_army.getRow(), map.player_army.getCol()));
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
        }
        if (didMove)
        {
            if (map.trueSpace(map.player_army.getRow(), map.player_army.getCol()) == map.ENEMY_ARMY)
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

            if (new_year)
            {
                map.player_army.setGold(map.player_army.getGold() - map.player_army.getArmySize());
            }



            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].getName() == "Barracks" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 2);
                } else if (map.buildings[i].getName() == "Gold Mine" && map.buildings[i].getReserve() < 25)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 1);
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
                        map.enemy_armies.push_back(Army("Enemy", ((year / 10) + 2) * year, 1 + (year / 100.0), ((year / 10) + 1) * year,row,col));
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
                                map.enemy_armies[j].setStrengthMultiplier(1 + (year / 100.0));
                                map.enemy_armies[j].setGold(map.enemy_armies[j].getGold() + (((year / 10) + 1) * year));
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