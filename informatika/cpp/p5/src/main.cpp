/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pavel
 *
 * Created on 5 июня 2017 г., 1:55
 */

#include <cstdlib>
#include <iostream>
#include "pairr.h"
//#include "rectangle.h"

using namespace std;
/*
void f1(pairr&p) {
    p.set_second(100);
    cout << p << endl << endl;
}

rectangle f2() {
    rectangle r(10,33);
    return r;
}
*/
int main() {
	int i;
    pairr a;
    cout << "Enter first number: " << endl; cin >> a; cout << endl;
    /*a.set_first(i);
    cout << "Enter second number: " << endl; cin >> i; cout << endl;
    a.set_second(i);
     */
    cout << "a.first * a.second = " << a.get_product() << endl << endl;
    a.show();
    /*
    cout << "Enter a: " << endl; cin >> a; cout << endl;
    cout << "a: " << a << endl << endl;
    
    cout << "b(5,7)";
    pairr b(5,7);
    cout << "b: " << b << endl;
    
    cout << "a = b: " << (a = b) << endl << endl;
    
    cout << "a.first * a.second = " << a.get_product() << endl << endl;
    
    rectangle c;
    cout << "Enter c: " << endl; cin >> c; cout << endl;
    cout << "product (c.first * c.second): " << c.get_product() << endl;
    cout << "area (c.first * c.second): " << c.get_area() << endl;
    cout << "perimeter (c.first * c.second): " << c.get_perimeter() << endl << endl;
    
    cout << "f1(c) (second = 100)" << endl;
    f1(c);
    a = f2();
    cout << "a (10 33): " << a << endl << endl;*/
    return 0;
}

