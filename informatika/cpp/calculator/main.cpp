//============================================================================
// Name        : main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Calculator
//============================================================================

#include <iostream>
#include <string>
#include "Fraction.h"
#include "Calc.h"
using namespace std;

int main() {
	Calc c;
	string op1, op2;
	char op3, op4;

	cout.precision(7);

	cout << endl << "����������, ������� ������ �����: ";
	cin >> op1;
	c->set_op1(op1);

	cout << endl << "����������, ������� ������ �����: ";
	cin >> op2;
	c->set_op2(op2);

	cout << endl << "����������, ������� ������ �������� ( + - * / ): ";
	cin >> op3;
	cout << endl << "����������, ������� ������ ������������� ���������� ( . / ): ";
	cin >> op4;
	cout << endl << "�����";

	/*exit(0);*/
	return 0;
}
