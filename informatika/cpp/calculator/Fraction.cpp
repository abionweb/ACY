/*
 * Fraction.cpp
 *
 *  Created on: 20 нояб. 2017 г.
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
	std::string::size_type slash_position, dot_position, comma_position;
	std::string fraction_string;

	in >> fraction_string; //f.str;
	slash_position = fraction_string.find('/');
	dot_position   = fraction_string.find('.');
	comma_position = fraction_string.find(',');

	switch ( std::string::npos ) {
		case slash_position:
			// переводим в double
		case dot_position:
			// переводим в double
		case comma_position:
			// переводим в double
	}

	std::cout << fraction_string;
	return in;
}

std::ostream &operator << (std::ostream& out, const Fraction& f) {
	return out;
    //return (out << p.first << " " << p.second);
}
