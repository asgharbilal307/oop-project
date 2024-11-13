#include<iostream>
#include<string>
#include "header.h"
using namespace std;

int main() {

	cout << "                                                  Welcome to facebook   " << endl;
	cout << endl;
	string mail;
	cout << "enter user email address : " << endl;
	getline(cin, mail);

	string passcode;
	cout << "password : " << endl;
	getline(cin, passcode);

	login lg(mail, passcode);
	lg.readfile();

	while (!lg.compare()) {
		cout << "You entered wrong email or password." << endl;

		cout << "Enter user email address: " << endl;
		getline(cin, mail);

		cout << "Password: " << endl;
		getline(cin, passcode);

		lg = login(mail, passcode);
		lg.readfile();
	}

	lg.displayfile();

	personalinfo in;
	int choice;
	do {
		cout << "enter 2 for personal information : " << endl;
		cout << "enter 3 for Friends list : " << endl;
		cin >> choice;

		if (choice == 2) {
			cout << "                                                  user information   " << endl;
			cout << endl;
			in.userinfo();
		}

		if (choice == 3) {
			cout << "                                                  Friend List   " << endl;
			cout << endl;
			in.displayfriendslist();
		}
	}

	while (choice != 4);
}
