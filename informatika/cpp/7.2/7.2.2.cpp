#include <iostream>
using namespace std;
int sum (int k, ...) {
	int *p = &k; //��������� ��������� �� �������� k
	int s=0;
	for (int l = 2 ; l!=0; l--) {
		cout << p << "\n";
		cout << *p << "\n";
		cout << *(++p) << "\n";
		s+=*(++p);
		cout << p << "\n";
		cout << *p << "\n";
	}
	return s;
}

int main( ) {
	int a = 4,
		b = 6;
		
	cout << "\n�����(2,4,6)= " << sum(2,a,b); //������������ 4+6
	cout << "\n�����(4,1,2,3,4)=" << sum(4,1,2,3,4);//������������ 1+2+3+4
	cout << "\n";
}
