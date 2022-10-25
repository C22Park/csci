#include <fstream>
#include <iostream>
#include "User.h"
#include "User.cpp"

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
            for (int i = 1; i <= max_posts; i++)
            {
                users[num_users_stored].setLikesAt(i - 1, stoi(temp_arr[i]));
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

    readLikes("users.txt", users, num_users_stored, users_arr_size, max_posts);
    for (int i = 0; i < 50; i++)
    {
        cout << users[i].getUsername() << "\n";
    }

    return 0;
}