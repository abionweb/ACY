/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pavel
 *
 * Created on 22 мая 2017 г., 13:54
 */

#include <cstdlib>
#include <iostream>

using namespace std;

float mult (int count, double k, ...) {
    double *p = &k;
    cout << "\t" << p << "\t" << *p << "\n";
    double s=1;
    cout << "\n";
            
    for (; count!=0; count--) {
        cout << "\t" << ++p;
        cout << "\t" << *p;
        cout << "\n";
    }
    return s;
}

int main() {
    double f1 = 0.1, f2 = 0.2, f3 = 0.3, f4 = 0.4, f5 = 0.5;
    cout << "\nmult(2,4,6)= " << mult(10,f1,f2,f3,f4,f5,f1,f2,f3,f4,f5) << "\n"; //находит сумму 4+6
    //cout << "\nСумма(4,1,2,3,4)=" << mult(4,1,2,3,4) << "\n";//находит сумму 1+2+3+4
    cout << "\n";
    return 0;
}