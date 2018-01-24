#include "Vector2.h"
#include <iostream>

#include "Error2.h"
using namespace std;

Vector2::Vector2(int s) {
	if (s > MAX_SIZE) throw error2("Vector length more than MAXSIZE\n");
	size = s;
	beg = new int [s];
	for (int i = 0; i < size; i++ ) beg[i] = 0;
}

Vector2::Vector2(const Vector2 &v) {
	size = v.size;
	beg = new int [size];
	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
}

Vector2::~Vector2() {
	if (beg!=0) delete []beg;
}

Vector2::Vector2(int s, int *mas) {
	if (s > MAX_SIZE) throw error2("Vector length more than MAXSIZE\n");
	size = s;
	beg = new int[size];
	for(int i = 0; i < size; i++) beg[i] = mas[i];
}

const Vector2& Vector2::operator =(const Vector2 &v) {
	if (this == &v) return *this;
	if (beg!=0) delete []beg;
	size = v.size;
	beg = new int [size];
	for (int i = 0; i < size; i++) beg[i] = v.beg[i];
	return *this;
}

ostream& operator<<(ostream& out, const Vector2& v) {
	if (v.size == 0) out << "Empty" << endl;
	else {
		for (int i = 0; i < v.size; i++) out << v.beg[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>>(istream& in, Vector2& v) {
	for (int i = 0; i < v.size; i++) {
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}

int Vector2::operator [](int i) {
	if (i < 0) throw error2("Index <0");
	if (i >= size) throw error2("Index > size");//3;
	return beg[i];
}

int Vector2::operator ()() {
	return size;
}
/*
Vector2 Vector2::operator +(int a) {
	if (size + 1 == MAX_SIZE) throw 4;
	Vector2 temp(size+1, beg);
	temp.beg[size] = a;
	return temp;
}*/


Vector2 Vector2::operator +(int n) {
	if (size + n >= MAX_SIZE) throw error2("size + a >= MAX_SIZE");
	Vector2 temp(size + n, beg);
	for (int i = size; i < (size + n); i++) temp.beg[i] = 0;
	return temp;
}

Vector2 Vector2::operator -(int a) {
	if (size < a ) throw error2("size < a");
	size = size - a;
	Vector2 temp(size, beg);
	delete []beg;
	beg = new int[size];
	for (int i = 0; i < size; i++) beg[i] = temp.beg[i];
	return *this;
}

Vector2 Vector2::operator --() {
	if(size == 0) throw error2("Vector is empty");
	if(size == 1) {
		size = 0;
		delete []beg;
		beg = 0;
		return *this;
	};
	Vector2 temp(size, beg);
	delete []beg;
	size--;
	beg = new int[size];
	for(int i = 0; i < size; i++) beg[i] = temp.beg[i];
	return *this;
}
