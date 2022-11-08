#ifndef BUILDING_H
#define BUILDING_H

using namespace std;

class Building: public MapObject
{
    private:
        string building_description_;
        int reserve_;

    public:
        Building();
        Building(string name, string building_description, int row, int col);

        void setBuildingDescription(string building_description);
        string getBuildingDescription();

        void setReserve(int reserve);
        int getReserve();
};

#endif