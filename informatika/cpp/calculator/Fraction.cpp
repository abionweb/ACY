/*
 * Fraction.cpp
 *
 *  Created on: 20 но€б. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#include "Fraction.h"
#include <iostream>
#include <string>

Fraction::Fraction() {
	// TODO Auto-generated constructor stub

}

Fraction::~Fraction() {
	// TODO Auto-generated destructor stub
}

std::istream& operator >> (std::istream& in, Fraction& f) {
	in >> f.str;
	std::cout << f.str;
    //cout << "first: "; in >> p.first;
    //cout << "second: "; in >> p.second;
    return in;
}

std::ostream &operator << (std::ostream& out, const Fraction& f) {
    //return (out << p.first << " " << p.second);
}
