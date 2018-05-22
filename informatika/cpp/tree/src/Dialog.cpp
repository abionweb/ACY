#include "Dialog.h"

int Dialog::enterCount() {
	return enterInt("Enter elements count:\n>");
}

int Dialog::enterElement() {
	return enterInt("Enter element:\n>");
}

int Dialog::enterInt(string q) {
	int integer;
	bool not_valid = true;
	do {
		try {
			cout << q;
			cin >> integer;
			if (std::cin.good()) {
				not_valid = false;
			} else {
				cin.clear();
				cin.ignore();
				throw EnterIntError();
			}
		} catch (EnterIntError& e) {
			e.what();
		}
	} while(not_valid);
	return integer;
}

int Dialog::enterInput() {
	string answer;
	bool not_valid = true;
	do {
		try {
			cout << "How to enter elements? (m,r,f)\n>";
			cin >> answer;
			if (std::cin.good()) {
				if (generalQuestionValid(answer)) {
					not_valid = false;
				} else {
					throw EnterGeneralQuestion();
				}
			} else {
				cin.clear();
				cin.ignore();
				throw EnterGeneralQuestion();
			}
		} catch (EnterGeneralQuestion& e) {
			e.what();
		}
	} while(not_valid);
	if (answer == "manually" or answer == "m") return 1;
	if (answer == "random" or answer == "r") return 2;
	if (answer == "file" or answer == "f") return 3;
	return 0;
}

bool Dialog::generalQuestionValid(string answer) {
	if ((answer == "m") or (answer == "manually") or (answer == "random") or (answer == "r") or (answer == "file") or (answer == "f")) {
		return true;
	} else {
		return false;
	}
}
