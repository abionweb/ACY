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
using namespace std;

int main() {
	Fraction op1, op2;
	char op3, op4;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	cout << endl << "����������, ������� ������ �����: ";
	cin >> op1;
	cout << endl << "����������, ������� ������ �����: ";
	cin >> op2;
	cout << endl << "����������, ������� ������ �������� ( + - * / ): ";
	cin >> op3;
	cout << endl << "����������, ������� ������ ������������� ���������� ( . / ): ";
	cin >> op4;
	cout << endl << "�����";
	return 0;
}
