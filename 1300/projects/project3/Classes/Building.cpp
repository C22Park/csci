#include "Building.h"

using namespace std;

Building::Building()
{
    building_description_ = "";
    reserve_ = 0;
}
Building::Building(string name, string building_description, int row, int col): MapObject(name, row, col)
{
    building_description_ = building_description;
    reserve_ = 0;
}

void Building::setBuildingDescription(string building_description)
{
    building_description_ = building_description;
}
string Building::getBuildingDescription()
{
    return building_description_;
}

void Building::setReserve(int reserve)
{
    reserve_ = reserve;
}
int Building::getReserve()
{
    return reserve_;
}