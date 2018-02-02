#ifndef TASK2_H_
#define TASK2_H_

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Time.h"

using namespace std;

typedef list<Time> List_time;

class Task2 {

List_time make_list(int n);
void print_list(List_time l);
List_time add_minimum_to_end(List_time l);
List_time del_by_key(List_time l, Time key);
List_time add_sum_of_min_max(List_time l);

public:
	Task2();
	~Task2();
	void show();
};

Task2::Task2() {
}

Task2::~Task2() {
}

List_time Task2::make_list(int n) {
	srand( time(0) );
	List_time l;
	for(int i = 0; i < n; i++) {

		Time a(rand()%60, rand()%60);
		l.push_back(a);
	}
	return l;
}

void Task2::print_list(List_time l) {
	for ( List_time::iterator li = l.begin(); li != l.end(); ++li ) cout << *li << "\t";
	cout << endl;
}

List_time Task2::add_minimum_to_end(List_time l) {
	Time minimum = *(l.begin());
	for ( List_time::iterator li = l.begin(); li != l.end(); ++li ) {
		if (*li < minimum) minimum = *li;
	}
	l.push_back(minimum);
	return l;
}

List_time Task2::del_by_key(List_time l, Time key) {
	List_time::iterator li = l.begin();
	while ((*li != key ) and (li != l.end())) li++;
	if ((*li==key)) {
		l.erase(li);
	}
	return l;
}

List_time Task2::add_sum_of_min_max(List_time l) {
	Time minimum = *(l.begin());
	Time maximum = *(l.begin());
	for ( List_time::iterator li = l.begin(); li != l.end(); ++li ) {
		if (*li < minimum) minimum = *li;
		if (*li > maximum) maximum = *li;
	}
	for ( List_time::iterator li = l.begin(); li != l.end(); ++li ) {
		*li = *li + minimum + maximum;
	}
	return l;
}

void Task2::show() {
	try {
		cout << "Task2" << endl;
		int n;
		cout << "Enter the number of items: " << endl; cin >> n;
		List_time l;
		l = make_list(n);
		print_list(l);

		l = add_minimum_to_end(l);
		print_list(l);

		Time key;
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

#endif /* TASK2_H_ */
