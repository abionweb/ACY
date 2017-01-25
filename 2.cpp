#include <iostream>
using namespace std;
int main() {
	int s;
	for (int i = 0; i < 100; i++) {
		if (not (i % 2)) {
			s += i;
			cout << "i: " << i << " s: " << s << endl;
		}
	}
	cout << "the sum of the even numbers from 0 to 99: " << s << endl;
	return 0;
}
