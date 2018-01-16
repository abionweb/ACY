/*
 * vector.h
 *
 *  Created on: 17 янв. 2018 г.
 *      Author: Павел
 */

#ifndef VECTOR_H_
#define VECTOR_H_

namespace std {

class vector {
public:
	vector(int s, int k=0);
	vector(const vector&a)
	~vector();
	vector&operator=(const vector&a);
	int&operator[](int index);
	vector operator+(const int k);
	int operator();
	friend ostream& operator<<(ostream& out, const vector&a);
	friend istream& operator>>(istream& in, vector&a);
private:
	int size;
	int*data;
};

} /* namespace std */

#endif /* VECTOR_H_ */
