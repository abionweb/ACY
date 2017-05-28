/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fraction.cpp
 * Author: pavel
 * 
 * Created on 28 мая 2017 г., 3:49
 */

#include "fraction.h"
#include <iostream>

using namespace std;

int fraction::Init(int denomination, int count) {
    switch (denomination) {
        case 1:
        case 2:
        case 5:
        case 10:
        case 50:
        case 100:
        case 500:
        case 1000:            
        case 5000:            
            first = denomination;
            second = count;
            break;
        default:
            cout << "\nThis denomination does not exist!\n";
            return 1;
    }
    return 0;
}
int fraction::Read() {
    int denomination;
    cout << "Enter denomination: "; cin >> denomination;
    switch (denomination) {
        case 1:
        case 2:
        case 5:
        case 10:
        case 50:
        case 100:
        case 500:
        case 1000:            
        case 5000:
            first = denomination;
            cout << "Enter count: "; cin >> second;
            break;
        default:
            cout << "\nThis denomination does not exist!\n";
            return 1;
    }
    return 0;
}
void fraction::Show() {
    cout << "Denomination: " << first << '\n';
    cout << "Count: " << second << '\n';
}
int fraction::summa() {
    return first * second;
}


/*fraction::fraction() {
}

fraction::fraction(const fraction& orig) {
}

fraction::~fraction() {
}

*/