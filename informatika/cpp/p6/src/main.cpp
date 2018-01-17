#include <cstdlib>
#include <iostream>
#include "vector.h"

using namespace std;

int main() {
	vector a(5);
	cout << "Empty container a: " << a << endl;
	cout << "Enter the elements of the container a: " << endl;
	cin >> a;
	cout << "The length of a = " << a() << endl;
	cout << "Container with user content a: " << a << endl;
	cout << "a[2] = 100;" << endl;
	a[2] = 100;
	cout << "Modified container with user content a: " << a << endl;

	vector b(10);
	cout << endl << "Empty container b: " << b << endl;
	b = a;
	cout << "b = a;" << endl << "b: " << b << endl;

	vector c(10);
	c = b + 100;
	cout << endl << "c = b + 100;" << endl << "c: " << c << endl;

	vector d(3);
	cout << endl << "Enter the elements of the container d(3): " << endl;
	cin >> d;
	cout << "d: " << d << endl;

	vector e(5);
	e = c + d;
	cout << endl << "e = c + d;" << endl << "e: " << e << endl;


	cout << endl << "*(a.first()): " << *(a.first()) << endl;
	Iterator i = a.first();
	cout << endl << "i = a.first();" << endl;
	++i;
	cout << "*(++i):" << *i << endl;
	i+2;
	cout << "*(i+2):" << *i << endl;
	cout << endl << "All items: " << endl;
	for (i=a.first(); i!=a.last(); ++i)
		cout << "a.elem: " << *i << endl;
    return 0;
}

