#include <iostream>
#include <complex>

using namespace std;

float zplus(int n, float a[]) {
	float result = 0;
	for (int i=0; i<n; i++) {
		result += a[i];
	}
	return result;
}

complex<double> zplus(int n, complex<double> a[]) {
	complex<double> result = 0;
	for (int i=0; i<n; i++) {
		result += a[i];
	}
	return result;
}

int main() {
	float x[6]={10, 20, 30.43, 40, 50, 60.22};
	complex< double > y[6] = {
		complex< double >( 28, 33 ),
		complex< double >( 77, 31 ),
		complex< double >( 45, 95 ),
		complex< double >( 22, 80 ),
		complex< double >( 50, 10 ),
		complex< double >( 13, -3 )
	};
	cout << "\nThe sum of    real numbers is  " << zplus(6,x) << '\n';
	cout << "The sum of complex numbers is " << zplus(6,y) << "\n\n";
	return 0;
}
