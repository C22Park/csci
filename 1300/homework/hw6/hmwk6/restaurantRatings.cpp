#include <iostream>
#include <fstream>
#include <string>

using namespace std;

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
        if (num_elements >= arr_size) 
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

int main() 
{
    string filename = "restaurant_samples.txt";

    // max number of restaurants to read
    int num_restaurants = 3;

    // make arrays to store data
    string restaurants[num_restaurants];
    int ratings[num_restaurants][3];

    // call read data function
    int num_posts = readRestaurantData(filename, restaurants, ratings, num_restaurants);

    // output results, if any
    if (num_posts == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "Number of lines: " << num_posts << "." << endl;
    }

    return 0;
}