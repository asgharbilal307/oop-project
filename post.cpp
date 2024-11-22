#include <iostream>
#include <fstream>
#include <string>
#include "post.h"
using namespace std;

Post::Post(): postId(""), description(""), likes(nullptr), comments(nullptr) {}

Post::Post(string id): postId(id) {
	ifstream file("posts.txt");
	string line;
	
	while (getline(file, line)) {
		if (line.empty()) continue;

		if (line == id) {
			getline(file, description);

			string likesLine;
			getline(file, likesLine);

            string temp = likesLine;
			int likesCount = 0;

            while (true) {
				int foundIndex = temp.find(",");

				if (foundIndex != string::npos) {
					likesCount++;
					temp.erase(0, foundIndex + 2);
				} else {
					likesCount++;
					break;
				}
			}

			likes = new User[likesCount];
			temp = likesLine;

			for (int i = 0; i < likesCount; i++) {
				int foundIndex = temp.find(",");

				if (foundIndex != string::npos) {
					likes[i] = User(temp.substr(0, foundIndex));
					temp.erase(0, foundIndex + 2);
				} else {
					break;
				}
			}

			string commentsLine;
			getline(file, commentsLine);
			
			temp = commentsLine;
			int commentsCount = 0;

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
					break;
				}
			}

			break;
		}
	}

    file.close();
}
