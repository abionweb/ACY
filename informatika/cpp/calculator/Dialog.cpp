/*
 * Dialog.cpp
 *
 *  Created on: 20 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#include "Dialog.h"

Dialog::Dialog() {
	// TODO Auto-generated constructor stub

}

Dialog::~Dialog() {
	// TODO Auto-generated destructor stub
}

int Dialog::execute() {
	TEvent event;
	do {
		EndState=0;
		GetEvent(event);
		HandleEvent(event);
	} while(!Valid());
	return EndState;
}

void Dialog::GetEvent(TEvent &event) {
	string OpInt = "123";
	string s;
	string param;
	char code;

	cout << endl << "1. ���������� ����� �������";
	cout << endl << "2. ����������� �������� ������ ������������";
	cout << endl << "3. ��������� ������ ���������";
	cout << endl << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code)>=0) {
		event.what = evMessage;
		switch(code) {
			case '1': event.command=cmCalc; break;
			case '2': event.command=cmProtocol; break;
			case '3': event.command=cmQuit; break;
		}
	} else event.what = evNothing;
}

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch(event.command) {
		case cmCalc:
			cout << "������ ������������";
			ClearEvent(event);
			break;
		case cmProtocol:
			cout << "����� ���������";
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default:
			cout << endl << "������������ �������. ��������� ��� ���!";
		}
	}
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}

void Dialog::EndExec() {
	cout << "�� �������!";
	EndState = 1;
}

int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;
}
