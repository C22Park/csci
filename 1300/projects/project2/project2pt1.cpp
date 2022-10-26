// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 - Problem 8 - project2pt1.cpp

#include <iostream>
#include <fstream>
#include "Post.cpp"
#include "User.cpp"

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

/*
    Algorithm:
    1. if the # of users currently stored is equal to the arr size return -2
    2. open file, file_name, if it fails to open return -1
    3. while you can get lines from the file and # of users currently stored is less than the arr size repeat 4-7
    4. split the current line into max_posts + 1 elements
    5. set username to index 0 of your split array
    6. set num_posts to max_posts
    7. if the element isnt empty set likes at index 0 to split arr[1] and increment both numbers until you fill likes_
    8. return the amount of elements filled in likes_
*/

int readLikes(string file_name, User users[], int num_users_stored, int users_arr_size, int max_posts)
{
    if (num_users_stored == users_arr_size)
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
    string temp_arr[max_posts + 1];

    while(getline(in_file, temp_line) && num_users_stored < users_arr_size)
    {
        if (temp_line != "")
        {
            split(temp_line, ',', temp_arr, max_posts + 1);
            users[num_users_stored].setUsername(temp_arr[0]);
            users[num_users_stored].setNumPosts(max_posts);
            for (int i = 0; i < max_posts; i++)
            {
                if (temp_arr[i + 1] != "")
                {
                users[num_users_stored].setLikesAt(i, stoi(temp_arr[i + 1]));
                }
            }
            num_users_stored++;
        }
    }

    return num_users_stored;
}

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

/*
    Algorithm:
    1. if # of users currently stored is <= 0 return "No users are stored in the datatbase"
    2. compare each username in users to see if username_tag is a part of that username and sav the username to a temp array
    3. print out "Here are all usernames taht contain " username_tag
    4. then print out all the usernames which contain that tag
*/

void findTagUser(string username_tag, User users[], int num_users_stored)
{
    if (num_users_stored <= 0)
    {
        cout << "No users are stored in the database\n";
        return;
    }

    string matching_users[num_users_stored];
    int num_users_found = 0;
    for (int i = 0; i < num_users_stored; i++)
    {
        for (int j = 0; j <= users[i].getUsername().length() - username_tag.length(); j++)
        {
            if (username_tag == users[i].getUsername().substr(j, username_tag.length()))
            {
                matching_users[num_users_found] = users[i].getUsername();
                num_users_found++;
            }
        }
    }

    if (num_users_found == 0)
    {
        cout << "No matching user found\n";
        return;
    } else
    {
        cout << "Here are all the usernames that contain " << username_tag << "\n";
        for (int i = 0; i < num_users_found; i++)
        {
            cout << matching_users[i] << "\n";
        }
        return;
    }
}

/*
    Algorithm:
    1. Run a loop as long as the user doesnt pick quit in the menu
    2. Print out your menu and let the user pick 1-6 if they pick outside that range print "Invalid input"
    3. If they pick 1 use your read post function
    4. if they pick 2 use print post by year function
    5. if they pick 3 use read likes function
    6. if they pick 4 use get likes function
    7. if they pick 5 use find user tage function
    8. If they pick 6 say goodbye and close menu
    
*/

int main()
{
    int menu = 0;
    string input, input2;
    int const arr_size = 50;
    Post posts[arr_size];
    User users[arr_size];
    int num_posts_stored = 0;
    int num_users_stored = 0;
    int temp_value = 0;
    while (menu != 6)
    {
        cout << "======Main Menu======\n"
             << "1. Read Posts\n"
             << "2. Print Posts By Year\n"
             << "3. Read Likes\n"
             << "4. Get Likes\n"
             << "5. Find users with matching tag\n"
             << "6. Quit\n";
        cin >> menu;

        switch (menu)
        {
            case 1:
                cout << "Enter a post file name:\n";
                cin >> input;
                temp_value = readPosts(input, posts, num_posts_stored, arr_size);
                switch (temp_value)
                {
                    case -1:
                        cout << "File failed to open. No posts saved to the database.\n";
                        break;
                    case -2:
                        cout << "Database is already full. No posts were added.\n";
                        break;
                    case arr_size:
                        num_posts_stored = temp_value;
                        cout << "Database is full. Some posts may have not been added.\n";
                        break;
                    default:
                        num_posts_stored = temp_value;
                        cout << "Total posts in the database: " << num_posts_stored << "\n";
                        break;
                }
                break;
            case 2:
                cout << "Enter the year(YY):\n";
                cin >> input;
                printPostsByYear(posts, input, num_posts_stored);
                break;
            case 3:
                cout << "Enter a user file name:\n";
                cin >> input;
                temp_value = readLikes(input, users, num_users_stored, arr_size, arr_size);
                switch (temp_value)
                {
                    case -1:
                        cout << "File failed to open. No userss saved to the database.\n";
                        break;
                    case -2:
                        cout << "Database is already full. No users were added.\n";
                        break;
                    case arr_size:
                        num_users_stored = temp_value;
                        cout << "Database is full. Some users may have not been added.\n";
                        break;
                    default:
                        num_users_stored = temp_value;
                        cout << "Total users in the database: " << num_users_stored << "\n";
                        break;
               }
                break;
            case 4:
                cout << "Enter a post author:\n";
                cin >> input;
                cout << "Enter a user name:\n";
                cin >> input2;
                temp_value = getLikes(input, posts, num_posts_stored, input2, users, num_users_stored);
                switch (temp_value)
                {
                    case 0:
                        cout << input2 << " has not liked the post posted by " << input << "\n";
                        break;
                    case -1:
                        cout << input2 << " has not viewed the post posted by " << input << "\n";
                        break;
                    case -2:
                        cout << "Database is empty.\n";
                        break;
                    case -3:
                        cout << input2 << " or " << input << " does not exist.\n";
                        break;
                    default:
                        cout << input2 << " liked the post posted by " << input << " " << temp_value << " times" << "\n";
                        break;
               }
                break;
            case 5:
                cout << "Enter a tag:\n";
                cin >> input;
                findTagUser(input, users, num_users_stored);
                break;
            case 6:
                cout << "Good bye!\n";
                break;
            default:
                cout << "Invalid input.\n";
                break;
        }
    }

    return 0;
}