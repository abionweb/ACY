#pragma once
#include <string>
#include <iostream>
using namespace std;
class error2 {
	string str;
public:
	error2(string s){str = s;};
	void what(){cout << str << endl;};
};
