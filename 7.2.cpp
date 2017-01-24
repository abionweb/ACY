#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double f(double x) {
	//return ((x-5)*(x-5)*(x-5)+2*x-3);
	return (pow(x,2) - 3*x + 4/2.3);
}
double df(double x) {
	//return (3*x*x-30*x+77);           
	return (2*x-3);
}
int main()
{
	double e = 0.000001, x = 4, x_prev; int k=0, prec = 10;
	cout << setprecision(prec);
	cout << "y=(x-5)^3+2x-3\n";
	cout << "e: 0.000001\n";
	
	do {
		x_prev = x;
		double dif = df(x);
		if (dif) x = x_prev - f(x)/dif;
		else {
			cout << "error: df(x) = 0\n";
			return 0;
		}
		cout << "k: " << k << "\tX: " << x << "\n";
		k++;
	}
	while (fabs(x_prev-x)>e);
	return 0;
}

