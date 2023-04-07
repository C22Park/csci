#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Game {
    private:
        bool mines[10][10];
        char map[10][10];

    public:
        Game() {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    mines[i][j] = false;
                    map[i][j] = "?"; 
                }
            }
        }

        void printMap() {
            cout.flush();
            for (int i = 0; i < 10; i++) {
                cout << "+-+-+-+-+-+-+-+-+-+-+\n|";
                for (int j = 0; j < 10; j++) {
                    cout << map[i][j] << "|";
                }
                cout << "+-+-+-+-+-+-+-+-+-+-+\n";
            }
        }
};

int main() {
    Game test;
    test.printMap();
}