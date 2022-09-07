#include <iostream>

using namespace std;

int main(){
    
    double coldReservoir;
    double hotReservoir;
    double carnotEfficiency;

    cout << "Enter cold resevoir temperature:" << endl;
    cin >> coldReservoir;
    coldReservoir = (coldReservoir - 32)*(5.0/9.0) + 273.15;
    cout << "Enter hot resevoir temperature:" << endl;
    cin >> hotReservoir;
    hotReservoir = (hotReservoir - 32)*(5.0/9.0) + 273.15;
    carnotEfficiency = 1 - coldReservoir/hotReservoir;
    cout << "Carnot efficiency: " << carnotEfficiency << endl;

    return 0;
}