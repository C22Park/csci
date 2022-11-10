#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <string>
#include "MapObject.cpp"
#include "Army.cpp"
#include "Building.cpp"
#include "Resource.cpp"

using namespace std;

class Map
{
private:
    static const int num_rows_ = 15; // number of rows in map
    static const int num_cols_ = 15; // number of columns in map

    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

public:
    Army player_army; // contains all info for the player
    vector<Army> enemy_armies; // contains all info for enemy armies on the map
    vector<Building> buildings; // contains all info for buildings on the map
    vector<Resource> resources; // contains all info for resources on the map

    const char UNEXPLORED = '-'; // marker for unexplored spaces
    const char EXPLORED = ' '; // marker for explored spaces
    const char RESOURCE = 'R'; // marker for unused resource
    const char BUILDING = 'B'; // marker for building locations
    const char ENEMY_ARMY = 'E'; // marker for enemy locations
    const char PLAYER_ARMY = 'X'; // marker for party position

    Map();

    // getters
    int getBuildingCount();
    int getEnemyCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isExplored(int row, int col);
    char trueSpace(int row, int col);

    // other
    void displayMap();
    void setMap(int row, int col);
    bool move(char direction);
    
};

#endif
