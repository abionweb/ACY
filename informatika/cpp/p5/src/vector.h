#ifndef VECTOR_H_
#define VECTOR_H_

#include "object.h"
#include <string>
#include <iostream>

using namespace std;

class vector {
public:
	vector(void);
	vector(int);
	~vector(void);
	void add(Object *);
	friend ostream& operator<<(ostream&out, const vector&);
private:
	Object**beg;
	int size;
	int cur;
};

#endif /* VECTOR_H_ */
