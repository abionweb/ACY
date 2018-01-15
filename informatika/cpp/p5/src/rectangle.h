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

