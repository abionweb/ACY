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
    double *p = &k, s=1;
    for (; count!=0; count--) s = s * (*(p++));
    return s;
}

int main() {
    double f1 = 0.1, f2 = 0.2, f3 = 0.3, f4 = 0.4, f5 = 0.5;
    cout << "\nmult(3, 3.2, 0.4, 2)= " << mult(3, 3.2, 0.4, 2.0) << "\n";
    cout << "\nmult(7, 3.2, 0.4, 2.0, 8.3, 0.2, 100.0, 0.001)= " << mult(7, 3.2, 0.4, 2.0, 8.3, 0.2, 100.0, 0.001) << "\n";
    cout << "\nmult(11, 3.2, 0.4, 2.0, 8.3, 0.2, 100.0, 0.001, 3.2, 1.1, 1.001, 9.2)= " << mult(11, 3.2, 0.4, 2.0, 8.3, 0.2, 100.0, 0.001, 3.2, 1.1, 1.001, 9.2) << "\n";
    cout << "\n";
    return 0;
}