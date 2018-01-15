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
#include "rectangle.h"

using namespace std;

int main() {
	Object *p;

    pairr a;
    cin >> a;
    p = &a;
    p->show();

    cout << endl << endl;

    rectangle b;
    cin >> b;
    p = &b;
    p->show();
    return 0;
}

