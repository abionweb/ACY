/*
 * calculator.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#ifndef CALC_H_
#define CALC_H_

#include <string>
#include "Fraction.h"

/* класс должен хранить 2 операнда и результат - простые дроби
 * в виде трех числителей (op1_numerator, op2_numerator, result_numerator)
 * и трех знаменателей (op1_denominator, op2_denominator, result_denominator)
 *
 * action знак операции
 * form - код формы для вывода результата
 *
 */
class Calc {
	Fraction op1, op2, res;
	int action, form;
public:
	Calc();
	virtual ~Calc();

	void go(int);
	void set_op1(string string);
	void set_op2(string string);

	void set_action(int);
	void set_form(int);

	Fraction get_result();

	void execute();
};

#endif /* CALC_H_ */
