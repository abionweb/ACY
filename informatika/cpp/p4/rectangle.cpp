/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rectangle.cpp
 * Author: pavel
 * 
 * Created on 5 июня 2017 г., 3:04
 */

#include "rectangle.h"

int rectangle::get_area() {
    return first*second;
}
int rectangle::get_perimeter() {
    return first * 2 + second * 2;
}