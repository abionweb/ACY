#pragma once
using namespace std;

const int evNothing = 0;
const int evMessage = 100;
const int cmStatus = 1;
const int cmProtocol = 2;
const int cmOp1      = 3;
const int cmOp2      = 4;
const int cmAction   = 5;
const int cmForm     = 6;
const int cmCalculate = 7;
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
