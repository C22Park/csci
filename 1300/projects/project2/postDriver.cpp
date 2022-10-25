#include <iostream>
#include "Post.h"
#include "Post.cpp"

using namespace std;

int main()
{
    Post default_post; // default construction
    cout << "Post author " << default_post.getPostAuthor() << endl;
    cout << "Post body " << default_post.getPostBody() << endl;
    cout << "Post date " << default_post.getPostDate() << endl;
    cout << "Post likes " << default_post.getPostLikes() << endl;

    default_post.setPostAuthor("Charlie");  // setting new values
    default_post.setPostBody("This is my post");
    default_post.setPostDate("01/01/06");
    default_post.setPostLikes(1000);

    cout << "Post author " << default_post.getPostAuthor() << endl;
    cout << "Post body " << default_post.getPostBody() << endl;
    cout << "Post date " << default_post.getPostDate() << endl;
    cout << "Post likes " << default_post.getPostLikes() << endl;

    Post my_post = Post("welcome to my social media","Boris Johnson", 9, "08/10/20"); // parameterized constructor
    cout << "Post author " << my_post.getPostAuthor() << endl;
    cout << "Post body " << my_post.getPostBody() << endl;
    cout << "Post date " << my_post.getPostDate() << endl;
    cout << "Post likes " << my_post.getPostLikes() << endl;

    return 0;
}