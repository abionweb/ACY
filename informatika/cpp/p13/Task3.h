#include "Time.h"
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef multiset<Time> Multiset_time;
//typedef vector<Time> Vector_time;
Multiset_time::iterator T3_it;

Multiset_time make_multiset(int n) {
	srand( time(0) );
	Multiset_time m;
	for (int i = 0; i < n; i++) {
		Time t(rand()%60, rand()%60);
		m.insert(t);
	}
	return m;
}

void print_multiset(Multiset_time m) {
	for(T3_it = m.begin(); T3_it != m.end(); T3_it++) {
		cout << *T3_it << "\t";
	}
	cout << endl;
}
/*
Vector_time copy_queue_to_vector(Queue_time q) {
	Vector_time v;
	while(!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

Queue_time copy_vector_to_queue(Vector_time v) {
	Queue_time q;
	for (int i = 0; i <v.size() ; i++) {
		q.push(v[i]);
	}
	return q;
}
*/
void Task3() {
	int n;
	cout << "Task3" << endl;
	cout << "Enter the number of items: "; cin >> n;
	Multiset_time m;
	m = make_multiset(n);
	print_multiset(m);

	cout << endl << "3) Add a minimum value to the end" << endl;
	T3_it = m.begin();
	m.insert(*T3_it);
	print_multiset(m);

	Time key;
	cout << endl << "4) Remove an element by key. Enter key: "; cin >> key;
	m.erase(key);
	print_multiset(m);

	cout << endl << "5) Adding the sum of the minimum and maximum elements in each." << endl;
	T3_it = m.begin();
	minimum = *T3_it;
	T3_it = m.end();
	maximum = *(--T3_it);
	Multiset_time tmp_m;
	for(T3_it = m.begin(); T3_it != m.end(); T3_it++) {
		Time n = *T3_it;
		n = n + maximum + minimum;
		tmp_m.insert(n);
	}
	m = tmp_m;
	print_multiset(m);


	cout << endl << "Sort ASC" << endl;
	print_multiset(m);
}

