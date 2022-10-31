// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 Part 2 - Problem 1 - Buffchat.h

#ifndef BUFFCHAT_H
#define BUFFCHAT_H
#include "Post.cpp"
#include "User.cpp"

using namespace std;

class Buffchat
{
    private:
        const static int posts_size_ = 50;
        const static int users_size_ = 50;
        Post posts_[posts_size_];
        User users_[users_size_];
        int num_posts_;
        int num_users_;
        int why_do_i_need_this; // codrunner has seg faults unless i have a variable which I never use

    public:
        Buffchat(); // default constructor

        int getPostSize(); // returns posts_size_
        int getUserSize(); // returns users_size_
        int getNumPosts(); // returns num_posts_
        int getNumUsers(); // returns num_users_

        int readPosts(string file_name);
        void printPostsByYear(string year);
        int readLikes(string file_name);
        int getLikes(string post_author, string username);
        void findTagUser(string username_tag);
        bool addPost(string post_body, string post_author, string date);
        void printPopularPosts(int count, string year);
        User findLeastActiveUser();
        int countUniqueLikes(string post_author);

};

#endif