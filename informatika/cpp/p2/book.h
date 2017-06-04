/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   book.h
 * Author: pavel
 *
 * Created on 29 мая 2017 г., 23:58
 */

#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

using namespace std;

class book {
    string title;
    string group;
    float average_score;
    
public:
    book();
    book(string, string, float);
    book(const book&);
    //virtual ~book();
    ~book();
    string get_title();
    string get_group();
    float get_average_score();
    void set_title(string);
    void set_group(string);
    void set_average_score(float);
    void show();
private:

};

#endif /* BOOK_H */

