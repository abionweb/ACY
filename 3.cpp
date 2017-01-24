#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double y(double x) {
	double result;
	result = (-1) * (log(fabs(2*sin(x/2))));
	return result;
}

double sn(double x, int n) {
	double result = 0, AN = cos(x);

	for (int i = 1; i <= n; i++) {
		AN = AN*(cos(i*x)/i*cos(x));
		result += AN;
	}
	return result;
}

double se(double x, double e) {
	double result = 0, AN=cos(x);
	for(int i=1; fabs(AN)>=e ; i++){
		AN=AN*(cos(i*x)/i*cos(x));
		result+=AN; 
	}
	return result;
}

int main() {
	const int prec = 5, k = 10, n = 40;
	const double a = M_PI / 5, b = 9 * M_PI / 5, e = 0.0001;
	cout << setprecision(prec);
	
	for (double x = a; x<b; x = x + (b-a)/k) {
		cout << "X: " << x << "\tSN: " << sn(x,n) << "\tSE: " << se(x,e) << "\tY: " << y(x) << endl;
	}
	
	return 0;
}
