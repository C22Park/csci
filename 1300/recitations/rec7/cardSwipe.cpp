#include <iostream>
#include <fstream>

using namespace std;

int main(){

    string filename;
    cout << "Enter the filename:" << endl;
    cin >> filename;

    ifstream fin;
    string temp_string;
    int counter[5];
    int busiest_day = 0;

    fin.open(filename);

    if (fin.is_open()) {
        for (int i = 0; i < 5; i++) {
            getline(fin, temp_string);
            for (int z = 0; z < temp_string.length(); z++) {
                if (temp_string[z] == ',') {
                    counter[i] += 1;
                }
            }
            counter[i] += 1;
            if (counter[busiest_day] < counter[i]) {
                busiest_day = i;
            }
        }
        switch (busiest_day) {
            case 0:
                cout << "Monday is the busiest day of the week at the lab." << endl;
                break;
            case 1:
                cout << "Tuesday is the busiest day of the week at the lab." << endl;
                break;
            case 2:
                cout << "Wednesday is the busiest day of the week at the lab." << endl;
                break;
            case 3:
                cout << "Thursday is the busiest day of the week at the lab." << endl;
                break;
            case 4:
                cout << "Friday is the busiest day of the week at the lab." << endl;
                break;
        }

        fin.close();
    } else {
        cout << "Could not open file" << endl;
    }

    return 0;
}