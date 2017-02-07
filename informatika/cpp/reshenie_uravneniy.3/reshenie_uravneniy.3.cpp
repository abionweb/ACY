#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double fi(double x) {
	//Исходная функция: f(x) = x*x - 3*x + 4/2.3
	return (3 - 4/(2.3*x));
}
 
int main() {
    double x_next=0, x, e=0.000001; int prec = 10;
	cout << setprecision(prec);
    do {
		cout << "x: " << x << "\tx_next: " << x_next << endl;
		x = x_next;
		x_next = fi(x);
    } while (fabs(x_next-x)>e);
    cout << "x: " << x << "\tx_next: " << x_next << endl;
    return 0;
}
