// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 1 - Post.cpp

#include "Post.h"

using namespace std;

Post::Post() // Default constructor sets everything blank and likes to 0
{
    body_ = "";
    post_author_ = "";
    num_likes_ = 0;
    date_ = "";
}
Post::Post(string body, string post_author, int num_likes, string date) // paramatized constructor
{
    body_ = body;
    post_author_ = post_author;
    
    if(num_likes >= 0)
    {
        num_likes_ = num_likes;
    } else
    {
        num_likes_ = 0;
    }

    date_ = date;
}

string Post::getPostBody() // returns body_
{
    return body_;
}
void Post::setPostBody(string body) // sets body_ to body
{
    body_ = body;
}

string Post::getPostAuthor() // returns post_author_
{
    return post_author_;
}
void Post::setPostAuthor(string post_author) // sets post_author_ to post_author
{
    post_author_ = post_author;
}

int Post::getPostLikes() // returns num_likes_
{
    return num_likes_;
}
void Post::setPostLikes(int num_likes) // sets num_likes_ to num_likes
{
    if(num_likes >= 0)
    {
        num_likes_ = num_likes;
    }
}

string Post::getPostDate() // returns date_
{
    return date_;
}
void Post::setPostDate(string date) // sets date_ to date
{
    date_ = date;
}