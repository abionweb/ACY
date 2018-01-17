#include "vector.h"
#include "time.h"
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

	Vector <int> c(10,5);
	cout << endl << "c: " << c << endl;
	Vector <int> d(1,0);
	cout << "d: " << d << endl << "d = b + c;" << endl;
	d = b + c;
	cout << "d: " << d << endl << endl;

	time t;
	cin >> t;
	cout << t;
	return 0;
}
