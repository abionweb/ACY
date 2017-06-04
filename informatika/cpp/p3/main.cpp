/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pavel
 *
 * Created on 3 июня 2017 г., 18:13
 */

//#include <cstdlib>
#include <iostream>
#include "Time.h"

using namespace std;

/*
 * 
 */
int main() {
    Time a;
    Time b;
    Time c;
    Time d;
    Time e;
    cout << "Enter a: " << endl; cin >> a; cout << endl;
    cout << "Enter b: " << endl; cin >> b; cout << endl;
    //++a;
    cout << "++a = " << (++a) << endl;
    
    //c = (a++) + b;
    cout << "c = (a++) + b = " << (c = (a++) + b) << endl << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl << endl;
    
    //d = b - a;
    cout << "d = b - a = " << (d = b - a) << endl << endl;
    
    //e = a;
    cout << "e = a = " << (e = a) << endl;
    
    bool boo;
    //boo = (a != e);
    //cout << boo;
    cout << "(a != e) = " << (boo = (a != e)) << endl;
    cout << "(a != d) = " << (boo = (a != d)) << endl;
    return 0;
}