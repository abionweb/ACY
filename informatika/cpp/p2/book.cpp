#include <iostream>
#include <string>
#include "book.h"

book::book() {
    title = "";
    group = "";
    average_score = 0;
    cout << "Constructor bez parametrov dlia objecta " << this << endl;
}

book::book(string t, string g, float a) {
    title = t;
    group = g;
    average_score = a;
    cout << "Constructor s parametrami dlia objecta " << this << endl;
}

book::book(const book& orig) {
    title = orig.title;
    group = orig.group;
    average_score = orig.average_score;
    cout << "Constructor copirovaniya dlia objecta " << this << endl;
}

book::~book() {
    cout << "Destructor dlia objecta" << this << endl;
}

string book::get_title() {
    return title;
}

string book::get_group() {
    return group;
}

float book::get_average_score() {
    return average_score;
}

void book::set_title(string t) {
    title = t;
}

void book::set_group(string g) {
    group = g;
}

void book::set_average_score(float a) {
    average_score = a;
}

void book::show() {
    cout << "title: " << title << endl;
    cout << "group: " << group << endl;
    cout << "average_scope: " << average_score << endl;
}