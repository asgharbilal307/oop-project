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
		
		int value;

		while (true) {
			cout << "Enter 1 to view info, 2 to view friends, 3 to view liked pages, 4 to exit: ";
			cin >> value;

			if (value == 1) {
				user->viewUser();
			} else if (value == 2) {
				user->viewFriends();
			} else if (value == 3) {
				user->viewLikedPages();
			} else if (value == 4) {
				break;
			} else {
				cout << "Invalid number entered. Please try again." << endl;
			}
		}

		cout << "Enter page id: ";
		cin >> value;

		Page* page = new Page(to_string(value));

		while (true) {
			cout << "Enter 1 to view page, 2 to view posts, 3 to exit: ";
			cin >> value;

			if (value == 1) {
				page->viewPage();
			} else if (value == 2) {
				page->viewPosts();
			} else if (value == 3) {
				break;
			} else {
				cout << "Invalid number entered. Please try again." << endl;
			}
		}

		cout << "Enter post id: ";
		cin >> value;

		Post* post = new Post(to_string(value));

		while (true) {
			cout << "Enter 1 to view post, 2 to view comments, 3 to exit: ";
			cin >> value;

			if (value == 1) {
				post->viewPost();
			} else if (value == 2) {
				post->viewComments();
			} else if (value == 3) {
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
