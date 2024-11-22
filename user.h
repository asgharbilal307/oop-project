#pragma once
#include <string>
#include "page.h"
using namespace std;

class User {
private:
    string email;
    string name;
    string bio;
    User* friends;
    Page* likedPages;

public:
    User();
    User(string e);
    void viewHome();
    void viewTimeline();
    void viewFriendList();
};

