/*
 * calculator.h
 *
 *  Created on: 16 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#ifndef CALC_H_
#define CALC_H_

#include <string>
#include "Fraction.h"

/* ����� ������ ������� 2 �������� � ��������� - ������� �����
 * � ���� ���� ���������� (op1_numerator, op2_numerator, result_numerator)
 * � ���� ������������ (op1_denominator, op2_denominator, result_denominator)
 *
 * action ���� ��������
 * form - ��� ����� ��� ������ ����������
 *
 */
class Calc {
	Fraction op1, op2, res;
	char action, form;
public:
	Calc();
	virtual ~Calc();

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
