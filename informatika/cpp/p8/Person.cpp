#include "Person.h"

using namespace std;

Person::Person(void) {
	name = "";
	age = 0;
}

Person::~Person(void) {
}

Person::Person(string n, int a) {
	name = n;
	age = a;
}

Person::Person(const Person& p) {
	name = p.name;
	age = p.age;
}

void Person::set_name(string n) {
	name = n;
}

void Person::set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person&p) {
	if (&p==this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

void Person::Show() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
}

void Person::Input() {
	cout << "Enter name: "; cin >> name;
	cout << "Enter age: "; cin >> age;
}

void Person::HandleEvent(const TEvent& e) {
	if (e.what==evMessage) {
		switch (e.command) {
		case cmGet:
			cout << "age=" << get_age() << endl; break;
		case cmGetName:
			cout << "name=" << get_name() << endl; break;
		}
	}
}
