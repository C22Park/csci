#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    string dump;
    double temp;
    vector<double> high;
    vector<double> low;
    vector<double> depth;

    ifstream infile;
    infile.open("weather.txt");
    getline(infile, dump);

    bool run = true;

    while (run) {
        infile >> dump >> dump >> dump;
        infile >> temp;
        high.push_back(temp);
        infile >> temp;
        low.push_back(temp);
        infile >> dump >> dump;
        infile >> temp;
        depth.push_back(temp);
        if (infile.eof()) {
            run = false;
        }
    }

    double max = high.front();
    double high_avg = high.front();
    double min = low.front();
    double low_avg = low.front();

    for (int i = 1; i < high.size(); i++) {
        if (high.at(i) > max) {
            max = high.at(i);
        }
        if (low.at(i) < min) {
            min = low.at(i);
        }
        high_avg += high.at(i);
        low_avg += low.at(i);
    }
    high_avg /= high.size();
    low_avg /= low.size();
    
    vector<double> depth_change;
    for (int i = 0; i < depth.size() - 1; i++) {
        depth_change.push_back(depth.at(i + 1) - depth.at(i));
    }

    cout << "Highest Temp: " << max << "\n"
         << "Lowest Temp: " << min << "\n"
         << "Average Daily High: " << high_avg << "\n"
         << "Average Daily Low: " << low_avg << "\n";

    for (int i = 2; i <= 31; i++) {
        cout << i << " January 2016 Snow Depth Change: " << depth_change.at(i - 2) << "\n";
    }
}