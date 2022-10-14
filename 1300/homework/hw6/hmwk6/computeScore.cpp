// computeScore.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 6 - Problem 4b 

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int split(string input_string, char separator, string arr[], int arr_size)
 {
    for (int i = 0; i < arr_size; i++) // emptys out arr for repeated use when called
    {
        arr[i] = "";
    }

    if (input_string == "") // if the string is empty return 0
    {
        return 0;
    }

    int num_elements = 0;
    
    for (int i = 0; i < input_string.length(); i++)
    {
        if (num_elements >= arr_size) // if there are more elements then can fit into the array return -1
        {
            return -1;
        } else if (input_string[i] == separator)
        {
            num_elements++; // when reaching a seperator you move to the next element
        } else
        {
            arr[num_elements] += input_string[i]; // adds current character to element in arr
        }
    }
        
    num_elements++; // marks you added the final element once you reach the end of the line

    return num_elements;
}

int readRestaurantData(string file_name, string restaurants[], int ratings[][3], int arr_size) 
{
    int num_restaurants = 0;
    string temp_string;
    string temp_arr[4];
    ifstream in_file;
    in_file.open(file_name);
    if (in_file.is_open() == false)
    {
        return -1;
    }

    while (getline(in_file, temp_string) && num_restaurants < arr_size)
    {
        if (split(temp_string, '~', temp_arr, 4) == 4)
        {
            restaurants[num_restaurants] = temp_arr[0];
            ratings[num_restaurants][0] = stoi(temp_arr[1]);
            ratings[num_restaurants][1] = stoi(temp_arr[2]);
            ratings[num_restaurants][2] = stoi(temp_arr[3]);
            num_restaurants++;
        }
    }
   

    return num_restaurants;
}

void calcOverallScore(string restaurants[], int ratings[][3], int num_restaurants)
{
    double score;
    cout << setprecision(1) << fixed;
    for (int i = 0; i < num_restaurants; i++)
    {
        score = (6.3 * ratings[i][0]) + (4.3 * ratings[i][1]) + (3.4 *(5 - ratings[i][2]));
        cout << restaurants[i] << " overall score: " << score << endl;
    }
}

int main() 
{
    string filename = "restaurant_samples.txt";

// max number of restaurants to read
int num_restaurants = 3;

// make arrays to store data
string restaurants[num_restaurants];
int ratings[num_restaurants][3];

// call read data function
int num_lines = readRestaurantData(filename, restaurants, ratings, num_restaurants);

if (num_lines == -1)
{
    cout << "Could not open file." << endl;
}
else
{
    calcOverallScore(restaurants, ratings, num_lines);
}

    return 0;
}