#include <iostream>
#include <fstream>
#include <string>
#include "comment.h"
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

void Comment::display() {
    cout << author << endl;
    cout << text << endl;
}
