/*
 * Fraction.h
 *
 *  Created on: 20 но€б. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
#include <string>


class Fraction {
public:
	Fraction();
	virtual ~Fraction();

	std::string str;


	friend std::istream& operator>>(std::istream& in, Fraction& p);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& p);
};


#endif /* FRACTION_H_ */
