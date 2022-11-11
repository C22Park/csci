#include "Army.h"

using namespace std;


Army::Army() // default construcor
{
    army_size_ = 0;
    strength_multiplier_ = 1;
    army_strength_ = army_size_ * strength_multiplier_;
    gold_ = 0;
}
Army::Army(string name, int army_size, double strength_multiplier, int gold, int row, int col): MapObject(name, row, col) // paramaterized construcor
{
    army_size_ = army_size;
    strength_multiplier_ = strength_multiplier;
    army_strength_ = army_size_ * strength_multiplier_;
    gold_ = gold;
}

void Army::setArmySize(int army_size) // sets army_size_ to army_size
{
    army_size_ = army_size;
    army_strength_ = army_size_ * strength_multiplier_;
}
int Army::getArmySize() // returns army_size_
{
    return army_size_;
}

void Army::setStrengthMultiplier(double strength_multiplier) // sets strength_multiplier_ to stength_multiplier
{
    strength_multiplier_ = strength_multiplier;
    army_strength_ = army_size_ * strength_multiplier_;
}
double Army::getStrengthMultiplier() // returns strength_multiplier_
{
    return strength_multiplier_;
}

int Army::getArmyStrength() // returns army_strength_
{
    return army_strength_;
}

void Army::setGold(int gold) // sets gold_ to gold
{
    gold_ = gold;
}
int Army::getGold() // returns gold_
{
    return gold_;
}