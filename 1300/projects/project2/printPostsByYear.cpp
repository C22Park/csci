#include <iostream>
#include <fstream>
#include <string>
#include "Post.h"
#include "Post.cpp"

using namespace std;


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

