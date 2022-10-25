#include <iostream>
#include "Animal.h"
#include "Enclosure.h"

using namespace std;

Enclosure::Enclosure()
{
   length = 10;
   width = 10;
   square_feet = length * width; 
}
Enclosure::Enclosure(double new_length, double new_width, Animal new_occupant)
{
    if (new_length >= 0)
    {
        length = new_length;
    } else
    {
        length = 10;
    }

    if (new_width >= 0)
    {
        width = new_width;
    } else
    {
        width = 10;
    }

    square_feet = length * width;

    occupant = new_occupant;
}

double Enclosure::getLength()
{
    return length;
}
void Enclosure::setLength(double new_length)
{
    if (new_length >= 0)
    {
        length = new_length;
        square_feet = length * width;
    } else
    {
        cout << "Could not update length" << endl;
    }
}

double Enclosure::getWidth()
{
    return width;
}
void Enclosure::setWidth(double new_width)
{
    if (new_width >= 0)
    {
        width = new_width;
        square_feet = length * width;
    } else
    {
        cout << "Could not update width" << endl;
    }
}

double Enclosure::getSquareFeet()
{
    return square_feet;
}
    
Animal Enclosure::getOccupant()
{
    return occupant;
}
void Enclosure::setOccupant(Animal new_occupant)
{
    occupant = new_occupant;
}

void Enclosure::describeEnclosure()
{
    cout << "The enclosure is: " << square_feet << " square feet.\n"
         << "This enclosure houses a " << occupant.getSpecies() << ", named " << occupant.getName() << endl;
}