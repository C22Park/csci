#include <iostream>
#include <cassert>

using namespace std;

double fertilize(double stock, double amount) {
    if (stock >= amount && amount >= 0) {
    return stock - amount;
    
    }
    else {
        cout << "Invalid amount." << endl;
        return -1;
    }
}

double restock(double stock, double amount) {
    if (amount >= 0) {
        return stock + amount;
    }
    else {
        cout << "Invalid amount." << endl;
        return -1;
    }
}

int farmMenu() {
    int input;
    do {
    cout << "Menu:\n1) Fertilize\n2) Stock Up\n3) Check Stores\n4) Exit" << endl;
    cin >> input;
    if (input < 1 || input > 4) {
        cout << "Invalid input. Try again." << endl;
    }
    } while (input < 1 || input > 4);
    return input;
}

int main() {
    double stores = 50.0;
    double input;
    int menu;
    do {
        menu = farmMenu();
        switch(menu) {
        case 1:
            do {
                cout << "How much fertilizer?" << endl;
                cin >> input;
            } while (fertilize(stores, input) == -1);
            stores = fertilize(stores, input);
            cout << "Fertilizing successful." << endl;
            break;
        case 2:
            do {
                cout << "How much fertilizer?" << endl;
                cin >> input;
            } while (restock(stores, input) == -1);
            stores = restock(stores, input);
            cout << "Restocking successful." << endl;
            break;
        case 3:
            cout << "Storage level is " << stores << " lbs." << endl;
            break;
        case 4:
        cout << "Exiting program." << endl;
        break;
    }
    cout << "\n";
    } while (menu != 4);

    return 0;
}