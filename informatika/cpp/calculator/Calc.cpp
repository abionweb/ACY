/*
 * calculator.cpp
 *
 *  Created on: 16 но€б. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#include "Calc.h"
#include "Fraction.h"

Calc::Calc() { // @suppress("Class members should be properly initialized")
	action = '+';
	form = '.';
}

Calc::~Calc() {
}

void Calc::set_op1(std::string str) {
	op1.set_value_from_string(str);
}

void Calc::set_op1(Fraction fraction) {
	op1 = fraction;
}

void Calc::set_op2(std::string str) {
	op2.set_value_from_string(str);
}

void Calc::set_action(char c) {
	action = c;
}

void Calc::set_form(char c) {
	form = c;
}

void Calc::execute() {
	switch (action) {
	case '+':
		res = op1 + op2;
		break;
	case '-':
		res = op1 - op2;
		break;
	case '*':
		res = op1 * op2;
		break;
	case '/':
		res = op1 / op2;
		break;
	}
}
