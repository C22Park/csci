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

    string map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

public:
    Army player_army; // contains all info for the player
    vector<Army> enemy_armies; // contains all info for enemy armies on the map
    vector<Building> buildings; // contains all info for buildings on the map
    vector<Resource> resources; // contains all info for resources on the map

    const string UNEXPLORED = "-"; // marker for unexplored spaces
    const string EXPLORED = " "; // marker for explored spaces
    const string RESOURCE = "R"; // marker for unused resource 
    const string BUILDING = "B"; // marker for building locations 
    const string ENEMY_ARMY = "E"; // marker for enemy locations 
    const string PLAYER_ARMY = "X"; // marker for party position 

    Map(); // default constructor

    // getters
    int getNumRows(); // returns num_rows_
    int getNumCols(); // returns num_cols_
    bool isOnMap(int row, int col); // returns true if position is valid
    bool isExplored(int row, int col); // returns true if a position is explored
    string trueSpace(int row, int col); // returns what non-player object is at that position if any

    // other
    void displayMap(); // draws map
    void setMap(int row, int col); // sets map_data_ at position to trueSpace or PLAYER_ARMY
    bool move(char direction); // moves player_army the direction corresponding to w a s or d
    void changeMapData(string map_data, int row, int col); // sets map_data_[row][col] to map_data
    
};

#endif
