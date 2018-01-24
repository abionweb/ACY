#ifndef VECTOR_H_
#define VECTOR_H_

#include "Object.h"
#include "Employee.h"
#include <iostream>
using namespace std;

class Vector {
public:
	Vector();
	Vector(int);
	~Vector(void);
	void Add();
	void Add(Object*);
	void Del();
	void Show();
	int operator()();
	virtual void HandleEvent(const TEvent& e);
protected:
	Object**beg;
	int size;
	int cur;
};

#endif /* VECTOR_H_ */
