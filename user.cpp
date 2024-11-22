#include <iostream>
#include <fstream>
#include <string>
#include "user.h"
using namespace std;

User::User(): email(""), name(""), bio(""), friends(nullptr), likedPages(nullptr) {}

User::User(string e): email(e) {}
