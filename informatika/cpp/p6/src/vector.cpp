/*
 * vector.cpp
 *
 *  Created on: 17 янв. 2018 г.
 *      Author: Павел
 */

#include "vector.h"

//namespace std {

vector::vector(int s, int k) {
	size = s;
	data = new int[size];
	for (int i=0; i<size; i++) {
		data[i] = k;
	}
}

vector::vector(const vector&a) {
	size = a.size;
	data = new int[size];
	for (int i=0; i<size; i++) {
		data[i] = a.data[i];
	}
}

vector::~vector() {
	delete []data;
	data = 0;
}

vector&vector::operator =(const vector&a) {
	if(this == &a) return *this;
	size = a.size;
	if (data!=0) delete[]data;
	data = new int[size];
	for(int i=0; i<size; i++) data[i] = a.data[i];
	return *this;
}

int&vector::operator[](int index) {
	if (index<size) return data[index];
	else {
		//cout << "\nError! index > size";
	}
	return data[index];
}

vector vector::operator+(const int k) {
	vector temp(size);
	for (int i=0; i<size; ++i) temp.data[i]+=data[i]+k;
	return temp;
}

vector vector::operator+(const vector&a) {
	vector temp(size);
	for (int i=0; i<size; ++i) temp.data[i] = data[i] + a.data[i];
	return temp;
}

int vector::operator () () {
	return size;
}

ostream&operator<<(ostream&out, const vector&a) {
	for (int i=0; i < a.size; ++i)
		out << a.data[i] << " ";
	return out;
}

istream&operator>>(istream&in, vector&a) {
	for (int i=0; i<a.size; ++i) in >> a.data[i];
	return in;
}



//} /* namespace std */
