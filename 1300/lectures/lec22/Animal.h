#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal 
{
    private:
        string name;
        string species;
        int age;

    public:
        Animal();
        Animal(string new_name, string new_species, int new_age);

        string getName();
        void setName(string new_name);

        string getSpecies();
        void setSpecies(string new_species);

        int getAge();
        void setName(int new_age);
};

#endif