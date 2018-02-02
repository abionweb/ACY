#ifndef PAIRR_H
#define PAIRR_H

#include "object.h"
#include <iostream>
using namespace std;

class pairr:
	public Object
{
protected: 
    int first, second;
public:
    pairr() {first=0;second=0;}
    pairr(int f, int s) {first=f;second=s;}
    pairr(const pairr &p) {first=p.first;second=p.second;}
    virtual ~pairr(void){}
    void show();
    int get_first(){return first;}
    int get_second(){return second;}
    int set_first(int f) {first=f; return first;}
    int set_second(int s) {second=s; return second;}

    pairr& operator=(const pairr&);
    friend istream& operator>>(istream& in, pairr& p);
    friend ostream& operator<<(ostream& out, const pairr& p);

    int get_product(void);

#endif /* PAIRR_H */
