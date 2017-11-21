/*
 * Fraction.h
 *
 *  Created on: 20 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <string>
using namespace std;

class Fraction {
public:
	Fraction() {};
	virtual ~Fraction() {};

	float fract;

	void set_value_from_string(std::string fraction_string);

	friend std::istream& operator>>(std::istream& in, Fraction& p);
	friend std::ostream& operator<<(std::ostream& out, const Fraction& p);
};


#endif /* FRACTION_H_ */
