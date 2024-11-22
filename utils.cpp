#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
using namespace std;

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
    cout << commentId << endl;
    cout << author << endl;
    cout << text << endl;
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
    cout << postId << endl;
    cout << description << endl;
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
    cout << pageId << endl;
    cout << title << endl;
    cout << likes << endl;
}

void Page::viewPosts() {
    for (int i = 0; i < postsCount; i++) {
       posts[i].viewPost();
    }
}

User::User(): email(""), name(""), bio(""), friends(nullptr), friendsCount(0), likedPages(nullptr), likedPagesCount(0) {}

User::User(string e): email(e) {}
