#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

class Comment {
private:
    string commentId;
    string author;
    string text;

public:
    Comment();
    Comment(string id);
    void viewComment();
};

class Post {
private:
    string postId;
    string description;
    Comment* comments;
    int commentsCount;

public:
    Post();
    Post(string id);
    void viewPost();
    void viewComments();
};

class Page {
private:
    string pageId;
    string title;
    string likes;
    Post* posts;
    int postsCount;

public:
    Page();
    Page(string id);
    void viewPage();
    void viewPosts();
};

class User {
private:
    string email;
    string name;
    string bio;
    string friends;
    Page* likedPages;
    int likedPagesCount;

public:
    User();
    User(string e);
    void viewUser();
    void viewFriends();
    void viewLikedPages();
};

#endif
