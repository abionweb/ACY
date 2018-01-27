#ifndef TIME_H_
#define TIME_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Time {
public:
	Time();
	Time(int, int);
	Time(const Time&);
	Time operator = (const Time&);
	friend ostream& operator << (ostream &out, const Time& t);
	friend istream& operator >> (istream &out, Time& t);
	const bool operator == (const Time& t2);
	const bool operator != (const Time& t2);
	const bool operator < (const Time& t2);
	Time operator-(Time k);

	friend fstream& operator >> (fstream& fin, Time& t);
	friend fstream& operator << (fstream& fout, const Time& t);
	~Time();
private:
	int minutes, seconds;
};

#endif /* TIME_H_ */
