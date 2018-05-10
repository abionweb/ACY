/*
 * calculator.h
 *
 *  Created on: 16 но€б. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#ifndef CALC_H_
#define CALC_H_

#include <string>
#include "Fraction.h"
#include "Protocol.h"

class Calc {
	Fraction op1, op2, res;
	char action, form;
public:
	Calc();
	virtual ~Calc();

	Protocol p;

	void set_op1(std::string str);
	void set_op1(Fraction fraction);
	void set_op2(std::string str);
	void set_action(char c);
	void set_form(char c);

	Fraction get_op1() { return op1; };
	char get_action()  { return action; };
	Fraction get_op2() { return op2; };
	char get_form()    { return form; };

	Fraction get_result() { return res; };

	void execute();
};

#endif /* CALC_H_ */
