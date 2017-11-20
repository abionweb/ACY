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

	cout << endl << "Пожалуйста, введите первое число: ";
	cin >> op1;
	cout << endl << "Пожалуйста, введите второе число: ";
	cin >> op2;
	cout << endl << "Пожалуйста, введите символ операции ( + - * / ): ";
	cin >> op3;
	cout << endl << "Пожалуйста, введите символ представления результата ( . / ): ";
	cin >> op4;
	cout << endl << "Конец";
	return 0;
}
