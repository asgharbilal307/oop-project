#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;

int main() {
    cout << "Enter email: ";
	string email;
	cin >> email;
	cout << "Enter password: ";
	string password;
	cin >> password;
	bool emailCorrect = false;
	ifstream file("login.txt");
    string line;

    while (getline(file, line)) {
        if (line.empty()) continue;

        if (line == email) {
            emailCorrect = true;
			break;
        }
    }

	getline(file, line);
	bool passwordCorrect = false;

	if (line == password) {
        passwordCorrect = true;
    }

	if (emailCorrect && passwordCorrect) {
		User* user = new User(email);
		cout << "Welcome" << endl;
		
		int firstValue;
		int secondValue;
		int thirdValue;

		while (true) {
			cout << "Enter 1 to view info, 2 to view friends, 3 to view liked pages, 4 to exit: ";
			cin >> firstValue;

			if (firstValue == 1) {
				user->viewUser();
			} else if (firstValue == 2) {
				user->viewFriends();
			} else if (firstValue == 3) {
				user->viewLikedPages();
			} else if (firstValue == 4) {
				break;
			} else {
				cout << "Invalid number entered. Please try again." << endl;
			}
		}

		string pageId;
		cout << "Enter page id: ";
		cin >> pageId;

		Page* page = new Page(pageId);

		while (true) {
			cout << "Enter 1 to view page, 2 to view posts, 3 to exit: ";
			cin >> secondValue;

			if (secondValue == 1) {
				page->viewPage();
			} else if (secondValue == 2) {
				page->viewPosts();
			} else if (secondValue == 3) {
				break;
			} else {
				cout << "Invalid number entered. Please try again." << endl;
			}
		}

		string postId;
		cout << "Enter post id: ";
		cin >> postId;

		Post* post = new Post(postId);

		while (true) {
			cout << "Enter 1 to view post, 2 to view comments, 3 to exit: ";
			cin >> thirdValue;

			if (thirdValue == 1) {
				post->viewPost();
			} else if (thirdValue == 2) {
				post->viewComments();
			} else if (thirdValue == 3) {
				break;
			} else {
				cout << "Invalid number entered. Please try again." << endl;
			}
		}  
	} else {
		cout << "Either the email or password is incorrect." << endl;
	}
    
    return 0;
}
