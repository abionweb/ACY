#ifndef VECTOR3_H_
#define VECTOR3_H_
#include <string>
#include <iostream>
using namespace std;



class Vector3 {
	int size;
	int *beg;
	const int MAX_SIZE=30;
public:
	Vector3() { size = 0; beg = 0; };
	Vector3(int s);
	Vector3(int s, int* mas);
	Vector3(const Vector3&v);
	~Vector3();
	const Vector3& operator=(const Vector3&v);
	int operator[](int i);
	int operator()(void);
//	Vector3 operator+(int a);
	Vector3 operator+(int n);
	Vector3 operator-(int n);
	Vector3 operator--();

	friend ostream& operator<<(ostream& out, const Vector3& v);
	friend istream& operator>>(istream& in, Vector3& v);
};

#endif /* VECTOR2_H_ */
