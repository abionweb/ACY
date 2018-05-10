#include "Dialog.h"
using namespace std;

Dialog::Dialog(void) {
	EndState = 0;
}

Dialog::~Dialog() {
}

void Dialog::GetEvent(TEvent &event) {
	string OpInt = "cq";
	string s;
	string param;

	char code;
	cout << "c - Выполнить рассчет" << endl << "q - Выход из программы" << endl << "Пожалуйста, введите команду: ";
	cin >> s; code = s[0];
	if (OpInt.find(code)>=0) {
		event.what = evMessage;
		switch(code) {
			case 'c': event.command=cmCalc; break; // произвести вычисления
			case 'q': event.command=cmQuit; break; // выйти из программы
		}
		if (s.length()>1) {
			param = s.substr(1,s.length()-1);
			int A=atoi(param.c_str());
			event.a=A;
		}
	} else event.what = evNothing;
}

int Dialog::Execute() {
	TEvent event;
	do {
		EndState=0;
		GetEvent(event);
		HandleEvent(event);
	} while(!Valid());
	return EndState;
}

int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;
}

void Dialog::ClearEvent(TEvent& event) {
	event.what = evNothing;
}

void Dialog::EndExec() {
	EndState = 1;
}

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch(event.command) {
		case cmCalc:
			CalcDialog();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		//default:
			//Vector::HandleEvent(event);
		}
	}
}

void Dialog::CalcDialog(void) {
	Calc c;
	string op1, op2;
	char action, form;

	cout.precision(7);

	cout << endl << "Пожалуйста, введите первое число: ";
	cin >> op1;

	c.set_op1(op1);

	cout << endl << "Пожалуйста, введите второе число: ";
	cin >> op2;
	c.set_op2(op2);

	cout << endl << "Пожалуйста, введите символ операции ( + - * / ): ";
	cin >> action;
	c.set_action(action);

	cout << endl << "Пожалуйста, введите символ представления результата ( . / ): ";
	cin >> form;
	c.set_form(form);
}
