#include "Time.h"

using namespace std;

Time::Time() {
	minutes = 0;
	seconds = 0;
}

Time::Time(int m, int s) {
	minutes = m;
	seconds = s;
}

Time::Time(const Time&t) {
	minutes = t.minutes;
	seconds = t.seconds;
}

Time Time::operator =(const Time&t) {
	if (&t == this) return *this;
	minutes = t.minutes;
	seconds = t.seconds;
	return *this;
}

Time::~Time() {}

ostream& operator<<(ostream& out, const Time &t) {
	out << t.minutes << ":" << t.seconds;
	return out;
}

istream& operator >> (istream& in, Time&t) {
	cout << "Enter minutes: "; in >> t.minutes;
	cout << "Enter seconds: "; in >> t.seconds;
	return in;
}
