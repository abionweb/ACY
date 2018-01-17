//============================================================================
// Name        : p7.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "vector.h"
#include <iostream>

using namespace std;

int main() {
	Vector <int> a(5,0);
	cout << "Enter the elements of the container a:" << endl;
	cin >> a;
	cout << "a: " << a << endl;
	cout << "a[2]: " << a[2] << endl;
	cout << "The length of a = " << a() << endl << endl;

	Vector <int> b(10,1);
	cout << "b: " << b << endl << "b = a;" << endl;
	b = a;
	cout << "b: " << b << endl;
	b = a + 10;
	cout << "b = a + 10;" << endl << "b: " <<  b << endl;

	return 0;
}
