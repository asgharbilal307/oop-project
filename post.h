#pragma once
#include <string>
#include "user.h"
#include "comment.h"
using namespace std;

class Post {
private:
    string postId;
    string description;
    User* likes;
    Comment* comments;

public:
    Post();
    Post(string id);
    void viewLikes();
    void viewComments();
};
