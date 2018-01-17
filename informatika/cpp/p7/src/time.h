#ifndef TIME_H_
#define TIME_H_
#include <iostream>
using namespace std;

class time {
public:
	time(void);
	time(int, int);
	time(const time&);
	time&operator=(const time&);
	friend ostream& operator << (ostream& out, const time&);
	friend istream& operator >> (istream& in, time&);
	virtual ~time(void){};
private:
	int min, sec;
};

#endif /* TIME_H_ */
