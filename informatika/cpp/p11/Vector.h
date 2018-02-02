#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class Vector {
	queue<T> q;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void Print();
	void add_minimum_to_end();
	void del_by_key(T key);
	void add_sum_of_min_max();
	vector<T> copy_queue_to_vector(queue<T> q);
	queue<T> copy_vector_to_queue(vector<T> v);
};

template <class T>
vector<T> Vector<T>::copy_queue_to_vector(queue<T> q) {
	vector<T> v;
	while(!q.empty()) {
		v.push_back(q.front());
		q.pop();
	}
	return v;
}

template <class T>
queue<T> Vector<T>::copy_vector_to_queue(vector<T> v) {
	queue<T> tmp_q;
	for(int i = 0; i < v.size(); i++) {
		tmp_q.push(v[i]);
	}
	return tmp_q;
}

template <class T>
Vector<T>::Vector() { len = 0; }

template <class T>
Vector<T>::Vector(int n) {
	T a;
	for(int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	len = q.size();
}

template <class T>
void Vector<T>::Print() {
	vector<T> v = copy_queue_to_vector(q);
	while(!q.empty()) {
		cout << q.front() << "\t";
		q.pop();
	}
	cout << endl;
	q = copy_vector_to_queue(v);
}

template <class T>
void Vector<T>::add_minimum_to_end() {
	vector<T> v = copy_queue_to_vector(q);
	T minimum = v[0];
	for (int i = 0; i < len; i++) {
		if (v[i] < minimum) minimum = v[i];
	}
	v.push_back(minimum); len++;
	q = copy_vector_to_queue(v);
}

template <class T>
void Vector<T>::del_by_key(T key) {
	vector<T> v = copy_queue_to_vector(q);
	int i = 0;
	for(i = 0; i < v.size(); i++) {
		if (v[i] == key) {
			v.erase(v.begin() + i);
			break;
		}
	}
	q = copy_vector_to_queue(v);
	len = q.size();
}

template <class T>
void Vector<T>::add_sum_of_min_max() {
	vector<T> v = copy_queue_to_vector(q);
	T minimum = v[0];
	T maximum = v[0];
	for (int i = 0; i < len; i++) {
		if (v[i] < minimum) minimum = v[i];
		if (v[i] > maximum) maximum = v[i];
	}
	for (int i = 0; i < len; i++) {
		v[i] = v[i] + minimum + maximum;
	}
	q = copy_vector_to_queue(v);
}

#endif /* VECTOR_H_ */
