#include "Vector3.h"
#include "Error3.h"
#include <iostream>

using namespace std;

Vector3::Vector3(int s) {
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int [s];
	for (int i = 0; i < size; i++ ) beg[i] = 0;
}

Vector3::Vector3(const Vector3 &v) {
	size = v.size;
	beg = new int [size];
	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

Vector3::~Vector3() {
	if (beg!=0) delete []beg;
}

Vector3::Vector3(int s, int *mas) {
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	beg = new int[size];
	for(int i = 0; i < size; i++) beg[i] = mas[i];
}

const Vector3& Vector3::operator =(const Vector3 &v) {
	if (this == &v) return *this;
	if (beg!=0) delete []beg;
	size = v.size;
	beg = new int [size];
	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
	return *this;
}

ostream& operator<<(ostream& out, const Vector3& v) {
	if (v.size == 0) out << "Empty" << endl;
	else {
		for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Vector3& v) {
	for (int i = 0; i < v.size; i++) {
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}

int Vector3::operator [](int i) {
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return beg[i];
}

int Vector3::operator ()() {
	return size;
}
/*
Vector3 Vector3::operator +(int a) {
	if (size + 1 == MAX_SIZE) MaxSizeError();
	Vector3 temp(size+1, beg);
	temp.beg[size] = a;
	return temp;
}*/


Vector3 Vector3::operator +(int n) {
	if (size + n >= MAX_SIZE) throw MaxSizeError();
	Vector3 temp(size + n, beg);
	for (int i = size; i < (size + n); i++) temp.beg[i] = 0;
	return temp;
}

Vector3 Vector3::operator -(int a) {
	if (size < a ) throw EmptySizeError();
	size = size - a;
	Vector3 temp(size, beg);
	delete []beg;
	beg = new int[size];
	for (int i = 0; i < size; i++) beg[i] = temp.beg[i];
	return *this;
}

Vector3 Vector3::operator --() {
	if(size == 0) throw EmptySizeError();
	if(size == 1) {
		size = 0;
		delete []beg;
		beg = 0;
		return *this;
	};
	Vector3 temp(size, beg);
	delete []beg;
	size--;
	beg = new int[size];
	for(int i = 0; i < size; i++) beg[i] = temp.beg[i];
	return *this;
}
