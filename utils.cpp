#include "utils.h"
#include <iostream>
#include <fstream>

Comment::Comment(): commentId(""), author(""), text("") {}

Comment::Comment(string id): commentId(id) {
    ifstream file("comments.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == id) {
            getline(file, author);
            getline(file, text);
            break;
        }
    }

    file.close();
}

void Comment::viewComment() {
    cout << "Comment id: " << commentId << endl;
    cout << "Author: " << author << endl;
    cout << "Text: " << text << endl;
}

Post::Post(): postId(""), description(""), comments(nullptr), commentsCount(0) {}

Post::Post(string id): postId(id) {
    ifstream file("posts.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == id) {
            getline(file, description);
            string commentsLine;
            getline(file, commentsLine);
            string temp = commentsLine;
            commentsCount = 0;

            while (true) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    commentsCount++;
                    temp.erase(0, foundIndex + 2);
                } else {
                    commentsCount++;
                    break;
                }
            }

            comments = new Comment[commentsCount];
            temp = commentsLine;

            for (int i = 0; i < commentsCount; i++) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    comments[i] = Comment(temp.substr(0, foundIndex));
                    temp.erase(0, foundIndex + 2);
                } else {
                    comments[i] = Comment(temp.substr(0, foundIndex));
                    break;
                }
            }

            break;
        }
    }

    file.close();
}

void Post::viewPost() {
    cout << "Post id: " << postId << endl;
    cout << "Description: " << description << endl;
}

void Post::viewComments() {
    for (int i = 0; i < commentsCount; i++) {
       comments[i].viewComment();
    }
}

Page::Page(): pageId(""), title(""), likes(""), posts(nullptr), postsCount(0) {}

Page::Page(string id): pageId(id) {
    ifstream file("pages.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == id) {
            getline(file, title);
            getline(file, likes);
            string postLine;
            getline(file, postLine);
            string temp = postLine;
            postsCount = 0;

            while (true) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    postsCount++;
                    temp.erase(0, foundIndex + 2);
                } else {
                    postsCount++;
                    break;
                }
            }

            posts = new Post[postsCount];
            temp = postLine;

            for (int i = 0; i < postsCount; i++) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    posts[i] = Post(temp.substr(0, foundIndex));
                    temp.erase(0, foundIndex + 2);
                } else {
                    posts[i] = Post(temp.substr(0, foundIndex));
                    break;
                }
            }

            break;
        }
    }

    file.close();
}

void Page::viewPage() {
    cout << "Page id: " << pageId << endl;
    cout << "Title: " << title << endl;
    cout << "Likes: " << likes << endl;
}

void Page::viewPosts() {
    for (int i = 0; i < postsCount; i++) {
       posts[i].viewPost();
    }
}

User::User(): email(""), name(""), bio(""), friends(""), likedPages(nullptr), likedPagesCount(0) {}

User::User(string e): email(e) {
    ifstream file("users.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == email) {
            getline(file, name);
            getline(file, bio);
            getline(file, friends);
            string likedPagesLine;
            getline(file, likedPagesLine);
            string temp = likedPagesLine;
            likedPagesCount = 0;

            while (true) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    likedPagesCount++;
                    temp.erase(0, foundIndex + 2);
                } else {
                    likedPagesCount++;
                    break;
                }
            }

            likedPages = new Page[likedPagesCount];
            temp = likedPagesLine;

            for (int i = 0; i < likedPagesCount; i++) {
                int foundIndex = temp.find(",");

                if (foundIndex != string::npos) {
                    likedPages[i] = Page(temp.substr(0, foundIndex));
                    temp.erase(0, foundIndex + 2);
                } else {
                    likedPages[i] = Page(temp.substr(0, foundIndex));
                    break;
                }
            }

            break;
        }
    }

    file.close();
}

void User::viewUser() {
    cout << "Email: " << email << endl;
    cout << "Name: " << name << endl;
    cout << "Bio: " << bio << endl;
}

void User::viewFriends() {
    cout << "Friends: " << friends << endl;
}

void User::viewLikedPages() {
    for (int i = 0; i < likedPagesCount; i++) {
       likedPages[i].viewPage();
    }
}
