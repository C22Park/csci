// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 1 - Post.h

#ifndef POST_H
#define POST_H
#include <string>

using namespace std;

class Post
{
    private:
        string body_; // text content of post
        string post_author_; // username of post author
        int num_likes_; // number of likes the post has
        string date_; // day the post was made

    public:
        Post(); // default constructor
        Post(string body, string post_author, int num_likes, string date); // paramatized constructor

        string getPostBody(); // returns body_
        void setPostBody(string body); // sets body_ to body

        string getPostAuthor(); // returns post_author_
        void setPostAuthor(string post_author); // sets post_author_ to post_author

        int getPostLikes(); // returns num_likes_
        void setPostLikes(int num_likes); // sets num_likes_ to num_likes

        string getPostDate(); // returns date_
        void setPostDate(string date); // sets date_ to date
};

#endif