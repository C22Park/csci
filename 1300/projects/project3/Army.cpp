#include "Army.h"

using namespace std;


Army::Army()
{
    army_size_ = 0;
    strength_multiplier_ = 1;
    army_strength_ = army_size_ * strength_multiplier_;
    gold_ = 0;
}
Army::Army(string name, int army_size, double strength_multiplier, int gold, int row, int col): MapObject(name, row, col)
{
    army_size_ = army_size;
    strength_multiplier_ = strength_multiplier;
    army_strength_ = army_size_ * strength_multiplier_;
    gold_ = gold;
}

void Army::setArmySize(int army_size)
{
    army_size_ = army_size;
    army_strength_ = army_size_ * strength_multiplier_;
}
int Army::getArmySize()
{
    return army_size_;
}

void Army::setStrengthMultiplier(double strength_multiplier)
{
    strength_multiplier_ = strength_multiplier;
    army_strength_ = army_size_ * strength_multiplier_;
}
double Army::getStrengthMultiplier()
{
    return strength_multiplier_;
}

int Army::getArmyStrength()
{
    return army_strength_;
}

void Army::setGold(int gold)
{
    gold_ = gold;
}
int Army::getGold()
{
    return gold_;
}