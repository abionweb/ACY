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

ostream& operator << (ostream& out, const Time &t) {
	out << t.minutes << ":" << t.seconds;
	return out;
}

istream& operator >> (istream& in, Time&t) {
	cout << "Enter minutes: "; in >> t.minutes;
	cout << "Enter seconds: "; in >> t.seconds;
	return in;
}

const bool Time::operator == (const Time& t2) {
	if ((minutes == t2.minutes) && (seconds == t2.seconds)) return true;
	else return false;
}

const bool Time::operator != (const Time& t2) {
	if ((minutes != t2.minutes) || (seconds != t2.seconds)) return true;
	else return false;
}

const bool Time::operator < (const Time& t2) {
	int x1 = minutes*60 + seconds;
	int x2 = t2.minutes*60 + t2.seconds;
	if (x1 < x2) return true;
	else return false;
}

Time Time::operator-(Time k) {
	int t1 = minutes * 60 + seconds;
	int t2 = k.minutes * 60 + k.seconds;
	int t = t1-t2;
	Time temp(t/60,t%60);
	return temp;
}

fstream& operator >> (fstream& fin, Time& t) {
	fin >> t.minutes;
	fin >> t.seconds;
	return fin;
}

fstream& operator << (fstream& fout,const Time& t) {
	fout << t.minutes << "\n" << t.seconds << "\n";
	return fout;
}
