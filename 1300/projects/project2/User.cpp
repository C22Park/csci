#include "User.h"

using namespace std;

User::User()
{
    username_ = "";
    num_posts_ = 0;
    for (int i = 0; i < size_; i++)
    {
        likes_[i] = -1;
    }
}
User::User(string username, int likes[], int num_posts)
{
    username_ = username;
    num_posts_ = num_posts;
    for (int i = 0; i < num_posts_; i++)
    {
        likes_[i] = likes[i];
    }
    for (int i = num_posts_; i < size_; i++)
    {
        likes_[i] = -1;
    }
}

string User::getUsername()
{
    return username_;
}
void User::setUsername(string username)
{
    username_ = username;
}

int User::getLikesAt(int post_id)
{
    if (post_id < 0 || post_id >= size_)
    {
        return -2;
    } else
    {
    return likes_[post_id];
    }
}
bool User::setLikesAt(int post_id, int num_likes)
{
    if (post_id >= 0 && post_id < num_posts_  && num_likes >= -1 && num_likes <= 10)
    {
        likes_[post_id] = num_likes;
        return true;
    } else{
        return false;
    }
}

int User::getNumPosts()
{
    return num_posts_;
}
void User::setNumPosts(int num_posts)
{
    if (num_posts >= 0 && num_posts <= size_)
    {
        num_posts_ = num_posts;
    }
}

int User::getSize()
{
    return size_;
}