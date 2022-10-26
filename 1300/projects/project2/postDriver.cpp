// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 1 - postDriver.cpp

#include <iostream>
#include "Post.h"
#include "Post.cpp"

using namespace std;

int main()
{
    // test 1 for creating a default post
    Post default_post; // default construction
    cout << "Post author " << default_post.getPostAuthor() << endl;
    cout << "Post body " << default_post.getPostBody() << endl;
    cout << "Post date " << default_post.getPostDate() << endl;
    cout << "Post likes " << default_post.getPostLikes() << endl;

    // test 2 for changing a posts contents
    default_post.setPostAuthor("Charlie");  // setting new values
    default_post.setPostBody("This is my post");
    default_post.setPostDate("01/01/06");
    default_post.setPostLikes(1000);

    cout << "Post author " << default_post.getPostAuthor() << endl;
    cout << "Post body " << default_post.getPostBody() << endl;
    cout << "Post date " << default_post.getPostDate() << endl;
    cout << "Post likes " << default_post.getPostLikes() << endl;

    // test 3 for creating a post with the paramaterized constructor
    Post my_post("welcome to my social media","Boris Johnson", 9, "08/10/20"); // parameterized constructor
    cout << "Post author " << my_post.getPostAuthor() << endl;
    cout << "Post body " << my_post.getPostBody() << endl;
    cout << "Post date " << my_post.getPostDate() << endl;
    cout << "Post likes " << my_post.getPostLikes() << endl;

    //test 4 for attempting to initialize with the paramater of likes < 0
    Post negative_likes("Post Body","Username",-10,"06/02/04");
    cout << negative_likes.getPostLikes() << endl; // should return 0

    //test 5 for attempting to change likes to a negative number
    my_post.setPostLikes(-50);
    cout << my_post.getPostLikes() << endl; // should return 9

    return 0;
}