// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 3 - printPostsByYear.cpp

#include <iostream>
#include <fstream>
#include <string>
#include "Post.h"
#include "Post.cpp"

using namespace std;

/*
    Algorithm:
    1. Empty the temp array that split will empty results into
    2. If the string is empty return 0
    3. Add each character into the index 0 of temp array until you reach a separator then increment the index
    4. if the index becomes greater than or equal to arr_size return -1 otherwise move on
    5. Once you reach the end of the input_string add one more to index and return that #
*/

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

/*
    Algorithm:
    1. if the number of posts currently stored is greater than or equal to the post_arr_size return -2
    2. open file, file_name, if it fails to open return -1
    3. as long as you can get lines from the file & current # of posts is < post_arr_size repeat 4-9
    4. if the line is not empty use your split function to populate an array of size 4
    5. set the post body at num posts currently stored to arr[0]
    6. set the post author at num posts currently stored to arr[1]
    7. set the post likes at num posts currently stored to arr[2]
    8. set the post date at num posts currently stored to arr[3]
    9. incremenmt # posts currently stored
    10. return # posts currently stored
*/

int readPosts(string file_name, Post posts[], int num_posts_stored, int post_arr_size)
{
    if (num_posts_stored >= post_arr_size)
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
    string temp_arr[4];

    while(getline(in_file, temp_line) && num_posts_stored < post_arr_size)
    {
        if (temp_line != "")
        {
            if (split(temp_line, ',', temp_arr, 4) == 4)
            {
                posts[num_posts_stored].setPostBody(temp_arr[0]);
                posts[num_posts_stored].setPostAuthor(temp_arr[1]);
                posts[num_posts_stored].setPostLikes(stoi(temp_arr[2]));
                posts[num_posts_stored].setPostDate(temp_arr[3]);
                num_posts_stored++;
            }
        }
    }


    return num_posts_stored;
}

/*
    Algorithm:
    1. If # of posts stored it <= 0 return "No posts are stored"
    2. print "Here is a lists of posts for year " year
    3. for all posts if a post has the last two characters of its date == to year print post body
*/

void printPostsByYear(Post posts[], string year, int num_posts_stored)
{
    if (num_posts_stored <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    int temp_value = 1;
    for (int i = 0; i < num_posts_stored; i++)
    {
        if (posts[i].getPostDate().substr(6, 2) == year)
        {
            if (temp_value)
            {
                cout << "Here is a list of posts for year " << year << "\n";
                temp_value = 0;
            }
            cout << posts[i].getPostBody() << "\n";
        }
    }

    if (temp_value)
    {
        cout << "No posts stored for year " << year << "\n";
    }
}

int main()
{
    Post posts[50];
    readPosts("posts.txt", posts, 0, 50);
    printPostsByYear(posts, "18", 50);

    return 0;
}

