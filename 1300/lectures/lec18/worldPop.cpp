#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    ifstream in_file;
    in_file.open("world_population.csv");

    /* store data into three arrays, one for the name of the country, one for the population of 
       the country, and one for the area of the country */
    string country[201];
    int population[201];
    int area[201];

    string temp;

    if (in_file.is_open()) {
        getline(in_file, temp);
        while (getline(in_file, temp)) {
            for (int i = 0; i < temp.length; i++) {
                int start = 0;
                int length;
                int country_num = 0;

                if (temp[i] == ',') {
                    length = i - 1 - start;
                    if (isalpha(temp[i - 1])) {
                        country[country_num] = temp.substr(start, length);
                    } else {
                        population[country_num] = temp.substr(start, length);
                    }
                    start = i + 1;
                } else if (isspace()
            }
        }
    } else {
        cout << "Can't find the file" << endl;
    }

    return 0;
}