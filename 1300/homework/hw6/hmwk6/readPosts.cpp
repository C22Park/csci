// readPosts.cpp
// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Homework 6 - Problem 3 

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

int readPosts(string file_name) 
{
    int num_posts = 0;
    string temp_input;
    string temp_arr[3];

    ifstream in_file;
    in_file.open(file_name);
    if (in_file.is_open() == false) 
    {
        return -1;
    }
    
    while (getline(in_file, temp_input)) 
    {
        if (split(temp_input, ',', temp_arr, 3) == 3)
        {
            num_posts++;
        }
    }

    return num_posts;
}

int main() 
{
    string filename = "posts.txt";
    int num_posts = readPosts(filename);
    if (num_posts == -1)
    {
        cout << "Could not open file." << endl;
    }
    else
    {
        cout << "Number of posts: " << num_posts << "." << endl;
    }

    return 0;
}