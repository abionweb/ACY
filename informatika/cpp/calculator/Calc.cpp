#include "Calc.h"
#include "Fraction.h"

Calc::Calc() {
	action = '+';
	form = '.';
}

Calc::~Calc() {
}

void Calc::set_op1(std::string str) {
	p.addRecord('1', op1.get_fract(), str);
	op1.set_value_from_string(str);
}

void Calc::set_op1(Fraction fraction) {
	float old_v;
	old_v = op1.get_fract();
	op1 = fraction;
	p.addRecord('1', old_v, op1.get_fract());
}

void Calc::set_op2(std::string str) {
	p.addRecord('2', op2.get_fract(), str);
	op2.set_value_from_string(str);
}

void Calc::set_action(char c) {
	p.addRecord('a', action, c);
	action = c;
}

void Calc::set_form(char c) {
	p.addRecord('a', form, c);
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
