/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.h
 * Author: pavel
 *
 * Created on 3 июня 2017 г., 22:21
 */

#ifndef TIME_H
#define TIME_H

#include <iostream>
using namespace std;

class Time {
    int min, sec;
public:
    Time() {min=0;sec=0;}
    Time(int m, int s) {min=m;sec=s;}
    Time(const Time&t) {min=t.min;sec=t.sec;}
    virtual ~Time(){};
    int get_min(){return min;};
    int get_sec(){return sec;};
    void set_min(int m){min=m;};
    void set_sec(int s){sec=s;};
    
    Time&operator=(const Time&);
    Time&operator++();
    Time operator++(int);
    Time operator+(const Time&);
    Time operator-(const Time&);
    bool operator!=(const Time&);
    
    friend istream& operator>>(istream&in, Time&t);
    friend ostream& operator<<(ostream&out, const Time&t);
private:

};

#endif /* TIME_H */

