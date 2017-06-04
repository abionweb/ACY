/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pair.cpp
 * Author: pavel
 * 
 * Created on 5 июня 2017 г., 2:15
 */

#include "pairr.h"
#include <iostream>
using namespace std;

pairr& pairr::operator = (const pairr& p) {
    if(&p == this) return *this;
    first = p.first;
    second = p.second;
    return *this;
}

istream& operator >> (istream& in, pairr& p) {
    cout << "first: "; in >> p.first;
    cout << "second: "; in >> p.second;
    return in;
}

ostream &operator << (ostream& out, const pairr& p) {
    return (out << p.first << " " << p.second);
}

int pairr::get_product() {
    return first*second;
}