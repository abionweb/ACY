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

istream& operator>>(istream& in, rectangle& p) {
	cout << "Enter the length of the sides of the rectangle: " << endl;
    cout << "First: "; in >> p.first;
    cout << "Second: "; in >> p.second;
    cout << endl;
    return in;
}

int rectangle::get_area() {
    return first*second;
}
int rectangle::get_perimeter() {
    return first * 2 + second * 2;
}

void rectangle::show() {
	cout << "Width: "     << first           << endl;
	cout << "Height: "    << second          << endl;
	cout << "Perimeter: " << get_perimeter() << endl;
	cout << "Area: "      << get_area()      << endl;
}
