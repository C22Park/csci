#ifndef ARMY_H
#define ARMY_H

using namespace std;

class Army: public MapObject
{
    private:
        int army_size_; // # of soldiers
        double strength_multiplier_; // used to find army_strength_
        int army_strength_; // army_size_ * strength_multiplier_
        int gold_; // User gold in player_army and the reward for killing enemy_armies

    public:
        Army(); // default constructor
        Army(string name, int army_size, double strength_multiplier, int gold, int row, int col); // paramaterized constructor

        void setArmySize(int army_size); // sets army_size_ to army_size
        int getArmySize(); // returns army_size_

        void setStrengthMultiplier(double strength_multiplier); // sets stength_miultiplier_ to stength_miultiplier
        double getStrengthMultiplier(); // returns stength_miultiplier_

        int getArmyStrength(); // returns army_strength_

        void setGold(int gold); // sets gold_ to gold
        int getGold(); // returns gold_
};

#endif