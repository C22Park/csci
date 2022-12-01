#include <iostream>
#include <cassert>
#include <unistd.h>
#include "Map.cpp"

using namespace std;

int main()
{
    // Tests for MapObject

        MapObject map_object; // default constructor
        assert(map_object.getName() == "");
        assert(map_object.isPosition(0, 0));

        MapObject map_object2("MapObject 2", 6, 6); //paramaterized constructor
        assert(map_object2.getName() == "MapObject 2");
        assert(map_object2.isPosition(6, 6));

        // MapObject Function Tests

        map_object.setPosition(5, 5);
        assert(map_object.isPosition(5, 5));
        
        map_object.setRow(10);
        assert(map_object.getRow() == 10);

        map_object.setCol(7);
        assert(map_object.getCol() == 7);

    // Tests for Army

        Army army; // default constructor
        assert(army.getArmySize() == 0);
        assert(army.getStrengthMultiplier() == 1);
        assert(army.getArmyStrength() == 0);
        assert(army.getGold() == 0);

        Army army2("Army 2", 10, 2, 100, 0, 0); // paramaterized constructor
        assert(army2.getArmySize() == 10);
        assert(army2.getStrengthMultiplier() == 2);
        assert(army2.getArmyStrength() == 20);
        assert(army2.getGold() == 100);

        // Army Function Tests

        army.setArmySize(100);
        assert(army.getArmySize() == 100);
        assert(army.getArmyStrength() == 100);

        army.setStrengthMultiplier(1.5);
        assert(army.getStrengthMultiplier() == 1.5);
        assert(army.getArmyStrength() == 150);

        army.setGold(20);
        assert(army.getGold() == 20);

    // Tests for Building

        Building building; // default constructor
        assert(building.getBuildingDescription() == "");
        assert(building.getReserve() == 0);

        Building building2("Building 2", "The second building", 0, 0);
        assert(building2.getBuildingDescription() == "The second building");

        // Building Function Tests

        building.setBuildingDescription("New description");
        assert(building.getBuildingDescription() == "New description");

        building.setReserve(100);
        assert(building.getReserve() == 100);

    // Tests for Resource

        Resource resource; // default constructor
        assert(resource.getResourceDescription() == "");
        assert(resource.getReward() == 0);
    
        Resource resource2("Resource 2", "The second resource", 10, 0, 0); // paramaterized constructor
        assert(resource2.getResourceDescription() == "The second resource");
        assert(resource2.getReward() == 10);
    
    // Tests for Map

        Map map; // default constructor is the only constructor
        assert(map.getNumRows() == 15);
        assert(map.getNumCols() == 15);
        assert(map.isOnMap(5, 5));
        assert(!map.isOnMap(100, 100));
        assert(map.isExplored(6, 7));
        assert(!map.isExplored(0, 0));
        assert(map.trueSpace(0, 0) == map.EXPLORED);

        map.displayMap();
        cout << "This is the starting state of the map\n"
             << "Press enter to continue\n";
        string input;
        getline(cin, input);
        system("clear");

        map.enemy_armies.push_back(Army("Enemy", 0, 0, 0, 6, 6)); // spawns an enemy above the player
        map.setMap(6, 6);
        map.displayMap();
        cout << "Enemies that spawn on the map look like E\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.buildings.push_back(Building("Building", "Building Description", 6, 7)); // spawns a building above the player
        map.setMap(6, 7);
        map.displayMap();
        cout << "Buildings the player make look like B\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.resources.push_back(Resource("Resource", "Resource Description", 0, 6, 8)); // spawns a resource above the player
        map.setMap(6, 8);
        map.displayMap();
        cout << "Resources the player can collect look like R\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.displayMap();
        cout << "The player moves with w a s d\n"
             << "Press enter to continue\n";
        getline(cin, input);
        system("clear");

        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.buildings.push_back(Building("Building", "Building Description", 7, 9));
        map.move('d');
        map.displayMap();
        sleep(1);
        system("clear");

        map.move('d');
        map.displayMap();
        cout << "When the player reahces an unexplored space, '-', they explore it and any objects there will be exposed\n"
             << "Press enter to finish\n";
        getline(cin, input);
        system("clear");

    return 0;
}