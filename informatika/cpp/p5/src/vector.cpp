#include "vector.h"

vector::vector(void) {
	beg = 0;
	size = 0;
	cur = 0;
}

vector::vector(int n) {
	beg = new Object*[n];
	cur = 0;
	size = n;
}

vector::~vector(void) {
	if (beg!=0) delete [] beg;
	beg = 0;
}

void vector::add(Object *p) {
	if (cur<size) {
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream&out, const vector&v) {
	if (v.size == 0) out << "Empty" << endl;
	Object **p = v.beg;
	for (int i = 0; i<v.cur;i++) {
		(*p)->show();
		p++;
	}
	return out;;
}
