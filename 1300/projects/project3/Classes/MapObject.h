#ifndef MAPOBJECT_H
#define MAPOBJECT_H

using namespace std;

class MapObject
{
    private:
        string name_;
        int position_[2];

    public:
        MapObject();
        MapObject(string name, int row, int col);

        void setName(string name);
        string getName();

        void setPosition(int row, int col);
        bool isPosition(int row, int col);
        void setRow(int row);
        int getRow();
        void setCol(int col);
        int getCol();
};

#endif