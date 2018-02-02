#ifndef TASK2_H_
#define TASK2_H_

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include "Time.h"

using namespace std;

typedef set<Time> T2_set;
T2_set::iterator T2_it;

T2_set T2_make_set(int n) {
	srand( time(0) );
	T2_set s;
	Time a;
	for(int i = 0; i < n; i++) {
		Time a(rand()%60, rand()%60);
		s.insert(a);
	}
	return s;
}

void T2_print_set(T2_set s) {
	for(T2_it = s.begin(); T2_it != s.end(); T2_it++) cout << *T2_it << "\t";
	cout << endl;
}

T2_set T2_add_minimum_to_end(T2_set s) {
	T2_it = s.begin();
	Time minimum = *T2_it;
	Time delta(0,30);
	for(T2_it = s.begin(); T2_it != s.end(); T2_it++) {
		Time tmp = *T2_it;
		if ( tmp < minimum ) minimum = tmp;
	}
	s.insert(minimum - delta);
	return s;
}

T2_set T2_del_by_key(T2_set s, Time key) {
	s.erase(key);
	return s;
}

T2_set T2_add_sum_of_min_max(T2_set s) {
	T2_set temp;
	T2_it = s.begin();
	Time minimum = *T2_it;
	Time maximum = *T2_it;
	Time tmp;
	for(T2_it = s.begin(); T2_it != s.end(); T2_it++) {
		tmp = *T2_it;
		if ( tmp < minimum ) minimum = tmp;
		if ( tmp > maximum ) maximum = tmp;
	}
	for(T2_it = s.begin(); T2_it != s.end(); T2_it++) {
		tmp = *T2_it;
		tmp = tmp + minimum + maximum;
		temp.insert( tmp );
	}
	return temp;
}

void Task2() {
	int n;
	cout << "Enter the number of items: "; cin >> n;
	T2_set s = T2_make_set(n);
	T2_print_set(s);

	cout << endl << "3) Add a minimum value to the end" << endl;
	s = T2_add_minimum_to_end(s);
	T2_print_set(s);

	Time key;
	cout << endl << "4) Remove an element by key. Enter key: "; cin >> key;
	s = T2_del_by_key(s, key);
	T2_print_set(s);

	cout << endl << "5) Adding the sum of the minimum and maximum elements in each." << endl;
	s = T2_add_sum_of_min_max(s);
	T2_print_set(s);
}


#endif /* TASK2_H_ */
