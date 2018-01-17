#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

template <class T>
class vector {
public:
	vector(int s, T k);
	vector(const vector<T>&a);
	~vector();
	vector& operator=(const vector<T>&a);
	T& operator[](int index);
	vector operator+(const T k);
	int operator()();
	friend ostream& operator << <>(ostream& out, const vector<T>&a);
	friend istream& operator >> <>(istream& in, vector<T>&a);
private:
	int size;
	T*data;
};

#endif /* VECTOR_H_ */
