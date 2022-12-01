#include "Game.h"

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
        map.player_army.setGold(500);
        map.player_army.setArmySize(10);
        enemy_spawn_rate_ = 2;
        resource_spawn_rate_ = 5;
    } else if (difficulty == 2)
    {
        map.player_army.setGold(300);
        map.player_army.setArmySize(5);
        enemy_spawn_rate_ = 3;
        resource_spawn_rate_ = 3;   
    } else if (difficulty == 3)
    {
        map.player_army.setGold(150);
        map.player_army.setArmySize(1);
        enemy_spawn_rate_ = 5;
        resource_spawn_rate_ = 2;
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
    int num_trading_posts = 0;
    int num_banks = 0;
    int num_sweatshops = 0;
    int num_trading_guilds = 0;
    int num_serf_homes = 0;

    // STATS AND MAP

    for (int i = 0; i < map.buildings.size(); i++)
    {
        if (map.buildings[i].getName() == "Conquering Party")
        {
            num_conquering_parties++;
        } else if (map.buildings[i].getName() == "Trading Post")
        {
            num_trading_posts++;
        } else if (map.buildings[i].getName() == "Bank")
        {
            num_banks++;
        } else if (map.buildings[i].getName() == "Sweatshop")
        {
            num_sweatshops++;
        } else if (map.buildings[i].getName() == "Trading Guild")
        {
            num_trading_guilds++;
        } else if (map.buildings[i].getName() == "Serf Homes")
        {
            num_serf_homes++;
        }
    }

    cout << username_ << "'s Kingdom | " << map.player_army.getGold() << " Gold | " << (num_conquering_parties * 25) - (num_trading_posts * 25) + (num_banks * 50) - (num_sweatshops * 75) + (num_trading_guilds * 200) + (num_serf_homes * 25) - map.player_army.getArmySize() << " Gold/year | " << materials_[0] << " Stone | " << materials_[1] << " Wood" << "\n"
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
                if (map.buildings[i].getName() == "Barracks" || map.buildings[i].getName() == "Gold Mine" || map.buildings[i].getName() == "Blacksmith" || map.buildings[i].getName() == "Keep" || map.buildings[i].getName() == "Wall" || map.buildings[i].getName() == "Trading Guild" || map.buildings[i].getName() == "Military Police" || map.buildings[i].getName() == "Wizard Acadamy")
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
                if (map.buildings[i].getName() != "Barracks" && map.buildings[i].getName() != "Gold Mine" && map.buildings[i].getName() != "Blacksmith" && map.buildings[i].getName() != "Keep" && map.buildings[i].getName() != "Wall")
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
        resource_spawn_rate_ = 10;
    }
    int row;
    int col;
    int resource;
    for (int i = 0; i < resource_spawn_rate_; i++)
    {
        bool successfully_placed = false;
        while (!successfully_placed)
        {
            row = randomNum(0, map.getNumRows());
            col = randomNum(0, map.getNumCols());
            resource = randomNum(1, 100);
            if (map.trueSpace(row, col) == map.EXPLORED)
            {
                if (resource >= 1 && resource <= 25)
                {
                    file.open("Resources/Boulder.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 26 && resource <= 50)
                {
                    file.open("Resources/Forest.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 51 && resource <= 70)
                {
                    file.open("Resources/Chest.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 71 && resource <= 85)
                {
                    file.open("Resources/Ransacked_Village.txt");
                    getline(file, input);
                    split(input, ',', temp_arr, 3);
                    file.close();
                } else if (resource >= 86 && resource <= 95)
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
        enemy_spawn_rate_ = 10;
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
            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].getName() == "Wizard Acadamy")
                {
                    resource_spawn_rate_--;
                }
            }
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
            } else if (resource_spawn_rate_ == 2)
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
                    if (map.resources[i].getName() == "Boulder" || map.resources[i].getName() == "Forest")
                    {
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
                        map.resources.erase(map.resources.begin() + i);
                    } else if (map.resources[i].getName() == "Chest")
                    {
                        cout << "You collect " << map.resources[i].getReward() << " gold.\n"
                             << "Press enter to continue\n";
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
                        map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .05);
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
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
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
                    } else if (map.buildings[i].getName() == "Bonfire")
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
                        materials_[1] += map.buildings[i].getReserve();
                        map.buildings[i].setReserve(0);
                    } else if (map.buildings[i].getName() == "Keep")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Wall")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Trading Guild")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Military Police")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Wizard Acadamy")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Archer Tower")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Serf Homes")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    } else if (map.buildings[i].getName() == "Survey Tower")
                    {
                        cout << "Press enter to continue\n";
                        getline(cin, input);
                        input = "investigate";
                    }
                }
            }
        } else if (input == "upgrade")
        {
            for (int i = 0; i < map.buildings.size(); i++)
            {
                if (map.buildings[i].isPosition(map.player_army.getRow(), map.player_army.getCol()))
                {
                    if (map.buildings[i].getName() == "Barracks")
                    {
                        while (input != "4")
                        {
                            system("clear");
                            cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                                 << map.buildings[i].getName() << " Upgrades\n";
                            cout << "1. Barracks -(2 Stone 2 Wood)-> Military Acadamy\n"
                                 << "   Makes 2 soldiers per year with automatic collection\n"
                                 << "2. Barracks -(2 Soldiers 1 Stone 1 Wood)-> Conquering Party\n"
                                 << "   Costs 1 soldiers a year and automatically collects 25 gold per year\n"
                                 << "3. Barracks -(1 Soldier 1 Stone 2 Wood)-> Trading Post\n"
                                 << "   -25 gold per year 1 random material with automatic collection\n"
                                 << "4. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Military Acadamy", "Makes 2 soldiers per year with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                input = "4";
                            } else if (input == "2" && map.player_army.getArmySize() > 2 && materials_[0] >= 1 && materials_[1] >= 1)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Conquering Party", "Costs 1 soldiers a year and automatically collects 25 gold per year", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setArmySize(map.player_army.getArmySize() - 2);
                                materials_[0]--;
                                materials_[1]--;
                                input = "4";
                            } else if (input == "3" && map.player_army.getArmySize() > 1 && materials_[0] >= 1 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Trading Post", "-25 gold per year 1 random material with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setArmySize(map.player_army.getArmySize() - 1);
                                materials_[0]--;
                                materials_[1] -= 2;
                                input = "4";
                            } else if (input == "4")
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
                        while (input != "4")
                        {
                            system("clear");
                            cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                                 << map.buildings[i].getName() << " Upgrades\n";
                            cout << "1. Gold Mine -(2 Stone 2 Wood)-> Market\n"
                                 << "   1 gold per turn and a chance of 1 wood or 1 stone a year, with automatic collection\n"
                                 << "2. Gold Mine -(5 Stone)-> Bank\n"
                                 << "   50 gold per year with automatic collection\n"
                                 << "3. Gold Mine -(3 Wood)-> Bonfire\n"
                                 << "   Protects against an enemy raid, then is destroyed\n"
                                 << "4. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Market", "1 gold per turn and a chance of 1 wood or 1 stone, with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                input = "4";
                            } else if (input == "2" && materials_[0] >= 5)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Bank", "50 gold per year with automatic collection", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 5;
                                input = "4";
                            } else if (input == "3" && materials_[1] >= 3)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Bonfire", "Protects against an enemy raid then is destroyed", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[1] -= 3;
                                input = "4";
                            } else if (input == "4")
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
                            system("clear");
                            cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                                 << map.buildings[i].getName() << " Upgrades\n";
                            cout << "1. Blacksmith -(5 Soldiers 2 Stone 2 Wood)-> Sweatshop\n"
                                 << "   .05x multiplier per year -75 gold per year\n"
                                 << "2. Blacksmith -(3 Stone 1 Wood)-> Quarry\n"
                                 << "   1 stone per year\n"
                                 << "3. Blacksmith -(1 Stone 3 Wood)-> Lumber Camp\n"
                                 << "   1 wood per year\n"
                                 << "4. Cancel\n\n";
                            getline(cin, input);
                            if (input == "1" && map.player_army.getArmySize() > 5 && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Sweatshop", ".05x multiplier per year -75 gold per year", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setArmySize(map.player_army.getArmySize() - 5);
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                input = "4";
                            } else if (input == "2" && materials_[0] >= 3 && materials_[1] >= 1)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Quarry", "1 stone per year", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 3;
                                materials_[1]--;
                                input = "4";
                            } else if (input == "3" && materials_[0] >= 1 && materials_[1] >= 3)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.buildings.push_back(Building("Lumber Camp", "1 wood per year", map.player_army.getRow(), map.player_army.getCol()));
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
                    } else if (map.buildings[i].getName() == "Keep")
                    {
                        while (input == "upgrade")
                        {
                            system("clear");
                            cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                                << "Upgrades:\n"; 
                            int wall_count = 0;
                            for (int i = 0; i < map.buildings.size(); i++)
                            {
                                if (map.buildings[i].getName() == "Wall" || map.buildings[i].getName() == "Archer Tower" || map.buildings[i].getName() == "Serf Homes" || map.buildings[i].getName() == "Survey Tower")
                                {
                                    wall_count++;
                                }
                            }
                            if (wall_count == 8)
                            {
                                cout << "1. Keep -(500 Gold 2 Stone 4 Wood)-> Trading Guild\n"
                                     << "   Produces 200g 1 wood and 1 stone every year automatically collected\n"
                                     << "2. Keep -(25 Soldiers 3 Stone 3 Wood)-> Military Police\n"
                                     << "   Automatically produce 5 soldier a day and .05x strength per year\n"
                                     << "3. Keep -(250 Gold 10 Soldiers 2 Stone 2 Wood)-> Wizard Acadamy\n"
                                     << "   +1 resource per year .1x strength per year\n"
                                     << "4. Exit\n\n";
                                getline(cin, input);
                                if (input == "1" && map.player_army.getGold() > 500 && materials_[0] >= 2 && materials_[1] >= 4)
                                {
                                    map.buildings.erase(map.buildings.begin() + i);
                                    map.player_army.setGold(map.player_army.getGold() - 500);
                                    materials_[0] -= 2;
                                    materials_[1] -= 4;
                                    map.buildings.push_back(Building("Trading Guild", "Produces 200g 1 wood and 1 stone every year automatically collected", map.player_army.getRow(), map.player_army.getCol()));
                                } else if (input == "2" && map.player_army.getArmySize() > 25 && materials_[0] >= 3 && materials_[1] >= 3)
                                {
                                    map.buildings.erase(map.buildings.begin() + i);
                                    map.player_army.setArmySize(map.player_army.getArmySize() - 25);
                                    materials_[0] -= 4;
                                    materials_[1] -= 3;
                                    map.buildings.push_back(Building("Military Police", "Automatically produce 1 soldier a day and .05x strength per year", map.player_army.getRow(), map.player_army.getCol()));
                                } else if (input == "3" && map.player_army.getGold() > 250 && map.player_army.getArmySize() > 10 && materials_[0] >= 2 && materials_[1] >= 2)
                                {
                                    map.buildings.erase(map.buildings.begin() + i);
                                    map.player_army.setGold(map.player_army.getGold() - 250);
                                    map.player_army.setArmySize(map.player_army.getArmySize() - 10);
                                    materials_[0] -= 2;
                                    materials_[1] -= 2;
                                    resource_spawn_rate_++;
                                    map.buildings.push_back(Building("Wizard Acadamy", "+1 resource per year .1x strength per year", map.player_army.getRow(), map.player_army.getCol()));
                                } else if (input == "4")
                                {} else
                                {
                                    system("clear");
                                    cout << "Invalid Input\n"
                                         << "Press enter to continue\n";
                                    getline(cin, input);
                                    input = "upgrade";    
                                }
                            } else
                            {
                                cout << "Come back when you finish the walls of your castle...\n"
                                    << "Press enter to continue\n";
                                getline(cin, input);
                                input = "";
                            }
                        }
                    } else if (map.buildings[i].getName() == "Wall")
                    {
                        while (input == "upgrade")
                        {
                            system("clear");
                            cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                                << "Upgrades:\n"
                                << "1. Wall -(5 Soldiers 1 Stone 2 Wood)-> Archer Tower\n"
                                << "   Attacks one enemy within 2 units every turn\n"
                                << "2. Wall -(25 Gold 2 Stone 2 Wood)-> Serf Homes\n"
                                << "   2 soldiers per year and 25 gold per year automatically collected\n"
                                << "3. Wall -(2 Stone 4 Wood)-> Survey Tower\n"
                                << "   Collects one resource within 2 units every turn\n"
                                << "4. Exit\n\n";
                            getline(cin, input);
                            if (input == "1" && map.player_army.getArmySize() > 5 && materials_[0] >= 1 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.player_army.setArmySize(map.player_army.getArmySize() - 5);
                                materials_[0]--;
                                materials_[1] -= 2;
                                map.buildings.push_back(Building("Archer Tower", "Attacks one enemy within 2 units every turn", map.player_army.getRow(), map.player_army.getCol()));
                            } else if (input == "2" && map.player_army.getGold() > 25 && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                map.player_army.setGold(map.player_army.getGold() - 25);
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                                map.buildings.push_back(Building("Serf Homes", "2 soldiers per year and 25 gold per year automatically collected", map.player_army.getRow(), map.player_army.getCol()));
                            } else if (input == "3" && materials_[0] >= 2 && materials_[1] >= 4)
                            {
                                map.buildings.erase(map.buildings.begin() + i);
                                materials_[0] -= 2;
                                materials_[1] -= 4;
                                map.buildings.push_back(Building("Survey Tower", "Collects one resource within 2 units every turn", map.player_army.getRow(), map.player_army.getCol()));
                            } else if (input == "4")
                            {} else
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
                cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                     << "Buildings:\n"
                     << "1. Barracks 25g (Makes 1 soldier per year)\n"
                     << "2. Gold Mine 50g (Makes 1 gold every day, stores 15 gold max)\n"
                     << "3. Blacksmith 150g (Increases your strength multiplier by .05x)\n"
                     << "4. Castle Construction\n"
                     << "5. Upgrade List\n"
                     << "6. Exit\n\n";
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
                    map.buildings.push_back(Building("Blacksmith", "Increses your strength multiplier by .05x", map.player_army.getRow(), map.player_army.getCol()));
                    map.player_army.setGold(map.player_army.getGold() - 150);
                    map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .1);
                } else if (input == "4")
                {
                    while (input == "4")
                    {
                        system("clear");
                        bool keepExists = false;
                        cout << "Gold: " << map.player_army.getGold() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                             << "Castle Construction:\n";
                        for (int i = 0; i < map.buildings.size(); i++)
                        {
                            if (map.buildings[i].getName() == "Keep" || map.buildings[i].getName() == "Trading Guild" || map.buildings[i].getName() == "Military Police" || map.buildings[i].getName() == "Wizard Acadamy")
                            {
                                keepExists = true;
                            }
                        }
                        if (!keepExists)
                        {
                            cout << "1. Keep 500g 5 stone 3 wood (The core of your castle, boosts army strength by .2x)\n"
                                 << "   Surround your keep with walls to be able to upgrade your castle\n"
                                 << "2. Wall 2 stone 2 wood (Expand your castle in the 3x3 around it\n"
                                 << "   Walls can be upgraded to enhance your castle\n"
                                 << "3. Exit\n\n";
                        } else
                        {
                            cout << "1. Wall 2 stone 2 wood (Expand your castle in the 3x3 around it)\n"
                                 << "2. Exit\n\n";
                        }
                        getline(cin, input);
                        if (keepExists)
                        {
                            if (input == "1")
                            {
                                for (int i = 0; i < map.buildings.size(); i++)
                                {
                                    if (map.buildings[i].getName() == "Keep")
                                    {
                                        if (map.player_army.getCol() > map.buildings[i].getCol() + 1 || map.player_army.getCol() < map.buildings[i].getCol() - 1)
                                        {
                                            input = "invalid";
                                        }
                                        if (map.player_army.getRow() > map.buildings[i].getRow() + 1 || map.player_army.getRow() < map.buildings[i].getRow() - 1)
                                        {
                                            input = "invalid";
                                        }   
                                    }
                                }
                            }
                            if (input == "1" && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.push_back(Building("Wall", "Walls can be upgraded to enhance your castle", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                            } else if (input == "2")
                            {
                                input = "build";
                            } else
                            {
                                system("clear");
                                cout << "Invalid Input\n"
                                     << "Press enter to continue\n";
                                getline(cin, input);
                                input = "4";    
                            }
                        } else
                        {
                            if (input == "2")
                            {
                                input = "invalid";
                            }
                            if (input == "1" && map.player_army.getGold() > 500 && materials_[0] >= 5 && materials_[1] >= 3)
                            {
                                map.buildings.push_back(Building("Keep", "Surround your keep with walls to be able to upgrade your castle", map.player_army.getRow(), map.player_army.getCol()));
                                map.player_army.setGold(map.player_army.getGold() - 500);
                                materials_[0] -= 5;
                                materials_[1] -= 3;
                                map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .2);
                            } else if (input == "2" && materials_[0] >= 2 && materials_[1] >= 2)
                            {
                                map.buildings.push_back(Building("Wall", "Walls can be upgraded to enhance your castle", map.player_army.getRow(), map.player_army.getCol()));
                                materials_[0] -= 2;
                                materials_[1] -= 2;
                            } else if (input == "3")
                            {
                                input = "build";
                            } else
                            {
                                system("clear");
                                cout << "Invalid Input\n"
                                    << "Press enter to continue\n";
                                getline(cin, input);
                                input = "4";    
                            }
                        }
                    }
                } else if (input == "5")
                {
                    system("clear");
                    cout << "Gold: " << map.player_army.getGold() << " | Soldiers: " << map.player_army.getArmySize() << " | Stone: " << materials_[0] << " | Wood: " << materials_[1] << "\n"
                         << "Upgrades:\n\n"
                         << "Barracks -(2 Stone 2 Wood)-> Military Acadamy\n"
                         << "Makes 2 soldiers per year with automatic collection\n"
                         << "Barracks -(2 Soldiers 1 Stone 1 Wood)-> Conquering Party\n"
                         << "Costs 1 soldiers a year and automatically collects 25 gold per year\n"
                         << "Barracks -(1 Soldier 1 Stone 2 Wood)-> Tarding Post\n"
                         << "25 gold per year for 1 random material with automatic collection\n\n"
                         << "Gold Mine -(2 Stone 2 Wood)-> Market\n"
                         << "1 gold per turn and a chance of 1 wood or 1 stone a year, with automatic collection\n"
                         << "Gold Mine -(5 Stone)-> Bank\n"
                         << "50 gold per year with automatic collection\n"
                         << "Gold Mine -(3 Wood)-> Bonfire\n"
                         << "Protects against an enemy raid, then is destroyed\n\n"
                         << "Blacksmith -(5 Soldiers 2 Stone 2 Wood)-> Sweatshop\n"
                         << ".05x multiplier per year -75 gold per year\n"
                         << "Blacksmith -(3 Stone 1 Wood)-> Quarry\n"
                         << "1 stone per year\n"
                         << "Blacksmith -(1 Stone 3 Wood)-> Lumber Camp\n"
                         << "1 wood per year\n\n"
                         << "Keep -(500g 2 stone 4 wood)-> Trading Guild\n"
                         << "Produces 200g 1 wood and 1 stone every year automatically collected\n"
                         << "Keep -(25 soldiers 3 stone 3 wood)-> Military Police\n"
                         << "Automatically produce 5 soldier a day and .05x strength per year\n"
                         << "Keep -(250 gold 10 soldiers 2 stone 2 wood)-> Wizard Acadamy\n"
                         << "+1 resource per year .1x strength per year\n\n"
                         << "Wall -(5 soldiers 1 stone 2 wood)-> Archer Tower\n"
                         << "Attacks one enemy within 2 units every turn\n"
                         << "Wall -(25 gold 2 stone 2 wood)-> Serf Homes\n"
                         << "2 soldiers per year and 25 gold per year automatically collected\n"
                         << "Wall -(2 stone 4 wood)-> Survey Tower\n"
                         << "Collects one resource within 2 units every turn\n\n"
                         << "Press enter to continue\n";
                    getline(cin, input);
                    input = "build";
                } else if (input == "6")
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
                    map.player_army.setArmySize(map.player_army.getArmySize() + 2);
                } else if (map.buildings[i].getName() == "Conquering Party" && new_year)
                {
                    map.player_army.setArmySize(map.player_army.getArmySize() - 1);
                    map.player_army.setGold(map.player_army.getGold() + 25);
                } else if (map.buildings[i].getName() == "Trading Post" && new_year)
                {
                    map.player_army.setGold(map.player_army.getGold() - 25);
                    int random = randomNum(0, 50);
                    if (random >= 0 && random <= 25)
                    {
                        materials_[0]++;
                    } else
                    {
                        materials_[1]++;
                    }
                } else if (map.buildings[i].getName() == "Market")
                {
                    map.player_army.setGold(map.player_army.getGold() + 1);
                    if (new_year)
                    {
                        resource = randomNum(0, 20);
                        if (resource == 2)
                        {
                            materials_[0]++;
                        } else if (resource == 4)
                        {
                            materials_[1]++;
                        }
                    }
                } else if (map.buildings[i].getName() == "Bank" && new_year)
                {
                    map.player_army.setGold(map.player_army.getGold() + 50);

                } else if (map.buildings[i].getName() == "Sweatshop" && new_year)
                {
                    map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .05);
                    map.player_army.setGold(map.player_army.getGold() - 75);
                } else if (map.buildings[i].getName() == "Quarry" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 1);
                } else if (map.buildings[i].getName() == "Lumber Camp" && new_year)
                {
                    map.buildings[i].setReserve(map.buildings[i].getReserve() + 1);
                } else if (map.buildings[i].getName() == "Trading Guild" && new_year)
                {
                    map.player_army.setGold(map.player_army.getGold() + 200);
                    materials_[0]++;
                    materials_[1]++;
                } else if (map.buildings[i].getName() == "Military Police")
                {
                    map.player_army.setArmySize(map.player_army.getArmySize() + 5);
                    if (new_year)
                    {
                        map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .05);
                    }
                } else if (map.buildings[i].getName() == "Wizard Acadamy" && new_year)
                {
                    map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .1);
                } else if (map.buildings[i].getName() == "Archer Tower")
                {
                    system("clear");
                    for (int j = map.buildings[i].getCol() - 3; j < map.buildings[i].getCol() + 3; j++)
                    {
                        for (int k = map.buildings[i].getRow() - 3; k < map.buildings[i].getRow() + 3; k++)
                        {
                            if (map.trueSpace(k, j) == map.ENEMY_ARMY)
                            {
                                int temp_col = map.player_army.getCol();
                                int temp_row = map.player_army.getRow();
                                map.player_army.setCol(j);
                                map.player_army.setRow(k);
                                fightEnemy();
                                map.player_army.setCol(temp_col);
                                map.player_army.setRow(temp_row);
                                map.setMap(k, j);
                                j = map.buildings[i].getCol() + 3;
                                k = map.buildings[i].getRow() + 3;
                            }
                        }   
                    }
                } else if (map.buildings[i].getName() == "Serf Homes" && new_year)
                {
                    map.player_army.setArmySize(map.player_army.getArmySize() + 2);
                    map.player_army.setGold(map.player_army.getGold() + 25);
                } else if (map.buildings[i].getName() == "Survey Tower")
                {
                    for (int j = map.buildings[i].getCol() - 3; j < map.buildings[i].getCol() + 3; j++)
                    {
                        for (int k = map.buildings[i].getRow() - 3; k < map.buildings[i].getRow() + 3; k++)
                        {
                            if (map.trueSpace(k, j) == map.RESOURCE)
                            {
                                for (int l = 0; l < map.resources.size(); l++)
                                {
                                    if (map.resources[l].isPosition(k, j))
                                    {
                                        if (map.resources[l].getName() == "Boulder")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            materials_[0]++;
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        } else if (map.resources[l].getName() == "Forest")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            materials_[1]++;
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        } else if (map.resources[l].getName() == "Chest")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            map.player_army.setGold(map.player_army.getGold() + 30);
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        } else if (map.resources[l].getName() == "Ransacked Village")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            map.player_army.setArmySize(map.player_army.getArmySize() + 2);
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        } else if (map.resources[l].getName() == "Ancient Temple")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            map.player_army.setStrengthMultiplier(map.player_army.getStrengthMultiplier() + .05);
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        } else if (map.resources[l].getName() == "Dragon's Hoard")
                                        {
                                            map.resources.erase(map.resources.begin() + l);
                                            map.player_army.setGold(map.player_army.getGold() + 75);
                                            map.setMap(k, j);
                                            j = map.buildings[i].getCol() + 3;
                                            k = map.buildings[i].getRow() + 3;
                                        }
                                    }
                                }
                            }
                        }   
                    }
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
                    bool enemy_removed = false;
                    row = randomNum(0, map.getNumRows());
                    col = randomNum(0, map.getNumCols());
                    int enemy_army_size = (1 + (year * ((1 + (year / 5)) + (2 * (year / 25)))));
                    double enemy_strength_multiplier;
                    if (year / 5 == 0)
                    {
                        enemy_strength_multiplier = 1;
                    } else
                    {
                        enemy_strength_multiplier = (1 + ((year - 4) * ((year / 5) * .025)));
                    }
                    int enemy_gold = 0;
                    int counter = 0;
                    for (int j = 1; j <= year; j++)
                    {
                        
                        if ((j - 1) % 5 == 0)
                        {
                            counter++;
                        }
                        enemy_gold = enemy_gold + counter;
                    }
                    if (map.trueSpace(row, col) == map.EXPLORED)
                    {
                        map.enemy_armies.push_back(Army("Enemy", enemy_army_size, enemy_strength_multiplier, enemy_gold, row, col));
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
                                map.enemy_armies[j].setArmySize(map.enemy_armies[j].getArmySize() + enemy_army_size);
                                map.enemy_armies[j].setStrengthMultiplier(enemy_strength_multiplier);
                                map.enemy_armies[j].setGold(map.enemy_armies[j].getGold() + enemy_gold);
                            }
                        }
                    } else if (map.trueSpace(row, col) == map.BUILDING)
                    {
                        for (int i = 0; i < map.buildings.size(); i++)
                        {
                            if (map.buildings[i].getName() == "Bonfire" && enemy_removed == false)
                            {
                                row = map.buildings[i].getRow();
                                col = map.buildings[i].getCol();
                                map.buildings.erase(map.buildings.begin() + i);
                                map.setMap(row, col);
                                i = map.buildings.size();
                                enemy_removed = true;
                            }
                        }
                        if (!enemy_removed) {
                            system("clear");
                            cout << "Enenmy forces ransacked one of your buildings. You lose " << enemy_army_size << " gold.\n"
                                << "Press enter to continue\n";
                            getline(cin, input);
                            input = "";
                            map.player_army.setGold(map.player_army.getGold() - enemy_army_size);
                            system("clear");
                        } else {
                            system("clear");
                            cout << "Enenmy forces attempted to raid your base but were scared off\n"
                                 << "Press enter to continue\n";
                            getline(cin, input);
                            input = "";
                            system("clear");
                        }
                    }
                }

                for (int i = 0; i < resource_spawn_rate_; i++)
                {
                    row = randomNum(0, map.getNumRows());
                    col = randomNum(0, map.getNumCols());
                    resource = randomNum(1, 100);
                    if (map.trueSpace(row, col) == map.EXPLORED)
                    {
                        if (resource >= 1 && resource <= 40)
                        {
                            file.open("Resources/Boulder.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 41 && resource <= 70)
                        {
                            file.open("Resources/Forest.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 71 && resource <= 80)
                        {
                            file.open("Resources/Chest.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 81 && resource <= 90)
                        {
                            file.open("Resources/Ransacked_Village.txt");
                            getline(file, input);
                            split(input, ',', temp_arr, 3);
                            file.close();
                        } else if (resource >= 91 && resource <= 95)
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
    for (int i = 0; i < map.buildings.size(); i++)
    {
        if (map.buildings[i].getName() == "Wizard Acadamy")
        {
            resource_spawn_rate_--;

        }
    }
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
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Using materials from certain resources you can upgrade buildings to a second tier form\n"
         << "Press enter to continue\n";
    getline(cin, input);
    system("clear");

    cout << "Player's Kingdom | 200 Gold | -10 Gold/year | 0 Stone | 0 Wood\n"
         << "10 Soldiers | 10 Strength | Day 5 Year 1 | Position: (7, 11)\n";
    map.changeMapData("5", 6, 7);
    map.displayMap();
    cout << "Use w/a/s/d to move | Commands: build | options\n\n";
    cout << "Entering 'r' as a command will toggle reserve view, in reserve view you can see how many soldiers\n" 
         << "or gold are in your buildings, any value over 10 shows up as F\n"
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