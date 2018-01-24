#include "Employee.h"

using namespace std;

Employee::Employee(void):Person() {
	pay = 0;
	position = "";
}

Employee::~Employee(void) {
}

Employee::Employee(string n, int a, float p, string pos):Person(n,a) {
	pay = p;
	position = pos;
}

Employee::Employee(const Employee &e) {
	name = e.name;
	age = e.age;
	pay = e.pay;
	position = e.position;
}

void Employee::set_pay(float p) {
	pay = p;
}
void Employee::set_position(string pos) {
	position = pos;
}
Employee& Employee::operator=(const Employee& e) {
	if (&e==this) return *this;
	name = e.name;
	age = e.age;
	pay = e.pay;
	position = e.position;
	return *this;
}

void Employee::Show() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Pay: " << pay << endl;
	cout << "Position: " << position << endl;
}

void Employee::Input() {
	cout << "Enter name: "; cin >> name;
	cout << "Enter age: "; cin >> age;
	cout << "Enter pay: "; cin >> pay;
	cout << "Enter position: "; cin >> position;
}
