// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 6 - getLikesDriver.cpp

#include "Post.cpp"
#include "User.cpp"

using namespace std;

/*
    Algorithm:
    1. if # of current posts or users stored is <= 0 return -2
    2. if you cant find desired username or post_author in their respective arrays return -3
    3. return the amount of likes username has at the post_id corresponding to the first appearence of post_author
*/

int getLikes (string post_author, Post posts[], int num_posts_stored, string username, User users[], int num_users_stored)
{
    if (num_posts_stored <= 0 || num_users_stored <= 0)
    {
        return -2;
    }
    
    bool valid_post = false;
    for (int i = 0; i < num_users_stored; i++)
    {
        if (users[i].getUsername() == username)
        {
            valid_post = true;
        }
    }
    if (!valid_post)
    {
        return -3;
    }
    valid_post = false;
    for (int i = 0; i < num_posts_stored; i++)
    {
        if (posts[i].getPostAuthor() == post_author)
        {
            valid_post = true;
        }
    }
    if (!valid_post)
    {
        return -3;
    }

    for (int i = 0; i < num_posts_stored; i++)
    {
        if (posts[i].getPostAuthor() == post_author)
        {
            for (int j = 0; j < num_users_stored; j++)
            {
                if (users[j].getUsername() == username)
                {
                    return users[j].getLikesAt(i);
                }
            }
        }
    }
}