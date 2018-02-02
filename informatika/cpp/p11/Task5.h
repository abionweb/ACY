#ifndef TASK5_H_
#define TASK5_H_

#include <iostream>
#include <cstdlib>
#include "Time.h"
#include <queue>
#include <vector>
#include "Vector.h"



using namespace std;

class Task5 {
public:
	Task5(void);
	Task5(int n);
	void show();
	~Task5();
};

Task5::Task5() {}

Task5::~Task5(void) {}

void Task5::show() {
	try {
		cout << "Task5" << endl;
		Vector <Time> v(3);
		v.Print();
		v.add_minimum_to_end();
		v.Print();

		Time key;
		cout << "Enter key: "; cin >> key;
		v.del_by_key(key);
		v.Print();

		v.add_sum_of_min_max();
		v.Print();
		cout << endl;
	}
	catch(int) {
		cout << "Error";
	}

}

#endif /* TASK5_H_ */

