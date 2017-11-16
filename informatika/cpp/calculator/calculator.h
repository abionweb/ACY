/*
 * calculator.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_
/* класс должен хранить 2 операнда и результат - простые дроби
 * в виде трех числителей (op1_numerator, op2_numerator, result_numerator)
 * и трех знаменателей (op1_denominator, op2_denominator, result_denominator)
 *
 * action знак операции
 * form - код формы для вывода результата
 *
 */
class calculator {
public:
	calculator();
	virtual ~calculator();



	int op1_numerator, op1_denominator,
		op2_numerator, op2_denominator,
		result_numerator, result_denominator,
		action,
		;
	void set_op1(string);
	void set_op2(string);
	void set_action(int);
	void set_form(int);
	double get_result();
	void execute();
};

#endif /* CALCULATOR_H_ */
