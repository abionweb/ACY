/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pair.h
 * Author: pavel
 *
 * Created on 5 июня 2017 г., 2:15
 */

#ifndef PAIRR_H
#define PAIRR_H
#pragma once
#include <iostream>
using namespace std;

class pairr {
protected: 
    int first, second;
public:
    pairr() {first=0;second=0;}
    pairr(int f, int s) {first=f;second=s;}
    pairr(const pairr &p) {first=p.first;second=p.second;}
    virtual ~pairr(void){}
    int get_first(){return first;}
    int get_second(){return second;}
    int set_first(int f) {first=f; return first;}
    int set_second(int s) {second=s; return second;}
    pairr& operator=(const pairr&);
    
    friend istream& operator>>(istream& in, pairr& p);
    friend ostream& operator<<(ostream& out, const pairr& p);
    
    int get_product();
private:

};

#endif /* PAIRR_H */

