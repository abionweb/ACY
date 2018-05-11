#ifndef CALC_H_
#define CALC_H_
using namespace std;

#include <string>
#include "Fraction.h"
#include "Protocol.h"

class Calc {
	Fraction op1, op2, res;
	char action, form;
public:
	Calc(void);
	virtual ~Calc(void);

	Protocol p;
	void undoLastEntry();

	void set_op1(std::string str);
	void set_op1(Fraction fraction);
	void set_op2(std::string str);
	void set_action(char c);
	void set_form(char c);

	Fraction get_op1() { return op1; };
	char get_action()  { return action; };
	Fraction get_op2() { return op2; };
	char get_form()    { return form; };

	std::string get_result_string();
	Fraction get_result_fraction();

	void print_protocol();
	void execute();
};

#endif /* CALC_H_ */
