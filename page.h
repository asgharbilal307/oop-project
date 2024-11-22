#pragma once
#include <string>
#include "post.h"
using namespace std;

class Page {
private:
    string pageId;
    string title;
    int likes;
    Post* post;

public:
    Page();
    Page(string id);
    void viewPosts();
};
