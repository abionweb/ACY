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
	return 0;
}
