/*
 * vector.h
 *
 *  Created on: 17 ���. 2018 �.
 *      Author: �����
 */

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
using namespace std;

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
private:
	int size;
	int*data;
};



#endif /* VECTOR_H_ */
