#include "Post.h"

using namespace std;

Post::Post()
{
    body_ = "";
    post_author_ = "";
    num_likes_ = 0;
    date_ = "";
}
Post::Post(string body, string post_author, int num_likes, string date)
{
    body_ = body;
    post_author_ = post_author;
    
    if(num_likes >= 0)
    {
        num_likes_ = num_likes;
    } else
    {
        num_likes_ = 0;
    }

    date_ = date;
}

string Post::getPostBody()
{
    return body_;
}
void Post::setPostBody(string body)
{
    body_ = body;
}

string Post::getPostAuthor()
{
    return post_author_;
}
void Post::setPostAuthor(string post_author)
{
    post_author_ = post_author;
}

int Post::getPostLikes()
{
    return num_likes_;
}
void Post::setPostLikes(int num_likes)
{
    if(num_likes >= 0)
    {
        num_likes_ = num_likes;
    }
}

string Post::getPostDate()
{
    return date_;
}
void Post::setPostDate(string date)
{
    date_ = date;
}