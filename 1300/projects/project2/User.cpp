// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 4 - User.cpp

#include "User.h"

using namespace std;

User::User() // default constructor
{
    username_ = ""; // sets username_ as blank
    num_posts_ = 0; // sets num_posts_ to 0 
    for (int i = 0; i < size_; i++) // fills all likes as not seen
    {
        likes_[i] = -1;
    }
}
User::User(string username, int likes[], int num_posts) // paramaterized constructor
{
    username_ = username; 
    num_posts_ = num_posts;
    for (int i = 0; i < num_posts_; i++) // for num_posts set likes_ to equivelent in likes
    {
        likes_[i] = likes[i];
    }
    for (int i = num_posts_; i < size_; i++) // for the rest of the array not included in num_posts set the likes_ to -1 or unseen
    {
        likes_[i] = -1;
    }
}

string User::getUsername() // return username_
{
    return username_;
}
void User::setUsername(string username) // sets username_ to username
{
    username_ = username;
}

int User::getLikesAt(int post_id) // returns likes_ at post_id
{
    if (post_id < 0 || post_id >= size_) // if post_id is invalid return -2
    {
        return -2;
    } else
    {
        return likes_[post_id];
    }
}
bool User::setLikesAt(int post_id, int num_likes) // sets likes_ at post_id to num_likes
{
    if (post_id >= 0 && post_id < num_posts_  && num_likes >= -1 && num_likes <= 10)
    {
        likes_[post_id] = num_likes;
        return true;
    } else{
        return false; // if post_id is invalid or num_likes is invalid return false
    }
}

int User::getNumPosts() // returns num_posts_
{
    return num_posts_;
}
void User::setNumPosts(int num_posts) // sets num_posts_ to num_posts
{
    if (num_posts >= 0 && num_posts <= size_)
    {
        num_posts_ = num_posts; // if num_posts is valid set num_posts_ to num_posts
    }
}

int User::getSize() // returns size_
{
    return size_;
}