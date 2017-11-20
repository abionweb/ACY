/*
 * calculator.h
 *
 *  Created on: 16 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#ifndef CALC_H_
#define CALC_H_
/* ����� ������ ������� 2 �������� � ��������� - ������� �����
 * � ���� ���� ���������� (op1_numerator, op2_numerator, result_numerator)
 * � ���� ������������ (op1_denominator, op2_denominator, result_denominator)
 *
 * action ���� ��������
 * form - ��� ����� ��� ������ ����������
 *
 */
class Calc {
public:
	Calc();
	virtual ~Calc();



	int op1_numerator, op1_denominator,
		op2_numerator, op2_denominator,
		result_numerator, result_denominator,
		action
		;
//	void set_op1(string);
//	void set_op2(string);
	void set_action(int);
	void set_form(int);
	double get_result();
	void execute();
};

#endif /* CALC_H_ */
