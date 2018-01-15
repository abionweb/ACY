/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rectangle.h
 * Author: pavel
 *
 * Created on 5 июня 2017 г., 3:04
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "pairr.h"

class rectangle : public pairr {
    
public:
    rectangle(void) {first = 0; second = 0;};
    rectangle(int a, int b) {first = a; second = b;};
    rectangle(const rectangle& r) {};
    ~rectangle(void) {};
    
    friend istream& operator>>(istream& in, rectangle& p);

    int get_area();
    int get_perimeter();

    void show();
private:

};

#endif /* RECTANGLE_H */

