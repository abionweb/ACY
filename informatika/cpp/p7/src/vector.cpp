#include "vector.h"

///using namespace std;
template <class T>
vector<T>::vector(int s, T k) {
	size = s;
	data = new T[size];
	for(int i=0; i<size; i++) data[i] = k;
}

template <class T>
vector<T>::vector(const vector&a) {
	size = a.size;
	data = new T[size];
	for(int i=0; i<size; i++) data[i] = a.data[i];
}

template <class T>
vector<T>::~vector() {
	delete []data;
	data = 0;
}

template <class T>
vector<T>& vector<T>::operator=(const vector<T>&a) {
	if(this==&a) return *this;
	size = a.size;
	if (data!=0) delete[]data;
	data=new T[size];
	for(int i=0; i<size; i++) data[i] = a.data[i];
	return *this;
}

template <class T>
T& vector<T>::operator[](int index) {
	if (index<size)
		{ return data[index] }
	else
		//cout << endl << "Error! Index>size";
}

template <class T>
vector<T> vector<T>::operator+(const T k) {
	vector<T> temp(size, k);
	for(int i=0; i<size; ++i) temp.data[i]=data[i]+k;
	return temp;
}

template <class T>
int vector<T>::operator ()() { return size; }

template <class T>
ostream&operator << (ostream&out, const vector<T>&a) {
	for(int i=0; i<a.soze; ++i) out << a.data[i] << " ";
}

template <class T>
istream&operator >> (istream&in, vector<T>&a) {
	for(int i=0; i<a.size; ++i) in >> a.data[i];
	return in;
}
