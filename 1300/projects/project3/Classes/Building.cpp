#include "Building.h"

using namespace std;

Building::Building() // default constructor
{
    building_description_ = "";
    reserve_ = 0;
}
Building::Building(string name, string building_description, int row, int col): MapObject(name, row, col) // paramaterized constructor
{
    building_description_ = building_description;
    reserve_ = 0;
}

void Building::setBuildingDescription(string building_description) // sets resource_description_ to resource_description
{
    building_description_ = building_description;
}
string Building::getBuildingDescription() // returns resource_description_
{
    return building_description_;
}

void Building::setReserve(int reserve) // sets reserve_ to reserve
{
    reserve_ = reserve;
}
int Building::getReserve() // return reserve_
{
    return reserve_;
}