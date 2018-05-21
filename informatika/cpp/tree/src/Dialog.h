#ifndef DIALOG_H_
#define DIALOG_H_
using namespace std;

#include <iostream>
#include <string>
#include "Error.h"

class Dialog {
public:
	Dialog() {};
	virtual ~Dialog(void) {};
	int enterCount();
	int enterElement();
	bool enterManually();
private:
	int enterInt(string q);
	bool generalQuestionValid(string answer);
};


#endif /* DIALOG_H_ */
