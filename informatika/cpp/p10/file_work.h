#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int make_file(const char* f_name) {
	fstream stream(f_name, ios::out|ios::trunc);
	if(!stream) return -1;
	int n;
	Time t;
	cout << " N? "; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t ;
		stream << t << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name) {
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Time t; int i = 0;
	while (stream>>t) {
		cout << t << "\n";
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, int k) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if(!stream) return -1;
	int i = 0;
	Time t;
	while(stream >> t) {
		if (stream.eof()) break;
		i++;
		if(i!=k) temp << t;
	}
	stream.close();;
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char*f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return 0;
	Time t; int i= 0, l = 0;
	while (stream >> t) {
		if (stream.eof()) break;
		i++;
		if(i==k) {
			temp << tt;
			l++;
		}
		temp<<t;
	}
	stream.close();
	temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name, Time tt) {
	fstream stream(f_name, ios::app);
	if(!stream) return -1;
	stream << tt;
	return 1;
}

int change_file(const char* f_name, int k, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if(!stream) return -1;
	Time t; int i = 0, l = 0;
	char q;
	while (stream >> t) {
		if (stream.eof()) break;
		i++;
		if(i == k) {
			cout << t << " - is changing... Continue[y/n]?\n";
			cin >> q;
			if (q == 'n' || q == 'N') break;
			temp << tt;
			l++;
		} else temp << t;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int delete_value(const char* f_name, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if(!stream) return -1;
	Time t; int i = 0, l = 0;
	while (stream >> t) {
		if (stream.eof()) break;
		i++;
		if (t == tt) {
			temp << t;
			l++;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int reduce_value(const char* f_name, Time tt) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if(!stream) return -1;
	Time t1_30(1,30), t0, t;
	int i = 0, l = 0;
	while (stream >> t) {
		if (stream.eof()) break;
		i++;
		if (t == tt) {
			t = t - t1_30;
			if (t < t0) t = t0;
			temp << t;
			l++;
		} else {
			temp << t;
		}
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_few(const char* f_name, int nom) {
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if(!stream) return -1;
	Time t;
	for (int i = 0; i < nom; i++) {
		temp << t;
	}
	while (stream >> t) {
		if (stream.eof()) break;
		temp << t;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return 1;
}
