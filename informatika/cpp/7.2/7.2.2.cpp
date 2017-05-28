#include <iostream>
using namespace std;
float sum (float k, ...) {
	float *p = &k; //настроили указатель на параметр k
	cout <<  "p: " << p << "\n";
	cout << "*p: " << *p << "\n";
	float s=0;
	
	/*while (*p) {
		cout <<  "p++" << "\n";
		p++;
		cout <<  "p: " << p << "\n";
		cout << "*p: " << *p << "\n";
	}*/
	for (; k!=0; k--) {
		cout <<  "p++" << "\n";
		p = p+1;
		cout <<  "p: " << p << "\n";
		cout << "*p: " << *p << "\n";
		s = s + *p;
		cout << "s: " << s << "\n";
	}
	return s;
}

int main( ) {
	cout << "\nСумма(2,4,6)= " << sum(5,47,5,30,5,6) << "\n"; //находитсумму 4+6
	cout << "\nСумма(4,1,2,3,4)=" << sum(4,1,2,3,4) << "\n";//находитсумму 1+2+3+4
	cout << "\n";
}
