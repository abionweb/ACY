#include <iostream>

#include "Error2.h"
#include "Vector2.h"
#include "Error3.h"
#include "Vector3.h"
using namespace std;

int main() {
	try {
		Vector2 x2(2);
		Vector2 y2;
		cout << x2;
		cout << "Number? ";
		int i2;
		cin >> i2;
		cout << "x[" << i2 << "]=" << x2[i2] << endl;
		cout << "y = x + 3" << endl;
		y2 = x2 + 3;
		cout << y2;
		cout << "y = y - 2" << endl;
		y2 = y2 - 2;
		cout << y2;

		cout << "x: " << x2;
		cout << "--x; x:" << --x2;
		cout << "--x; x:" << --x2;
		cout << "--x; x:" << --x2;
	}
	catch(error2 e) { e.what(); }

	try {
		Vector3 x3(2);
		Vector3 y3;
		cout << x3;
		cout << "Number? ";
		int i3;
		cin >> i3;
		cout << "x[" << i3 << "]=" << x3[i3] << endl;
		cout << "y = x + 3" << endl;
		y3 = x3 + 3;
		cout << y3;
		cout << "y = y - 2" << endl;
		y3 = y3 - 2;
		cout << y3;

		cout << "x: " << x3;
		cout << "--x; x:" << --x3;
		cout << "--x; x:" << --x3;
		cout << "--x; x:" << --x3;
	}
	catch(Error3 &e) { e.what(); }
	return 0;
}
