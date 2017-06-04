/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: pavel
 *
 * Created on 28 мая 2017 г., 3:46
 */

#include <cstdlib>
#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int denomination, int count) {
    fraction temp;
    temp.Init(denomination, count);
    return temp;
}

int main(int argc, char** argv) {
    const int n = 3;
    fraction A, B, *C, D[n], *E = new fraction[n], F;
    
    if (!A.Init(50, 10)) {
        A.Show();
        cout << "summa: " << A.summa() << "\n\n\n";
    }
    
    if (!B.Read()) {
        cout << "summa: " << B.summa() << "\n\n\n";
    }
    
    C = new fraction;
    if (!C->Init(1000, 25)) {
        C->Show();
        cout << "summa: " << C->summa() << "\n\n\n";
    };
    
    cout << "fraction[3]\n";
    for (int i = 0; i < n; i++) {
        if (!D[i].Read()) {
            cout << "summa: " << D[i].summa() << "\n\n\n";
        }
    }
    
    cout << "new fraction[3]\n";
    for (int i = 0; i < n; i++) {
        if (!E[i].Read()) {
            cout << "summa: " << E[i].summa() << "\n\n\n";
        }
    }
    delete[] E;
    
    cout << "make_fraction";
    int denomination, count;
    cout << "Enter denomination: "; cin >> denomination;
    cout << "Enter count: "; cin >> count;
    F = make_fraction(denomination, count);
    cout << "summa: " << F.summa() << "\n\n\n";
    return 0;
}

