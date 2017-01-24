#include <iostream>

using namespace std;

int main() {
int n,m;
cout << "Enter n: ";
cin >> n;
cout << "Enter m: ";
cin >> m;
cout << "++n*++m: " << ( ++n*++m ) << endl;
cout << "m++<n: " << ( m++<n ) << endl;
cout << "n++>m: " << ( n++>m ) << endl;
return 0;
}
