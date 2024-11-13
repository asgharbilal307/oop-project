#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class login {

	string email;
	string password;
	string c1;
	string c2;
public:

	login(string e,string p);
	void readfile();
	void displayfile();
	bool compare();
};

class personalinfo {

	string username;
	string bio;
	string friends;
	int count;
	string friendsnames[100];

public:

	personalinfo();
	void userinfo() const ;
	void displayfriendslist();
};
