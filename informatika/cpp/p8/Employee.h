#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include "Person.h"
using namespace std;

class Employee :
	public Person {
public:
	Employee(void);
	~Employee(void);
	void Show();
	void Input();
	Employee(string, int, float, string);
	Employee(const Employee & );

	float get_pay() {return pay;}
	string get_position() {return position;}

	void set_pay(float);
	void set_position(string);

	Employee& operator=(const Employee&);
protected:
	float pay;
	string position;
};

#endif /* EMPLOYEE_H_ */
