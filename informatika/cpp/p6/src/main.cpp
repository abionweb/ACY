#include <cstdlib>
#include <iostream>
#include "vector.h"

using namespace std;

int main() {
	vector a(5);
	cout << "a: " << a << endl;
	cin >> a;
	cout << "a: " << a << endl;
	a[2] = 100;
	cout << "a: " << a << endl;

	vector b(10);
	cout << "b: " << b << endl;
	b = a;
	cout << "b: " << b << endl;

	vector c(10);
	c = b + 100;
	cout << "c: " << c << endl;

	vector d(5);
	d = a + c;
	cout << "d: " << d << endl;

	cout << endl << "the length of a =" << a() << endl;
    return 0;
}

