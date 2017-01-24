#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int size = 7;

void output (const char *expression[], float *f, double *d) {
	for (int i = 0; i<size; i++) {
		cout << (i+1) << ") " << expression[i] << endl << " float: " << f[i] << endl << "double: " << d[i] << endl << endl;
	}
}

int main() {
	//system("cls");
	int prec = 10;
	float a = 1000, b = 0.001;
	float f[7]; double d[7];
	const char *text[size] = {"a-b","(a-b)²","a²","b²","2ab","(a-b)² - (a² -2ab)","result"};
	
	cout << endl << "(a - b)² - (a² -2ab)" << endl << "————————————————————" << endl << "         b²" << endl << endl;
	cout << setprecision(prec);
	f[0] = a - b;                  d[0] = a - b;
	f[1] = pow(f[0],2);            d[1] = pow(d[0],2);
	f[2] = pow(a,2);               d[2] = pow(a,2);
	f[3] = pow(b,2);               d[3] = pow(b,2);
	f[4] = 2*a*b;                  d[4] = 2*a*b;
	f[5] = f[1] - f[2] + f[4];     d[5] = d[1] - d[2] + d[4];
	f[6] = f[5] / f[3];            d[6] = d[5] / d[3];
	output(text,f,d);
	return 0;
}
