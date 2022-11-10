#ifndef GAME_H
#define GAME_H

using namespace std;

class Game
{
    private:
        Map map;
        bool active_cheats_[6];
        string username_;
        int enemy_spawn_rate_;
        int resource_spawn_rate_;
        int day_;
        int max_army_size_;
        int enemies_killed_;
        int materials_[2];

    public:
        Game(bool active_cheats[6], string username, int difficulty);

        void fightEnemy();

        string gameMenu();

        void playGame();
};

#endif