#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Object {
    protected:
        string name;
        string description;

    public: 
        Object() {
            name = "Name";
            description = "Description";
        }
        Object(string _name, string _description) {
            name = _name;
            description = _description;
        }

        string getName() {
            return name;
        }
        void setName(string _name) {
            name = _name;
        }

        string getDescription() {
            return description;
        }
        void setDescription(string _description) {
            description = _description;
        }
};

class Entity: public Object {
    private:
        int position[2];
        string type;

    public: 
        Entity(){
            position[0] = 0;
            position[1] = 0;
            type = "disabled";
        }
        Entity(string _name, string _description, int position_x, int position_y, string _type): Object(_name, _description){
            position[0] = position_x;
            position[1] = position_y;
            type = _type;
        }

        int getX() {
            return position[0];
        }
        void setX(int position_x) {
            position[0] = position_x;
        }

        int getY() {
            return position[1];
        }
        void setY(int position_y) {
            position[1] = position_y;
        }

        string getType() {
            return type;
        }
        void setType(string _type) {
            type = _type;
        }
};

class Game {
    private:
        vector<Entity> rooms;
        vector<Entity> npcs;
        Entity player;
        vector<Object> inventory;

    public:
        Game() {
            player = Entity("Player", "This is you.", 0, 0, "human");
            
        }

        void printMap() {
            bool room_found = false;
            for (int y = 5; y >= -5; y--) {
                for (int x = -5; x <= 5; x++) {
                    if (player.getX() == x && player.getY() == y) {
                        cout << "* ";
                    } else {
                        room_found = false;
                        for (int i = 0; i < rooms.size(); i++) {
                            if (rooms[i].getX() == x && rooms[i].getY() == y) {
                                cout << "# ";
                                room_found = true;
                            }
                        }
                        if (room_found == false) {
                            cout << "- ";
                        }
                    }
                }
                cout << "\n";
            }
        }
};

int main() {

    Game test;
    test.generateMap(0, 0);
    test.printMap();

    return 0;
}