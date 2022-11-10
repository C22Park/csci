#include "MapObject.h"

using namespace std;

MapObject::MapObject() // default constructor
{
    name_ = "";
    position_[0] = 0;
    position_[1] = 0;
}
MapObject::MapObject(string name, int row, int col) // paramaterized constructor
{
    name_ = name;
    position_[0] = row;
    position_[1] = col;
}

void MapObject::setName(string name) // sets name_
{
    name_ = name;
}
string MapObject::getName() // returns name_
{
    return name_;
}

void MapObject::setPosition(int row, int col) // sets position_
{
    position_[0] = row;
    position_[1] = col;
}
bool MapObject::isPosition(int row, int col) // returns true if the row and column match the MapObjects
{
    if (position_[0] == row && position_[1] == col)
    {
        return true;
    } else 
    {
        return false;
    }
}
void MapObject::setRow(int row) // sets position_[0]
{
    position_[0] = row;
}
int MapObject::getRow() // returns position_[0]
{
    return position_[0];
}
void MapObject::setCol(int col) // sets position_[1]
{
    position_[1] = col;
}
int MapObject::getCol() // returns position_[1]
{
    return position_[1];
}