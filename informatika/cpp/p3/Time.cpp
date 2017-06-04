/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Time.cpp
 * Author: pavel
 * 
 * Created on 3 июня 2017 г., 22:21
 */

#include "Time.h"
#include <iostream>
using namespace std;

/*Time::Time() {
}

Time::Time(const Time& orig) {
}

Time::~Time() {
}*/

Time&Time::operator=(const Time &t) {
    if(&t==this) return *this;
    min = t.min;
    sec = t.sec;
    return *this;
}
Time&Time::operator++() {
    int tmp = min * 60 + sec;
    tmp++;
    min = tmp / 60;
    sec = tmp % 60;
    return *this;
}
Time Time::operator++(int) {
    int tmp = min * 60 + sec;
    tmp++;
    Time t(min,sec);
    min = tmp / 60;
    sec = tmp % 60;
    return t;
}
Time Time::operator+(const Time &t) {
    int tmp1 = min * 60 + sec;
    int tmp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (tmp1 + tmp2) / 60;
    p.sec = (tmp1 + tmp2) % 60;
    return p;
}

Time Time::operator-(const Time &t) {
    int tmp1 = min * 60 + sec;
    int tmp2 = t.min * 60 + t.sec;
    Time p;
    p.min = (tmp1 - tmp2) / 60;
    p.sec = (tmp1 - tmp2) % 60;
    return p;
}

bool Time::operator!=(const Time &t) {
    int tmp1 = min * 60 + sec;
    int tmp2 = t.min * 60 + t.sec;
    return (tmp1 != tmp2);
}

istream &operator >> (istream&in, Time&t) {
    cout<<"min: "; in>>t.min;
    cout<<"sec: "; in>>t.sec;
    return in;
}/**/
ostream &operator << (ostream&out, const Time&t) {
    return (out << t.min << ":" << t.sec);
}/**/