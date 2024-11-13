#include <iostream>
#include<string>
#include<fstream>
#include "header.h"
using namespace std;

login::login(string e, string p) 

{
	
	email = e;
	c1 = email;
	password = p;
	c2 = password;

}

void login::readfile() {
	ifstream info("password.txt");

	getline(info, email);
	getline(info, password);
	
}

void login::displayfile() 

{

	
		cout << "user email address is : " << email << endl;
		cout << "user password is : " << password << endl;
	
}

bool login::compare() {

	bool flag = 0;
	if (c1 != email || c2 != password) {
		flag = 0;
	}

	else {
		flag=1;
	}

	return flag;
}

personalinfo::personalinfo()

{
	    ifstream input("personal.txt");
		getline(input, username);
		getline(input, bio);
		count = 0;

		ifstream friendlist("friendlist.txt");
		while (getline(friendlist, friends)) {
			friendsnames[count] = friends;
			count++;
		}

}

void personalinfo::displayfriendslist()  {

	for (int i = 0; i < count; i++) {
		cout << friendsnames[i] << endl;
	}
}

void personalinfo::userinfo() const {

	cout << "user name is : " << username << endl;
	cout << bio << endl;
	cout << "total number of friends are : " << count << endl;

}
void timeline::readfile() {

	ifstream in("timeline.txt");
	while (getline(in, posts)) {
		cout << posts << endl;
	}
}
