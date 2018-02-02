#ifndef TASK1_H_
#define TASK1_H_

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef list<float> List_float;

class Task1 {

List_float make_list(int n);
void print_list(List_float l);
List_float add_minimum_to_end(List_float l);
List_float del_by_key(List_float l, float key);
List_float add_sum_of_min_max(List_float l);

public:
	Task1();
	~Task1();
	void show();
};

Task1::Task1() {
}

Task1::~Task1() {
}

List_float Task1::make_list(int n) {
	srand( time(0) );
	List_float l;
	for(int i = 0; i < n; i++) {
		float a = (rand()%100);
		a = a / 10;
		l.push_back(a);
	}
	return l;
}

void Task1::print_list(List_float l) {
	for ( List_float::iterator li = l.begin(); li != l.end(); ++li ) cout << *li << "\t";
	cout << endl;
}

List_float Task1::add_minimum_to_end(List_float l) {
	float minimum = *(l.begin());
	for ( List_float::iterator li = l.begin(); li != l.end(); ++li ) {
		if (*li < minimum) minimum = *li;
	}
	l.push_back(minimum);
	return l;
}

List_float Task1::del_by_key(List_float l, float key) {
	List_float::iterator li = l.begin();
	while ((*li != key ) and (li != l.end())) li++;
	if ((*li==key)) {
		l.erase(li);
	}
	return l;
}

List_float Task1::add_sum_of_min_max(List_float l) {
	float minimum = *(l.begin());
	float maximum = *(l.begin());
	for ( List_float::iterator li = l.begin(); li != l.end(); ++li ) {
		if (*li < minimum) minimum = *li;
		if (*li > maximum) maximum = *li;
	}
	for ( List_float::iterator li = l.begin(); li != l.end(); ++li ) {
		*li += minimum + maximum;
	}
	return l;
}

void Task1::show() {
	try {
		List_float l;
		int n;
		cout << "Task1" << endl;
		cout << "Enter the number of items: "; cin >> n;
		l = make_list(n);
		print_list(l);

		l = add_minimum_to_end(l);
		print_list(l);

		float key;
		cout << "Enter key: "; cin >> key;
		l = del_by_key(l, key);
		print_list(l);

		l = add_sum_of_min_max(l);
		print_list(l);
		cout << endl;
	}
	catch(int) {
		cout << "Error";
	}
}


#endif /* TASK1_H_ */
