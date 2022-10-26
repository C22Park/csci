// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 4 - User.h

#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    private:
        string username_; // name of user
        static const int size_ = 50; // max amount of likes able to be stored
        int likes_[size_]; // array with size size_ to hold values of likes for each post
        int num_posts_; // number of posts in likes_ array

    public:
        User(); // default constructor
        User(string username, int likes[], int num_posts); // paramaterized constructor

        string getUsername(); // return username_
        void setUsername(string username); // sets username_ to username

        int getLikesAt(int post_id); // returns likes_ at post_id
        bool setLikesAt(int post_id, int num_likes); // sets likes_ at post_id to num_likes

        int getNumPosts(); // returns num_posts_
        void setNumPosts(int num_posts); // sets num_posts_ to num_posts

        int getSize(); // returns size_
};

#endif