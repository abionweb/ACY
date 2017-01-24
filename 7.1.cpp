#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double f(double x) {
//return ((x-5)*(x-5)*(x-5)+2*x-3);
return (pow(x,2) - 3*x + 4/2.3);
}

int main() {
double a = 1, b = 4, e = 0.000001, x; int k=0, prec=10;
cout << setprecision(prec);
cout<<"y=(x-5)^3+2x-3\n" << "a: " << a << "\nb: " << b << "\ne: 0.000001\n";
x=(a+b)/2;
cout << "X:"<< x << "\n";
while(fabs(b-a)>e) {
	if(f(a)*f(x)<=0) b=x;
	else a=x;
	x=(a+b)/2;
	k++;
	cout << "k: " << k << "\tX: "  << x << "\t|b-a|: " << fabs(b-a) << "\n";
} 
cout << "\nX: " << x << "\n";
return 0;
}
