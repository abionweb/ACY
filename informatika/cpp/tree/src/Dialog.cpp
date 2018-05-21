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

bool Dialog::enterManually() {
	string answer;
	bool not_valid = true;
	do {
		try {
			cout << "Want to enter values manually?\n>";
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
	if ((answer == "yes") or (answer == "y") or (answer == "manually")) {
		return true;
	} else {
		return false;
	}
}

bool Dialog::generalQuestionValid(string answer) {
	if ((answer == "yes") or (answer == "y") or (answer == "manually") or (answer == "no") or (answer == "n") or (answer == "random")) {
		return true;
	} else {
		return false;
	}
}
