#include "time.h"
#include "list"
#include <iostream>

using namespace std;

typedef list<Time> List_time;
List_time::iterator it;

List_time make_list(int n) {
	Time a;
	List_time l;
	for(int i = 0; i < n; i++) {
		cout << "Enter element #" << i+1;
		cin >> a;
		l.push_back(a);
	}
	return l;
}

void print_list(List_time l) {
	for(it = l.begin(); it != l.end(); ++it) cout << *it << "\t";
	cout << endl;
}

void Task1() {
	int n;
	cout << "Enter the number of items: "; cin >> n;
	List_time l = make_list(n);
	print_list(l);
}
