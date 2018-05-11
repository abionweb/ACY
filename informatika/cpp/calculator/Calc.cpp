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
	p.addRecord('f', form, c);
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

void Calc::undoLastEntry() {
	ProtocolRecord r;
	r = p.get_last_record();
	cout << "Отменяю: " << r << endl;
	char code;
	switch (r.mod_attr) {
	case '1':
		op1.set_value_from_string(r.old_value);
		break;
	case '2':
		op2.set_value_from_string(r.old_value);
		break;
	case 'a':
		code = r.old_value[0];
		action = code;
		break;
	case 'f':
		code = r.old_value[0];
		form = code;
		break;
	}
}

void Calc::print_protocol() {
	p.print_protocol();
}

Fraction Calc::get_result_fraction() {
	return res;
}

std::string Calc::get_result_string() {
	switch (form) {
	case '.': {
		std::string str = std::to_string(res.get_fract());
		return str;
		break;
	}
	case '/':
		return res.get_fraction_string();
		break;
	}
}
