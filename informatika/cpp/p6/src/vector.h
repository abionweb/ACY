/*
 * vector.h
 *
 *  Created on: 17 янв. 2018 г.
 *      Author: Павел
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
using namespace std;

class Iterator {
	friend class vector;
public:
	Iterator() {elem = 0;};
	Iterator(const Iterator&it) { elem = it.elem; };
	bool operator==(const Iterator&it) { return elem == it.elem; };
	bool operator!=(const Iterator&it) { return elem != it.elem; };
	void operator++() { ++elem; };
	void operator--() { --elem; };
	int& operator *() const { return *elem; };
	void operator+(int n) { for (int i = 0; i<n; i++){ ++elem; }};
private:
	int*elem;
};

class vector {
public:
	vector(int s, int k=0);
	vector(const vector&a);
	~vector();
	vector&operator=(const vector&a);
	int&operator[](int index);
	vector operator+(const int k);
	vector operator+(const vector&a);
	int operator () ();
	friend ostream& operator<<(ostream& out, const vector&a);
	friend istream& operator>>(istream& in, vector&a);
	Iterator first() { return beg; };
	Iterator last() { return end; };
private:
	int size;
	int*data;
	Iterator beg;
	Iterator end;
};



#endif /* VECTOR_H_ */
