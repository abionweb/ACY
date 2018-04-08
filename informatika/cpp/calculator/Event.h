#pragma once
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmCalc = 1;
const int cmQuit= 101;

struct TEvent {
	int what;
	union {
		int command;
		struct {
			int message;
			int a;
		};
	};
};
