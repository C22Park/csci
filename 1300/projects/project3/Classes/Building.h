#ifndef BUILDING_H
#define BUILDING_H

using namespace std;

class Building: public MapObject
{
    private:
        string building_description_;
        int reserve_; // amount of product in building ready to be collected

    public:
        Building(); // default constructor
        Building(string name, string building_description, int row, int col); // paramaterized constructor

        void setBuildingDescription(string building_description); // sets resource_description_ to resource_description
        string getBuildingDescription(); // returns resource_description_

        void setReserve(int reserve); // sets reserve_ to reserve
        int getReserve(); // return reserve_
};

#endif