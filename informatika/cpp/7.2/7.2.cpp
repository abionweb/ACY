#include <iostream>
#include <iomanip> //setprecision

using namespace std;

int mult(int k, int first, ...) {
	//cout << "\n    n: " << &n << ": " << n << "\n";
	cout << "\n    k: " << &k << ": " << k << "\n";
	cout << "\nfirst: " << &first << ": " << first << "\n";
	
	int *p = &first;
	int result = first;
	for (;k!=0;k--) {
		cout << "result: " << result << "\n";
		result = *(++p);
		cout << p << ": " << *p << "\n";
	}
	return result;
}

int main() {
	cout << setprecision(2);
	cout << "\n Product of numbers is " << mult( 3, 10, 2, 20) << '\n';
	//cout << "\n Product of numbers is " << mult(7, 10.3, 3.20, 33.43, 40,   50, 60.22, 9.2) << '\n';
	//cout << "\n Product of numbers is " << mult(11,  10, 20.6, 50.47, 12, 24.2,  6.24, 3.2, 87.7, 44.3, 32.4, 46.3) << '\n';
	return 0;
}
