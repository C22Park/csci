// mountainStats.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 6 - Problem 2 

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Mountain
{
    string name;
    int height;
};

int split(string input_string, char separator, string arr[], int arr_size)
 {
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = "";
    }

    if (input_string == "")
    {
        return 0;
    }

    int num_elements = 0;
    
    for (int i = 0; i < input_string.length(); i++)
    {
        if (input_string[i] == separator && num_elements >= arr_size) 
        {
            return -1;
        } else if (input_string[i] == separator)
        {
            num_elements++;
        } else
        {
            arr[num_elements] += input_string[i];
        }
    }
        
    num_elements++;

    return num_elements;
}

void printMountainStats(string file_name)
{
    ifstream in_file;
    in_file.open(file_name);

    if (in_file.fail())
    {
        cout << "Could not open file." << endl;
        return;
    }

    string temp_mountain[2] = {"",""};
    string temp_line;
    int lines_read = 1;
    Mountain max_mountain;
    Mountain min_mountain;
    getline(in_file, temp_line);
    split(temp_line, '|', temp_mountain, 2);
    max_mountain.name = temp_mountain[0];
    max_mountain.height = stoi(temp_mountain[1]);
    min_mountain.name = temp_mountain[0];
    min_mountain.height = stoi(temp_mountain[1]);
    cout << max_mountain.name << endl;
    while (getline(in_file, temp_line))
    {
        if (temp_line != "") 
        {
            lines_read++;
        
        split(temp_line, '|', temp_mountain, 2);
        if (stoi(temp_mountain[1]) > max_mountain.height) 
        {
            max_mountain.name = temp_mountain[0];
            max_mountain.height = stoi(temp_mountain[1]);
        } 
        if (stoi(temp_mountain[1]) < min_mountain.height) 
        {
            min_mountain.name = temp_mountain[0];
            min_mountain.height = stoi(temp_mountain[1]);
        }
        }
    }

    cout << "Number of lines read: " << lines_read << "." << endl;
    cout << "Tallest Mountain: " << max_mountain.name << " at " << max_mountain.height << " feet." << endl;
    cout << "Shortest Mountain: " << min_mountain.name << " at " << min_mountain.height << " feet." << endl;
}

int main()
{
    string file_name = "mountain_data.txt";
    printMountainStats(file_name);

    return 0;
}