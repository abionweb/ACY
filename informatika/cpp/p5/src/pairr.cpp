#include "pairr.h"
#include <iostream>
using namespace std;

pairr& pairr::operator = (const pairr& p) {
    if(&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

istream& operator>>(istream& in, pairr& p) {
	cout << "Enter a pair of numbers: " << endl;
    cout << "First: "; in >> p.first;
    cout << "Second: "; in >> p.second;
    cout << endl;
    return in;
}

ostream &operator << (ostream& out, const pairr& p) {
    return (out << p.first << " " << p.second);
}

void pairr::show() {
	cout << "First number: "       << first << endl;
	cout << "Second number: "      << second << endl;
	cout << "Product of numbers: " << get_product() << endl << endl;
}

int pairr::get_product() {
    return first*second;
}
