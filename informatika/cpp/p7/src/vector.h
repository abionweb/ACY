#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

template <class T>
class Vector {
public:
	Vector(int s, T k);
	Vector(const Vector<T>&a);
	~Vector();
	Vector& operator=(const Vector<T>&a);
	T& operator[](int index);
	Vector operator+(const T k);
	Vector operator+(const Vector<T>&a);
	int operator()();
	template <class _T> friend istream & operator>> (istream & in, const Vector<_T>&);
	template <class _T> friend ostream & operator<< (ostream & out, Vector<_T>&a);
private:
	int size;
	T*data;
};

template <class T>
Vector<T>::Vector(int s, T k) {
	size = s;
	data = new T[size];
	for(int i=0; i<size; i++) data[i] = k;
}

template <class T>
Vector<T>::Vector(const Vector&a) {
	size = a.size;
	data = new T[size];
	for(int i=0; i<size; i++) data[i] = a.data[i];
}

template <class T>
Vector<T>::~Vector() {
	delete []data;
	data = 0;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>&a) {
	if(this==&a) return *this;
	size = a.size;
	if (data!=0) delete[]data;
	data=new T[size];
	for(int i=0; i<size; i++) data[i] = a.data[i];
	return *this;
}

template <class T>
T& Vector<T>::operator[](int index) {
	if (index<size)
		{ return data[index]; }
	else {
		cout << endl << "Error! Index>size";
	}
}

template <class T>
Vector<T> Vector<T>::operator+(const T k) {
	Vector<T> temp(size, k);
	for(int i=0; i<size; ++i) temp.data[i]=data[i]+k;
	return temp;
}

template <class T>
Vector<T> Vector<T>::operator+(const Vector<T>&a) {
	int max, min;
	Vector<T> temp(1);
	if (size > a.size) {
		min = a.size;
		temp = *this;
	} else {
		min = size;
		temp = a;
	}
	for (int i=0; i<min; ++i) temp.data[i] = data[i] + a.data[i];
	return temp;
}

template <class T>
int Vector<T>::operator ()() { return size; }

template <class T>
istream&operator >> (istream&in, const Vector<T>&a) {
	for(int i=0; i<a.size; ++i) in >> a.data[i];
	return in;
}

template <class T>
ostream&operator << (ostream&out, Vector<T>&a) {
	for(int i=0; i<a.size; ++i) out << a.data[i] << " ";
	return out;
}

#endif /* VECTOR_H_ */
