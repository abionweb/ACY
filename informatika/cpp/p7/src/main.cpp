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
	cout << "t: " << t << endl;

	int k;
	cout << "How many seconds to add: ";
	cin >> k;
	time p;
	p = t + k;
	cout << "Result: " << p << endl;
	time o;
	cout << "How many time to add? " << endl;
	cin >> o;
	time u;
	u = p + o;
	cout << "Result: " << u << endl;

	Vector <time> at(5,u);
	cout << "Enter time 5 times: " << endl;
	cin >> at;
	cout << "at: " << at << endl;
	cout << "at[2]: " << at[2] << endl;
	cout << "The length of at = " << at() << endl;

	Vector <time> bt(10,t);
	cout << endl << "bt: " << bt << endl << "bt = at;" << endl;
	bt = at;
	cout << "bt: " << bt << endl << "bt = at + t;" << endl;
	bt = at + t;
	cout << "bt: " << bt << endl;
	return 0;
}
