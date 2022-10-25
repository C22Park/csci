#include <iostream>
#include <fstream>
#include "Items.cpp"
#include "../../split.cpp"

using namespace std;

int main()
{    
    ifstream in_file;
    in_file.open("items.txt");
    
    if (in_file.fail())
    {
        cout << "Couldn't open file\n";
        return 0;
    }

    Item inventory[50];
    string temp_arr[3];
    string temp_string;
    
    int i = 0;

    while (getline(in_file, temp_string) && i < 50)
    {
        split(temp_string, ',', temp_arr, 3);
        inventory[i].setDescription(temp_arr[0]);
        inventory[i].setUpc(temp_arr[1]);
        inventory[i].setPrice(stod(temp_arr[2]));
        i++;
    }

    cout << inventory[0].getDescription() << "\n";
    cout << inventory[1].getDescription() << "\n";
    cout << inventory[2].getDescription() << "\n";

    return 0;
}