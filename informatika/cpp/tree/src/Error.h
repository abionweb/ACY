#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error {
public:	virtual void what() {};
};

class EnterIntError
		: public Error {
protected:
	string msg;
public:
	EnterIntError() {msg = "Input Error. Requires an integer.\n";};
	virtual void what() {cout << msg;};
};

class EnterGeneralQuestion
		: public Error {
protected:
	string msg;
public:
	EnterGeneralQuestion() {msg = "Input Error. allowed values 'manually', 'm', 'random', 'r', 'file', 'f'.\n";};
	virtual void what() {cout << msg;};
};
