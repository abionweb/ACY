#include "Dialog.h"

#include "Error.h"

using namespace std;

Dialog::Dialog(void) {
	EndState = 0;
}

Dialog::~Dialog() {
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
	string OpInt = "sp1z2fcqo";
	string s;
	string param;
	char code;

	cout << endl << "s. ������� ������ ������������";
	cout << endl << "1. ������ ������ ��������";
	cout << endl << "2. ������ ������ ��������";
	cout << endl << "o. ������ ���� ��������";
	cout << endl << "f. ������ ����� ������";
	cout << endl << "�. ����������";
	cout << endl << "p. ����������� �������� ������ ������������";
	cout << endl << "z. �������� ��������� ����";
	cout << endl << "q. ��������� ������ ���������";
	cout << endl << '>';
	cin >> s; code = s[0];
	if (OpInt.find(code)>=0 and OpInt.find(code)<4294967290) {
		event.what = evMessage;
		switch(code) {
			case 's': event.command=cmStatus; break;
			case '1': event.command=cmOp1; break;
			case '2': event.command=cmOp2; break;
			case 'o': event.command=cmAction; break;
			case 'f': event.command=cmForm; break;
			case 'c': event.command=cmCalculate; break;
			case 'p': event.command=cmProtocol; break;
			case 'z': event.command=cmCancel; break;
			case 'q': event.command=cmQuit; break;
		}
	} else event.what = evNothing;
}

void Dialog::HandleEvent(TEvent& event) {
	if (event.what == evMessage) {
		switch(event.command) {
		case cmStatus:
			printCalc();
			ClearEvent(event);
			break;
		case cmOp1:
			enterOp1();
			ClearEvent(event);
			break;
		case cmOp2:
			enterOp2();
			ClearEvent(event);
			break;
		case cmAction:
			enterAction();
			ClearEvent(event);
			break;
		case cmForm:
			enterForm();
			ClearEvent(event);
			break;
		case cmCalculate:
			calculate();
			ClearEvent(event);
			break;
		case cmProtocol:
			c.print_protocol();
			ClearEvent(event);
			break;
		case cmCancel:
			c.undoLastEntry();
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default:
			cout << "������������ �������. ��������� ��� ���!" << endl;
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

void Dialog::enterOp1() {
	string str;
	cout << endl << "����������, ������� ������ �������� (� ������� 5.12 ��� 6,23 ��� 7/99)" << endl << ">";
	cin >> str;
	c.set_op1(str);
}

void Dialog::enterOp2() {
	string str;
	cout << endl << "����������, ������� ������ �������� (� ������� 5.12 ��� 6,23 ��� 7/99)" << endl << ">";
	cin >> str;
	c.set_op2(str);
}

void Dialog::enterAction() {
	string OpInt = "+-*/";
	string str;
	char code;
	cout << endl << "����������, ������� ������ �������� ( + - * / )" << endl << ">";
	cin >> str;
	code = str[0];
	if (OpInt.find(code)>=0 and OpInt.find(code)<4294967290) {
		c.set_action(code);
	} else {
		cout << "������������ �������. ��������� ��� ���!" << endl;
	}
}

void Dialog::enterForm() {
	string OpInt = "./";
	string str;
	char code;
	cout << endl << "����������, ������� ������ ������� ������ ( . / )" << endl << ">";
	cin >> str;
	code = str[0];
	if (OpInt.find(code)>=0 and OpInt.find(code)<4294967290) {
		c.set_form(code);
	} else {
		cout << "������������ �������. ��������� ��� ���!" << endl;
	}
}

void Dialog::printCalc() {
	cout << endl << "������ ��������: \t" << c.get_op1();
	cout << endl << "���� ��������: \t\t" << c.get_action();
	cout << endl << "������ ��������: \t" << c.get_op2();
	cout << endl << "������ ������: \t\t" << c.get_form();
	cout << endl << "���������:     \t\t" << c.get_result_fraction();
	cout << endl;
}

void Dialog::calculate() {
	Fraction result_fraction;
	std::string result_string;
	try {
		c.execute();
		result_fraction = c.get_result_fraction();
		result_string = c.get_result_string();
		c.set_op1(result_fraction);
		cout << "���������: " << result_string << endl;
	}
	catch(Error& e) {
		e.what();
	}
}

int Dialog::Valid() {
	if (EndState == 0) return 0;
	else return 1;

}
