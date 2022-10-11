#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string filename1;
    string filename2;

    ifstream fin1;
    ifstream fin2;

    string output;
    string output_name;
    string temp_string;
    ofstream fout;

    cout << "Enter file 1" << endl;
    cin >> filename1;
    fin1.open(filename1);

    cout << "Enter file 2" << endl;
    cin >> filename2;
    fin2.open(filename2);

    cout << "Enter the output file" << endl;
    cin >> output_name;


    fin1 >> temp_string;
    output += temp_string;
    output += " ";
    fin2 >> temp_string;
    output += temp_string;
    fout.open(output_name);
    fout << output;
    fin1.close();
    fin2.close();
    fout.close();
    
    

    return 0;
}