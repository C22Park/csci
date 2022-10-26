// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 5 - readLikesDriver.cpp

#include <fstream>
#include <iostream>
#include "User.h"
#include "User.cpp"

using namespace std;

/*
    Algorithm:
    1. Empty the temp array that split will empty results into
    2. If the string is empty return 0
    3. Add each character into the index 0 of temp array until you reach a separator then increment the index
    4. if the index becomes greater than or equal to arr_size return -1 otherwise move on
    5. Once you reach the end of the input_string add one more to index and return that #
*/

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

/*
    Algorithm:
    1. if the # of users currently stored is equal to the arr size return -2
    2. open file, file_name, if it fails to open return -1
    3. while you can get lines from the file and # of users currently stored is less than the arr size repeat 4-7
    4. split the current line into max_posts + 1 elements
    5. set username to index 0 of your split array
    6. set num_posts to max_posts
    7. if the element isnt empty set likes at index 0 to split arr[1] and increment both numbers until you fill likes_
    8. return the amount of elements filled in likes_
*/

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{
    if (num_users_stored == users_arr_size)
    {
        return -2;
    }

    ifstream in_file;
    in_file.open(file_name);

    if (in_file.fail())
    {   
        return -1;
    }

    string temp_line;
    string temp_arr[max_posts + 1];

    while(getline(in_file, temp_line) && num_users_stored < users_arr_size)
    {
        if (temp_line != "")
        {
            split(temp_line, ',', temp_arr, max_posts + 1);
            users[num_users_stored].setUsername(temp_arr[0]);
            users[num_users_stored].setNumPosts(max_posts);
            for (int i = 0; i < max_posts; i++)
            {
                if (temp_arr[i + 1] != "")
                {
                users[num_users_stored].setLikesAt(i, stoi(temp_arr[i + 1]));
                }
            }
            num_users_stored++;
        }
    }

    return num_users_stored;
}

int main()
{
    User users[50];
    int num_users_stored = 0;
    int users_arr_size = 50;
    int max_posts = 50;

    readLikes("users_10.txt", users, num_users_stored, users_arr_size, max_posts);
    for (int i = 0; i < 50; i++)
    {
        cout << users[i].getUsername() << "\n";
    }

    return 0;
}