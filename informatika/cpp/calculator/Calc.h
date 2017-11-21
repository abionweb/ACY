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
	int action, form;
public:
	Calc();
	virtual ~Calc();

	void set_op1(std::string string);
	void set_op2(std::string string);

	void set_action(int);
	void set_form(int);

	Fraction get_result();

	void execute();
};

#endif /* CALC_H_ */
