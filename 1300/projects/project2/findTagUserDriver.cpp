// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 7 - findTagUserDriver.cpp

#include "User.cpp"
#include <iostream>

using namespace std;

/*
    Algorithm:
    1. if # of users currently stored is <= 0 return "No users are stored in the datatbase"
    2. compare each username in users to see if username_tag is a part of that username and sav the username to a temp array
    3. print out "Here are all usernames taht contain " username_tag
    4. then print out all the usernames which contain that tag
*/

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    if (num_users_stored <= 0)
    {
        cout << "No users are stored in the database\n";
        return;
    }

    string matching_users[num_users_stored];
    int num_users_found = 0;
    for (int i = 0; i < num_users_stored; i++)
    {
        for (int j = 0; j <= users[i].getUsername().length() - username_tag.length(); j++)
        {
            if (username_tag == users[i].getUsername().substr(j, username_tag.length()))
            {
                matching_users[num_users_found] = users[i].getUsername();
                num_users_found++;
            }
        }
    }

    if (num_users_found == 0)
    {
        cout << "No matching user found\n";
        return;
    } else
    {
        cout << "Here are all the usernames that contain " << username_tag << "\n";
        for (int i = 0; i < num_users_found; i++)
        {
            cout << matching_users[i] << "\n";
        }
        return;
    }
}

int main ()
{
    // creating 5 users
    User user_array[5];
    int likes1[3] = {1, 0, -1};
    int likes2[3] = {4, 5, 0};
    user_array[0] = User("foliwn22", likes1, 3);
    user_array[1] = User("joh23k", likes2, 3);
    user_array[2] = User("harry02", likes2, 3);
    user_array[3] = User("luwkml1", likes2, 3);
    user_array[4] = User("fwollow3", likes1, 3);
    findTagUser("ol", user_array, 5);

    return 0;
}