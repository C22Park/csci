#ifndef MAPOBJECT_H
#define MAPOBJECT_H

using namespace std;

class MapObject
{
    private:
        string name_; 
        int position_[2]; // [0] = x | [1] = y

    public:
        MapObject(); // default constructor
        MapObject(string name, int row, int col); // paramaterized constructor

        void setName(string name); // sets name_
        string getName(); // returns name?

        void setPosition(int row, int col); // sets position_
        bool isPosition(int row, int col); // returns true if row and column match the MapObjects
        void setRow(int row); // sets position_[0]
        int getRow(); // returns position_[0]
        void setCol(int col); // sets position_[1]
        int getCol(); // returns position_[1]
};

#endif