#include <iostream>
#include <fstream>
#include "Post.cpp"
#include "User.cpp"

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
            for (int i = 1; i <= max_posts; i++)
            {
                users[num_users_stored].setLikesAt(i - 1, stoi(temp_arr[i]));
            }
            num_users_stored++;
        }
    }

    return num_users_stored;
}

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
                    default:
                        if (temp_value == arr_size)
                        {
                        cout << "Database is full. Some posts may have not been added.\n";
                        } else
                        {
                        num_posts_stored = temp_value;
                        cout << "Total posts in the database: " << num_posts_stored << "\n";
                        }
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