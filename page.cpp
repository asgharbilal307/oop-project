#include <iostream>
#include <fstream>
#include <string>
#include "page.h"
using namespace std;

Page::Page(): pageId(""), title(""), likes(0), post(nullptr) {}

Page::Page(string id): pageId(id) {}
