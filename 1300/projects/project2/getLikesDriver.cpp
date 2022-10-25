#include "Post.cpp"
#include "User.cpp"

using namespace std;

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