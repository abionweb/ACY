#ifndef TASK4_H_
#define TASK4_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Time.h"
#include <queue>
#include <vector>

using namespace std;

typedef queue<Time> Queue_time;
typedef vector<Time> Vector_time;

class Task4 {
Queue_time make_queue(int n);
Vector_time copy_queue_to_vector(Queue_time q);
Queue_time copy_vector_to_queue(Vector_time v);
void print_queue(Queue_time q);
Queue_time add_minimum_to_end(Queue_time q);
Queue_time del_by_key(Queue_time l, Time key);
Queue_time add_sum_of_min_max(Queue_time q);
public:
	Task4();
	~Task4();
	void show();
};

Task4::Task4() {
}

Task4::~Task4() {
}

Queue_time Task4::make_queue(int n) {
	srand( time(0) );
	Queue_time q;
	for(int i = 0; i < n; i++) {
		Time t(rand()%60, rand()%60);
		q.push(t);
	}
	return q;
}

void Task4::print_queue(Queue_time q) {
	Queue_time tmp_q = q;
	Time q_element;
	while(!tmp_q.empty()) {
		q_element = tmp_q.front();
		cout << q_element << "\t";
		tmp_q.pop();
	}
	cout << endl;
}

Vector_time Task4::copy_queue_to_vector(Queue_time q) {
	Vector_time v;
	while(!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

Queue_time Task4::copy_vector_to_queue(Vector_time v) {
	Queue_time q;
	for (int i = 0; i <v.size() ; i++) {
		q.push(v[i]);
	}
	return q;
}
Queue_time Task4::add_minimum_to_end(Queue_time q) {
	Vector_time v = copy_queue_to_vector(q);
	Time minimum = v[0];
	for(int i = 0; i < v.size(); i++) {
		if (v[i] < minimum) minimum = v[i];
	}
	v.push_back(minimum);
	Queue_time tmp_q = copy_vector_to_queue(v);
	return tmp_q;
}

Queue_time Task4::del_by_key(Queue_time q, Time key) {
	Vector_time v = copy_queue_to_vector(q);
	for (int i = 0; i < v.size(); i++) {
		if ((v[i]==key)) {
			v.erase(v.begin()+i);
		}
	}
	Queue_time tmp_q = copy_vector_to_queue(v);
	return tmp_q;
}

Queue_time Task4::add_sum_of_min_max(Queue_time q) {
	Vector_time v = copy_queue_to_vector(q);
	Time minimum = v[0];
	Time maximum = v[0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < minimum) minimum = v[i];
		if (v[i] > maximum) maximum = v[i];
	}
	for (int i = 0; i < v.size(); i++) {
		v[i] = v[i] + minimum + maximum;
	}
	Queue_time tmp_q = copy_vector_to_queue(v);
	return tmp_q;
}

void Task4::show() {
	try {
		cout << "Task4" << endl;
		int n;
		cout << "Enter the number of items: "; cin >> n;
		Queue_time q;
		q = make_queue(n);
		print_queue(q);

		q = add_minimum_to_end(q);
		print_queue(q);

		Time key;
		cout << "Enter key: "; cin >> key;
		q = del_by_key(q, key);
		print_queue(q);

		q = add_sum_of_min_max(q);
		print_queue(q);
		cout << endl;
	}
	catch(int) {
		cout << "Error";
	}
}

#endif /* TASK4_H_ */
