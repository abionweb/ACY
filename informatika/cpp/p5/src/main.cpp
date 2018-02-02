#include <cstdlib>
#include <iostream>
#include "pairr.h"
#include "rectangle.h"
#include "vector.h";
//#include <vector>

using namespace std;

int main() {
	vector v(5);
	Object *p;

    pairr a;
    cin >> a;
    p = &a;
    v.add(p);

    rectangle b;
    cin >> b;
    p = &b;
    v.add(p);

    cout << v;
    return 0;
}

