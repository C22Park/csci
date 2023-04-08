/*
Charles Park
Section 5
4/7/23
Assignment 11	
*/

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Game {
    private:
        bool mines[10][10];
        string map[10][10];

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
                if (i == 0) {
                    cout << "+-0-+-1-+-2-+-3-+-4-+-5-+-6-+-7-+-8-+-9-+\n" << i;
                } else {
                    cout << "+---+---+---+---+---+---+---+---+---+---+\n" << i;
                }
                for (int j = 0; j < 10; j++) {
                    cout << " " << map[i][j] << " |";
                }
                cout << "\n";
                if (i == 9) {
                    cout << "+---+---+---+---+---+---+---+---+---+---+\n";
                }
            }
        }

        void populate(int _x, int _y) {
            srand(time(NULL));
            int num_mines = 20;
            int x, y;
            while (num_mines != 0) {
                x = rand() % 10;
                y = rand() % 10;
                if (x != _x && y != _y && mines[x][y] == false) {
                    mines[y][x] = true;
                    num_mines--;
                }
            }
        }

        bool checkCell(int x, int y) {
           int surrounding_mines = 0;
           if (mines[y][x]) {
                return false;
           } else {
                for (int i = y - 1; i < y + 2; i++) {
                    for (int j = x - 1; j < x + 2; j++) {
                        if (i >= 0 && i < 10 && j >= 0 && j < 10) {
                            if (mines[i][j]) {
                                surrounding_mines++;
                            }
                        }
                    }
                }
                if (surrounding_mines == 0) {
                    map[y][x] = " ";
                } else {
                    map[y][x] = to_string(surrounding_mines);
                }
                return true;
           }
           return true;
        }

        int run() {
            int timer = time(NULL);
            int x, y;
            bool on = true;
            bool win = false;
            int mine_check = 0;
            printMap();
            do {
                cout << "\nEnter the coordinates(x,y) of the cell you wish to check: ";
                cin >> x >> y;
                if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                    cout << "Invalid Input.\n";
                }
            } while (x < 0 || x >= 10 || y < 0 || y >= 10);
            populate(x, y);
            checkCell(x, y);
            while (on) {
                printMap();
                do {
                    cout << "\nEnter the coordinates(x,y) of the cell you wish to check: ";
                    cin >> x >> y;
                    if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                        cout << "Invalid Input.\n";
                    }
                } while (x < 0 || x >= 10 || y < 0 || y >= 10);
                on = checkCell(x, y);
                if (!on) {
                    win = false;
                }
                mine_check = 0;
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        if (map[i][j] == "?") {
                            mine_check++;
                        }
                    }
                }
                if (mine_check == 20) {
                    on = false;
                    win = true;
                }
            }
            
            timer = time(NULL) - timer;

            if (win) {
                return timer;
            } else {
                return -1;
            }
            return -1;
        }
};

int main() {
    Game test;
    int score;
    score = test.run();
    if (score == -1) {
        cout << "YOU LOSE!!!\n";
    } else {
        cout << "YOU WIN!!!!\n"
             << "SCORE: " << score << "\n";
    }
}