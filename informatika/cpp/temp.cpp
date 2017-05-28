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
//#include <stdarg>

using namespace std;

float mult (int count, double k, ...) {
    /*double *p1 = &k;
    cout << "p1: " << p1 << "\n";
    char *p = (char*)(&(p1));*/
    double *p = &k;
    cout <<  "p: " << p << "\n";
    cout <<  "*p: " << *p << "\n";
    //char *p = &k; //настроили указатель на параметр k
    double s=1;
    cout << "\n";
            
    for (; count!=0; count--) {
        //cout << "k:  " << k << "\n";
        cout <<  "p++" << "\n";
        p = p+1;
        cout <<  "p: " << p << "\n";
        cout << "*p: " << *p << "\n";
        s = s * (*p);
        cout << "s: " << s << "\n";
        cout << "\n";
    }
    return s;
}

/*
 * 
 */
int main() {
    float f1 = 0.1, f2 = 0.2, f3 = 0.3, f4 = 0.4, f5 = 0.5;
    cout << "\nmult(2,4,6)= " << mult(10,f1,f2,f3,f4,f5,f1,f2,f3,f4,f5) << "\n"; //находит сумму 4+6
    //cout << "\nСумма(4,1,2,3,4)=" << mult(4,1,2,3,4) << "\n";//находит сумму 1+2+3+4
    cout << "\n";
    return 0;
}