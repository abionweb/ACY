#ifndef TASK1_H_
#define TASK1_H_

#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef set<float> T1_set;
T1_set::iterator T1_it;

T1_set make_set(int n) {
	srand( time(0) );
	T1_set s;
	float a;
	for(int i = 0; i < n; i++) {
		a = (rand()%100);
		a = a / 10;
		s.insert(a);
	}
	return s;
}

void print_set(T1_set s) {
	for(T1_it = s.begin(); T1_it != s.end(); T1_it++) cout << *T1_it << "\t";
	cout << endl;
}

T1_set add_minimum_to_end(T1_set s) {
	T1_it = s.begin();
	float minimum = *T1_it;
	for(T1_it = s.begin(); T1_it != s.end(); T1_it++) {
		if ( *T1_it < minimum ) minimum = *T1_it;
	}
	s.insert(minimum - 1);
	return s;
}

T1_set del_by_key(T1_set s, float key) {
	s.erase(key);
	return s;
}

T1_set add_sum_of_min_max(T1_set s) {
	T1_set temp;
	T1_it = s.begin();
	float minimum = *T1_it;
	float maximum = *T1_it;
	for(T1_it = s.begin(); T1_it != s.end(); T1_it++) {
		if ( *T1_it < minimum ) minimum = *T1_it;
		if ( *T1_it > maximum ) maximum = *T1_it;
	}
	for(T1_it = s.begin(); T1_it != s.end(); T1_it++) {
		temp.insert( *T1_it + minimum + maximum );
	}
	return temp;
}

void Task1() {
	int n;
	cout << "Enter the number of items: "; cin >> n;
	T1_set s = make_set(n);
	print_set(s);

	cout << endl << "3) Add a minimum value to the end" << endl;
	s = add_minimum_to_end(s);
	print_set(s);

	float key;
	cout << endl << "4) Remove an element by key. Enter key: "; cin >> key;
	s = del_by_key(s, key);
	print_set(s);

	cout << endl << "5) Adding the sum of the minimum and maximum elements in each." << endl;
	s = add_sum_of_min_max(s);
	print_set(s);
}


#endif /* TASK1_H_ */
