#include "Time.h"
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef queue<Time> Queue_time;
typedef vector<Time> Vector_time;
Vector_time::iterator T2_it;

Queue_time make_queue(int n) {
	srand( time(0) );
	Queue_time q;
	for(int i = 0; i < n; i++) {
		Time t(rand()%60, rand()%60);
		q.push(t);
	}
	return q;
}

void print_queue(Queue_time q) {
	Queue_time tmp_q = q;
	Time q_element;
	while(!tmp_q.empty()) {
		q_element = tmp_q.front();
		cout << q_element << "\t";
		tmp_q.pop();
	}
	cout << endl;
}

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

void Task2() {
	int n;
	cout << "Task2" << endl;
	cout << "Enter the number of items: "; cin >> n;
	Queue_time q;
	q = make_queue(n);
	print_queue(q);


	Vector_time v;
	cout << endl << "3) Add a minimum value to the end" << endl;
	v = copy_queue_to_vector(q);
	T2_it = min_element(v.begin(), v.end());
	v.push_back(*T2_it);
	q = copy_vector_to_queue(v);
	print_queue(q);


	Time key;
	cout << endl << "4) Remove an element by key. Enter key: "; cin >> key;
	s = key;
	v = copy_queue_to_vector(q);
	T2_it = remove_if(v.begin(), v.end(), Equal_s());
	v.erase(T2_it,v.end());
	q = copy_vector_to_queue(v);
	print_queue(q);

	cout << endl << "5) Adding the sum of the minimum and maximum elements in each." << endl;
	v = copy_queue_to_vector(q);
	T2_it = min_element(v.begin(), v.end());
	minimum = *T2_it;
	T2_it = max_element(v.begin(), v.end());
	maximum = *T2_it;
	for_each(v.begin(), v.end(), add_sum_of_min_max);
	q = copy_vector_to_queue(v);
	print_queue(q);

	v = copy_queue_to_vector(q);
	cout << endl << "Sort ASC" << endl;
	sort(v.begin(),v.end());
	q = copy_vector_to_queue(v);
	print_queue(q);
	cout << endl << "Sort DESC" << endl;
	sort(v.begin(),v.end(), Comp_less());
	q = copy_vector_to_queue(v);
	print_queue(q);
}

