#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
    private:
        string username_;
        static const int size_ = 50;
        int likes_[size_];
        int num_posts_;

    public:
        User();
        User(string username, int likes[], int num_posts);

        string getUsername();
        void setUsername(string username);

        int getLikesAt(int post_id);
        bool setLikesAt(int post_id, int num_likes);

        int getNumPosts();
        void setNumPosts(int num_posts);

        int getSize();
};

#endif