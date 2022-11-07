#include "MapObject.h"

using namespace std;

MapObject::MapObject()
{
    name_ = "";
    position_[0] = 0;
    position_[1] = 0;
}
MapObject::MapObject(string name, int row, int col)
{
    name_ = name;
    position_[0] = row;
    position_[1] = col;
}

void MapObject::setName(string name)
{
    name_ = name;
}
string MapObject::getName()
{
    return name_;
}

void MapObject::setPosition(int row, int col)
{
    position_[0] = row;
    position_[1] = col;
}
bool MapObject::isPosition(int row, int col)
{
    if (position_[0] == row && position_[1] == col)
    {
        return true;
    } else 
    {
        return false;
    }
}
void MapObject::setRow(int row)
{
    position_[0] = row;
}
int MapObject::getRow()
{
    return position_[0];
}
void MapObject::setCol(int col)
{
    position_[1] = col;
}
int MapObject::getCol()
{
    return position_[1];
}