#ifndef TASK3_H_
#define TASK3_H_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template <class T>
class Task3 {
	vector <T> v;
	int len;
	void print_list();
	void add_minimum_to_end();
	void del_by_key(T key);
	void add_sum_of_min_max();
public:
	Task3(void);
	Task3(int n);
	void show();
	~Task3();
};

template <class T>
Task3<T>::Task3() {
	len = 0;
}

template <class T>
Task3<T>::~Task3(void) {}

template <class T>
Task3<T>::Task3(int n) {
	cout << "Task3" << endl;
	T a;
	for(int i = 0; i < n; i++) {
		cout << "Enter the element #" << ( i + 1 ) << ": "; cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

template <class T>
void Task3<T>::print_list() {
	for(int i = 0; i < len; i++) cout << v[i] << "\t";
	cout << endl;
}

template <class T>
void Task3<T>::add_minimum_to_end() {
	T minimum = v[0];
	for (int i = 0; i < len; i++) {
		if (v[i] < minimum) minimum = v[i];
	}
	v.push_back(minimum); len++;
}

template <class T>
void Task3<T>::del_by_key(T key) {
	int i = 0;
	for(i = 0; i < len; i++) {
		if (v[i] == key) {
			v.erase(v.begin() + i);
			len--;
			break;
		}
	}
}

template <class T>
void Task3<T>::add_sum_of_min_max() {
	T minimum = v[0];
	T maximum = v[0];
	for (int i = 0; i < len; i++) {
		if (v[i] < minimum) minimum = v[i];
		if (v[i] > maximum) maximum = v[i];
	}
	for (int i = 0; i < len; i++) {
		v[i] = v[i] + minimum + maximum;
	}
}

template <class T>
void Task3<T>::show() {
	try {
		print_list();
		add_minimum_to_end();
		print_list();

		T key;
		cout << "Enter key: "; cin >> key;
		del_by_key(key);
		print_list();

		add_sum_of_min_max();
		print_list();
		cout << endl;
	}
	catch(int) {
		cout << "Error";
	}

}

#endif /* Task3_H_ */

