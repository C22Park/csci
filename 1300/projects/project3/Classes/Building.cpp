#include "Building.h"

using namespace std;

Building::Building()
{
    building_description_ = "";
}
Building::Building(string name, string building_description, int row, int col): MapObject(name, row, col)
{
    building_description_ = building_description;
}

void Building::setBuildingDescription(string building_description)
{
    building_description_ = building_description;
}
string Building::getBuildingDescription()
{
    return building_description_;
}