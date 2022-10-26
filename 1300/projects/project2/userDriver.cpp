// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 4 - userDriver.cpp

#include "User.cpp"
#include <iostream>

using namespace std;

int main ()
{
    // test 1 for creating a default user
    User test_user;
    cout << test_user.getUsername() << endl; // should be blank
    cout << test_user.getNumPosts() << endl; // should be 0
    cout << test_user.getLikesAt(0) << endl; // should be -1
    cout << test_user.getSize() << endl; // should be 50
    
    // test 2 for editing a user
    test_user.setUsername("Charlie");
    test_user.setNumPosts(10);
    test_user.setLikesAt(0, 10);

    cout << test_user.getUsername() << endl; // should be Charlie
    cout << test_user.getNumPosts() << endl; // should be 10
    cout << test_user.getLikesAt(0) << endl; // should be 10
    cout << test_user.getSize() << endl; // should be 50
    
    // test 3 for creating a paramatized user
    int likes[10] = {-1, 2, 7, 3, 7, 10, -1, 3, 2, 0};
    User paramaterized_user("Bill Murray",likes,10);

    cout << paramaterized_user.getUsername() << endl; // should be Bill Murray
    cout << paramaterized_user.getNumPosts() << endl; // should be 10
    cout << paramaterized_user.getLikesAt(3) << endl; // should be 3
    cout << paramaterized_user.getSize() << endl; // should be 50

    // test 4 for trying to edit a user to have invalid num_posts
    paramaterized_user.setNumPosts(51);
    cout << paramaterized_user.getNumPosts() << endl; // should be 10
    return 0;
}