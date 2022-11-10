#include "Map.h"

using namespace std;

Map::Map()
{
    for (int row = 0; row < num_rows_; row++)
    {
        for (int col = 0; col < num_cols_; col++)
        {
            map_data_[row][col] = UNEXPLORED;
        }
    }
    for (int row = 6; row <= 8; row++)
    {
        for (int col = 6; col <= 8; col++)
        {
            map_data_[row][col] = EXPLORED;
        }
    }
    map_data_[7][7] = PLAYER_ARMY;
    player_army = Army("Player", 10, 1, 100, 7, 7);
}

// getters
int Map::getBuildingCount()
{
    return buildings.size();
}
int Map::getEnemyCount()
{
    return enemy_armies.size();
}
int Map::getNumRows()
{
    return num_rows_;
}
int Map::getNumCols()
{
    return num_cols_;
}
bool Map::isOnMap(int row, int col)
{
    if (row >= 0 && row < num_rows_ && col >= 0 && col < num_cols_)
    {
        return true;
    } else
    {
        return false;
    }
}
bool Map::isExplored(int row, int col)
{
    if (map_data_[row][col] == UNEXPLORED)
    {
        return false;
    } else
    {
        return true;
    }
}
char Map::trueSpace(int row, int col)
{
    for (int i = 0; i < enemy_armies.size(); i++)
    {
        if (enemy_armies[i].isPosition(row, col))
        {
            return ENEMY_ARMY;
        }
    }    
    for (int i = 0; i < buildings.size(); i++)
    {
        if (buildings[i].isPosition(row, col))
        {
            return BUILDING;
        }
    }    
    for (int i = 0; i < resources.size(); i++)
    {
        if (resources[i].isPosition(row, col))
        {
            return RESOURCE;
        }
    }
    return EXPLORED;
}

// other
void Map::displayMap()
{
    cout << " ";
    for (int row = 0; row < num_rows_; row++)
    {
        cout << "__";
    }
    cout << "_\n";

    for (int row = 0; row < num_rows_; row++)
    {
        cout << "| ";
        for (int col = 0; col < num_cols_; col++)
        {
            cout << map_data_[row][col] << " ";
        }
        cout << "|\n";
    }

    cout << " ";
    for (int row = 0; row < num_rows_; row++)
    {
        cout << "‾‾";
    }
    cout << "‾\n";
}
void Map::setMap(int row, int col)
{
    map_data_[row][col] = trueSpace(row, col);
    if (player_army.isPosition(row, col))
    {
        map_data_[row][col] = PLAYER_ARMY;
    }
}
bool Map::move(char direction)
{
    switch (direction)
    {
        case 'w':
            if (!isOnMap(player_army.getRow() - 1, player_army.getCol()))
            {
                return false;
            } else
            {
                player_army.setPosition(player_army.getRow() - 1, player_army.getCol());
                setMap(player_army.getRow() + 1, player_army.getCol());
                setMap(player_army.getRow(), player_army.getCol());
                return true;
            }
        case 'a':
            if (!isOnMap(player_army.getRow(), player_army.getCol() - 1))
            {
                return false;
            } else
            {
                player_army.setPosition(player_army.getRow(), player_army.getCol() - 1);
                setMap(player_army.getRow(), player_army.getCol() + 1);
                setMap(player_army.getRow(), player_army.getCol());
                return true;
            }
        case 's':
            if (!isOnMap(player_army.getRow() + 1, player_army.getCol()))
            {
                return false;
            } else
            {
                player_army.setPosition(player_army.getRow() + 1, player_army.getCol());
                setMap(player_army.getRow() - 1, player_army.getCol());
                setMap(player_army.getRow(), player_army.getCol());
                return true;
            }
        case 'd':
            if (!isOnMap(player_army.getRow(), player_army.getCol() + 1))
            {
                return false;
            } else
            {
                player_army.setPosition(player_army.getRow(), player_army.getCol() + 1);
                setMap(player_army.getRow(), player_army.getCol() - 1);
                setMap(player_army.getRow(), player_army.getCol());
                return true;
            }
        default:
            return false;
    }
}