/*
 * Dialog.cpp
 *
 *  Created on: 20 нояб. 2017 г.
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

	cout << endl << "1. Произвести новый рассчет";
	cout << endl << "2. Просмотреть протокол работы калькулятора";
	cout << endl << "3. Завершить работу программы";
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
			cout << "Запуск калькулятора";
			ClearEvent(event);
			break;
		case cmProtocol:
			cout << "Вывод протокола";
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default:
			cout << endl << "Недопустимая команда. Попробуем ещё раз!";
		}
	}
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}

void Dialog::EndExec() {
	cout << "До встречи!";
	EndState = 1;
}

int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;
}
