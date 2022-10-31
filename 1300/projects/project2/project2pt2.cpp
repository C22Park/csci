// CSCI 1300 Fall 2022
// Author: Charlie Park
// Recitation: 305 - Nikhith Sannidi
// Project 2 Part 2 - Problem 10 - project2pt2.cpp

#include <iostream>
#include <fstream>
#include "../../split.cpp"
#include "Buffchat.h"

using namespace std;

Buffchat::Buffchat () // default constructor
{
        Post posts_[posts_size_];
        User users_[users_size_];
        int num_posts_ = 0;
        int num_users_ = 0;
}

int Buffchat::getPostSize() // returns posts_size_
{
    return posts_size_;
}

int Buffchat::getUserSize() // returns users_size_
{
    return users_size_;
}

int Buffchat::getNumPosts() // returns num_posts_
{
    return num_posts_;
}

int Buffchat::getNumUsers() // returns num_users_
{
    return num_users_;
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

int Buffchat::readPosts(string file_name)
{
    if (num_posts_ >= posts_size_)
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

    while(getline(in_file, temp_line) && num_posts_ < posts_size_)
    {
        if (temp_line != "")
        {
            if (split(temp_line, ',', temp_arr, 4) == 4)
            {
                posts_[num_posts_].setPostBody(temp_arr[0]);
                posts_[num_posts_].setPostAuthor(temp_arr[1]);
                posts_[num_posts_].setPostLikes(stoi(temp_arr[2]));
                posts_[num_posts_].setPostDate(temp_arr[3]);
                num_posts_++;
            }
        }
    }
 
    return num_posts_;
}

/*
    Algorithm:
    1. If # of posts stored it <= 0 return "No posts are stored"
    2. print "Here is a lists of posts for year " year
    3. for all posts if a post has the last two characters of its date == to year print post body
*/

void Buffchat::printPostsByYear(string year)
{
    if (num_posts_ <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    int temp_value = 1;
    for (int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostDate().substr(6, 2) == year)
        {
            if (temp_value)
            {
                cout << "Here is a list of posts for year " << year << "\n";
                temp_value = 0;
            }
            cout << posts_[i].getPostBody() << "\n";
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

int Buffchat::readLikes(string file_name)
{
    if (num_users_ == users_size_)
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
    string temp_arr[posts_size_ + 1];
    

    while(getline(in_file, temp_line) && num_users_ < users_size_)
    {
        if (temp_line != "")
        {
            split(temp_line, ',', temp_arr, posts_size_ + 1);
            users_[num_users_].setUsername(temp_arr[0]);
            for (int i = 0; i < posts_size_; i++)
            {
                if (temp_arr[i + 1] != "")
                {
                users_[num_users_].setNumPosts(i + 1);
                users_[num_users_].setLikesAt(i, stoi(temp_arr[i + 1]));
                }
            }
            num_users_++;
        }
    }

    return num_users_;
}

/*
    Algorithm:
    1. if # of current posts or users stored is <= 0 return -2
    2. if you cant find desired username or post_author in their respective arrays return -3
    3. return the amount of likes username has at the post_id corresponding to the first appearence of post_author
*/

int Buffchat::getLikes(string post_author, string username)
{
    if (num_posts_ <= 0 || num_users_ <= 0)
    {
        return -2;
    }
    
    bool valid_post = false;
    for (int i = 0; i < num_users_; i++)
    {
        if (users_[i].getUsername() == username)
        {
            valid_post = true;
        }
    }
    if (!valid_post)
    {
        return -3;
    }
    valid_post = false;
    for (int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostAuthor() == post_author)
        {
            valid_post = true;
        }
    }
    if (!valid_post)
    {
        return -3;
    }

    for (int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostAuthor() == post_author)
        {
            for (int j = 0; j < num_users_; j++)
            {
                if (users_[j].getUsername() == username)
                {
                    return users_[j].getLikesAt(i);
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

void Buffchat::findTagUser(string username_tag)
{
if (num_users_ <= 0)
    {
        cout << "No users are stored in the database\n";
        return;
    }

    string matching_users[num_users_];
    int num_users_found = 0;
    for (int i = 0; i < num_users_; i++)
    {
        if (username_tag.length() < users_[i].getUsername().length())
        {
            for (int j = 0; j <= users_[i].getUsername().length() - username_tag.length(); j++)
            {
                if (username_tag == users_[i].getUsername().substr(j, username_tag.length()))
                {
                    matching_users[num_users_found] = users_[i].getUsername();
                    num_users_found++;
                }
            }
        }
    }

    if (num_users_found == 0)
    {
        cout << "No matching user found\n";
    } else
    {
        cout << "Here are all the usernames that contain " << username_tag << "\n";
        for (int i = 0; i < num_users_found; i++)
        {
            cout << matching_users[i] << "\n";
        }
    }
    return;
}

/*
    Algorithm:
    1. if the posts array is full return false
    2. set posts_[new_post_id] post body to post_body, post author to post_author, post date to date, and post likes to 0
    3. set the likes for all users at new_post_id to -1
    4. add one to num_posts_ and return true 
*/

bool Buffchat::addPost(string post_body, string post_author, string date)
{
    if (num_posts_ == posts_size_)
    {
        return false;
    }

    posts_[num_posts_].setPostBody(post_body);
    posts_[num_posts_].setPostAuthor(post_author);
    posts_[num_posts_].setPostDate(date);
    posts_[num_posts_].setPostLikes(0);
    for (int i = 0; i < num_users_; i++)
    {
        users_[i].setLikesAt(num_posts_, -1);
    }
    num_posts_++;

    return true;
}

/* 
    Algorithm:
    1. if posts database is empty return "No posts are stored"
    2. add every post with matching year to an array of posts
    3. if the number of posts in that array is < count return "There are fewer than count posts for year year. Top (number of posts in array) posts for year year" and the posts in the array
    4. if the number of posts in teh array is 0 return "No posts are stored for year year"
    5. if the number of posts in that array is >= count remove the lowest liked posts in the array until you have count left
    6. return "Top count posts for year year" and the posts in the array
*/

void Buffchat::printPopularPosts(int count, string year)
{
    int check_int = 0;
    Post temp_posts[num_posts_];

    if (num_posts_ <= 0)
    {
        cout << "No posts are stored\n";
        return;
    }

    for (int i = 0; i < num_posts_; i ++)
    {
        if (posts_[i].getPostDate().substr(6, 2) == year)
        {
            temp_posts[check_int] = posts_[i];
            check_int++;
        }
    }
    if (check_int < count && check_int > 0)
    {
        cout << "There are fewer than " << count << " posts for year " << year << ". Top " << check_int 
             << " posts for year " << year << "\n";
        for (int i = 0; i < check_int; i++)
        {
            cout << temp_posts[i].getPostLikes() << " likes: " << temp_posts[i].getPostBody() << "\n";
        }
    } else if (check_int == 0)
    {
        cout << "No posts stored for year " << year << "\n";
    } else
    {
        int min_likes;
        Post remove_post;

        while (check_int > count)
        {
            min_likes = temp_posts[0].getPostLikes();
            for (int i = 0; i < check_int; i++)
            {
                if (temp_posts[i].getPostLikes() < min_likes)
                {
                    min_likes = temp_posts[i].getPostLikes();
                    remove_post = temp_posts[i];
                }
            }
            for (int i = 0; i < check_int; i++)
            {
                if (temp_posts[i].getPostBody() == remove_post.getPostBody())
                {
                    temp_posts[i] = Post();
                }
            }
            for (int i = 0; i < check_int - 1; i++)
            {
                if (temp_posts[i].getPostDate() == "")
                {
                    temp_posts[i] = temp_posts[i + 1];
                    temp_posts[i + 1] = Post();
                }
            }
            check_int--;
        }

        cout << "Top " << count << " posts for year " << year << "\n";
        for (int i = 0; i < count; i++)
        {
            cout << temp_posts[i].getPostLikes() << " likes: " << temp_posts[i].getPostBody() << "\n";
        }
    }
}

/*
    ALgorithm:
    1. If there are no users stored in database return a default constructor user
    2. return the user with the most unviewed posts(or posts where likes_ == -1)
*/

User Buffchat::findLeastActiveUser()
{
    User least_active_user;
    if (num_users_ == 0)
    {
        return least_active_user;
    }   

    int least_active_unviewed = 0;
    int check_unviewed = 0;
    for (int i = 0; i < num_users_; i++)
    {
        for (int j = 0; j < num_posts_; j++)
        {
            if (users_[i].getLikesAt(j) == -1)
            {
                check_unviewed++;
            }
        }
        if (check_unviewed > least_active_unviewed)
        {
            least_active_user = users_[i];
            least_active_unviewed = check_unviewed;

        }
        check_unviewed = 0;
    }
    return least_active_user;
}

/*
    Algorithm:
    1. if any of the databases are empty return -2
    2. if no one has viewed the post authors posts return -1
    3. if no one has liked the post authors posts return 0
    4. otherwise return how many times the post has likes > 0 
*/

int Buffchat::countUniqueLikes(string post_author)
{
    if (num_posts_ == 0 || num_users_ == 0)
    {
        return -2;
    }

    bool unviewed = true;
    int counter = 0;

    for(int i = 0; i < num_posts_; i++)
    {
        if (posts_[i].getPostAuthor() == post_author)
        {
            for (int j = 0; j < num_users_; j++)
            {
                if (users_[j].getLikesAt(i) != -1)
                {
                    unviewed = false;
                }
                if(users_[j].getLikesAt(i) > 0)
                {
                    counter++; 
                }
            }
        }
    }

    if (unviewed)
    {
        return -1;
    } else 
    {
        return counter;
    }
}

int main()
{
    string menu = "0";
    string input, input2, input3;
    Buffchat buffchat;
    int temp_value = 0;
    User blank_user;
    while (stoi(menu) != 10)
    {
        cout << "======Main Menu=====\n"
             << "1. Read posts\n"
             << "2. Print Posts By Year\n"
             << "3. Read Likes\n"
             << "4. Get Likes\n"
             << "5. Find users with matching tag\n"
             << "6. Add a new post\n"
             << "7. Print popular posts for a year\n"
             << "8. Find least active user\n"
             << "9. Find unique likes for a post author\n"
             << "10. Quit\n";
        getline(cin, menu);

        switch (stoi(menu))
        {
            case 1:
                cout << "Enter a post file name:\n";
                getline(cin, input);
                switch (buffchat.readPosts(input))
                {
                    case -1:
                        cout << "File failed to open. No posts saved to the database.\n";
                        break;
                    case -2:
                        cout << "Database is already full. No posts were added.\n";
                        break;
                    case 50:
                        cout << "Database is full. Some posts may have not been added.\n";
                        break;
                    default:
                        cout << "Total posts in the database: " << buffchat.getNumPosts() << "\n";
                        break;
                }
                break;
            case 2:
                cout << "Enter the year(YY):\n";
                getline(cin, input);
                buffchat.printPostsByYear(input);
                break;
            case 3:
                cout << "Enter a user file name:\n";
                getline(cin, input);
                switch (buffchat.readLikes(input))
                {
                    case -1:
                        cout << "File failed to open. No users saved to the database.\n";
                        break;
                    case -2:
                        cout << "Database is already full. No users were added.\n";
                        break;
                    case 50:
                        cout << "Database is full. Some users may have not been added.\n";
                        break;
                    default:
                        cout << "Total users in the database: " << buffchat.getNumUsers() << "\n";
                        break;
               }
                break;
            case 4:
                cout << "Enter a post author:\n";
                getline(cin, input);
                cout << "Enter a user name:\n";
                getline(cin, input2);
                temp_value = buffchat.getLikes(input, input2);
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
                getline(cin, input);
                buffchat.findTagUser(input);
                break;
            case 6:
                cout << "Enter a post body:\n";
                getline(cin, input);
                cout << "Enter a post author:\n";
                getline(cin, input2);
                cout << "Enter a date(mm/dd/yy):\n";
                getline(cin, input3);
                if (buffchat.addPost(input, input2, input3))
                {
                    cout << input2 << "'s post added successfully\n";
                } else
                {
                    cout << "Database is already full. " << input2 << "'s post was not added\n";
                }
                break;
            case 7:
                cout << "Enter the number of posts:\n";
                getline(cin, input);
                cout << "Enter the year(YY):\n";
                getline(cin, input2);
                buffchat.printPopularPosts(stoi(input), input2);
                break;
            case 8:
                if(buffchat.findLeastActiveUser().getUsername() == blank_user.getUsername())
                {
                    cout << "There are no users stored\n";
                } else
                {
                    cout << buffchat.findLeastActiveUser().getUsername() << " is the least active user\n";
                }
                break;
            case 9:
                cout << "Enter a post author:\n";
                getline(cin, input);
                switch (buffchat.countUniqueLikes(input))
                {
                    case -2:
                        cout << "Database is empty.\n";
                        break;
                    case -1:
                        cout << "The posts posted by " << input << " have not been viewed by anyone.\n";
                        break;
                    case 0:
                        cout << "The posts posted by " << input << " have received 0 likes so far.\n";
                        break; 
                    default:
                        cout << "The posts posted by " << input << " have been liked by " << buffchat.countUniqueLikes(input)
                             << " unique users.\n";
                        break;
                }
                break;
            case 10:
                cout << "Good bye!\n";
                break;
            default:
                cout << "Invalid input\n";
                break;
        }
    }

    return 0;
}