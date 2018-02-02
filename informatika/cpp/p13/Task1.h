#include "time.h"
#include "list"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef list<Time> List_time;
List_time::iterator it;
Time s;
Time minimum;
Time maximum;

struct Greater_s {
	bool operator()(Time t) {
		if (t>s) return true; else return false;
	}
};

struct Equal_s {
	bool operator()(Time t) {
		return (t==s); }
};

struct Comp_less {
public:
	bool operator()(Time t1, Time t2) {
		if(t1>t2) return true;
		else return false;
	}
};

List_time make_list(int n) {
	srand( time(0) );
	Time a;
	List_time l;
	for(int i = 0; i < n; i++) {
		Time a(rand()%60, rand()%60);
		l.push_back(a);
	}
	return l;
}

void print_list(List_time l) {
	for(it = l.begin(); it != l.end(); ++it) cout << *it << "\t";
	cout << endl;
}

void add_sum_of_min_max(Time& t) {
	t = t + minimum + maximum;
}

void Task1() {
	int n;
	cout << "Task1" << endl;
	cout << "Enter the number of items: "; cin >> n;
	List_time l = make_list(n);
	print_list(l);

	cout << endl << "3) Add a minimum value to the end" << endl;
	it = min_element(l.begin(), l.end());
	l.push_back(*it);
	print_list(l);

	Time key;
	cout << endl << "4) Remove an element by key. Enter key: "; cin >> key;
	s = key;
	it = remove_if(l.begin(), l.end(), Equal_s());
	l.erase(it,l.end());
	print_list(l);

	cout << endl << "5) Adding the sum of the minimum and maximum elements in each." << endl;
	it = min_element(l.begin(), l.end());
	minimum = *it;
	it = max_element(l.begin(), l.end());
	maximum = *it;
	for_each(l.begin(), l.end(), add_sum_of_min_max);
	print_list(l);

	cout << endl << "Sort ASC" << endl;
	l.sort();
	print_list(l);
	cout << endl << "Sort ASC" << endl;
	l.sort(greater<Time>());
	print_list(l);
}
