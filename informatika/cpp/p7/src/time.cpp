#include "time.h"

using namespace std;

time::time(void) {
	min = sec = 0;
}

time::time(int M, int S) {
	min = M;
	sec = S;
}

time::time(const time&t) {
	min = t.min;
	sec = t.sec;
}

time&time::operator =(const time &t) {
	min = t.min;
	sec = t.sec;
	return *this;
}

ostream& operator << (ostream&out, const time&t) {
	out << t.min << ":" << t.sec;
	return out;
}

istream& operator >> (istream &in, time&t) {
	cout << "Enter the minutes: ";
	in >> t.min;
	cout << "Enter the seconds: ";
	in >> t.sec;
	return in;
}

time time::operator+(int k) {
	int t=min*60+sec + k;
	time temp(t/60,t%60);
	return temp;
}

time time::operator+(time k) {
	int t=min*60+sec;
	int lt = k.min*60+k.sec;
	t+=lt;
	time temp(t/60,t%60);
	return temp;
}
