#ifndef ARMY_H
#define ARMY_H

using namespace std;

class Army: public MapObject
{
    private:
        int army_size_;
        double strength_multiplier_;
        int army_strength_;
        int gold_;

    public:
        Army();
        Army(string name, int army_size, double strength_multiplier, int gold, int row, int col);

        void setArmySize(int army_size);
        int getArmySize();

        void setStrengthMultiplier(double strength_multiplier);
        double getStrengthMultiplier();

        int getArmyStrength();

        void setGold(int gold);
        int getGold();
};

#endif