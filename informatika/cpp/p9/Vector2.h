#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <iostream>
using namespace std;
const int MAX_SIZE=30;

class Vector2 {
	int size;
	int *beg;
public:
	Vector2() { size = 0; beg = 0; };
	Vector2(int s);
	Vector2(int s, int* mas);
	Vector2(const Vector2&v);
	~Vector2();
	const Vector2& operator=(const Vector2&v);
	int operator[](int i);
	int operator()(void);
//	Vector2 operator+(int a);
	Vector2 operator+(int n);
	Vector2 operator-(int n);
	Vector2 operator--();

	friend ostream& operator<<(ostream& out, const Vector2& v);
	friend istream& operator>>(istream& in, Vector2& v);
};

#endif /* VECTOR2_H_ */
