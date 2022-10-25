#ifndef ENCLOSURE_H
#define ENCLOSURE_H

#include <iostream>
#include "Animal.h"

using namespace std;

class Enclosure
{
    private:
        double length;
        double width;
        double square_feet;
        Animal occupant;

    public:
        Enclosure();
        Enclosure(double new_length, double new_width, Animal new_occupant);

        double getLength();
        void setLength(double new_length);

        double getWidth();
        void setWidth(double new_width);

        double getSquareFeet();
        
        Animal getOccupant();
        void setOccupant(Animal new_occupant);

        void describeEnclosure();
};

#endif