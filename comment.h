#pragma once
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
    void display();
};
