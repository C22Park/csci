#ifndef POST_H
#define POST_H
#include <string>

using namespace std;

class Post
{
    private:
        string body_;
        string post_author_;
        int num_likes_;
        string date_;

    public:
        Post();
        Post(string body, string post_author, int num_likes, string date);

        string getPostBody();
        void setPostBody(string body);

        string getPostAuthor();
        void setPostAuthor(string post_author);

        int getPostLikes();
        void setPostLikes(int num_likes);

        string getPostDate();
        void setPostDate(string date);
};

#endif