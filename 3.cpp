#include <iostream>
#include <math.h> //sin fabs log
#include <iomanip> //setprecision

using namespace std;

double y(double x) {
	return (-1) * (log(fabs(2*sin(x/2))));
}

double sn(double x, int n) {
	double result = 0, An;
	for (int i = 1; i <= n; i++) {
		An = cos(i*x)/i;
		result += An;
	}
	return result;
}

double se(double x, double e) {
	double result = 0, An;
	for(int i=1; fabs(An)>=e ; i++){
		An = cos(i*x)/i;
		result += An; 
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
