#ifndef DIALOG_H_
#define DIALOG_H_
using namespace std;

#include <iostream>
#include "Event.h"
#include "Calc.h"
#include "Fraction.h"
using namespace std;

class Dialog {
public:
	Dialog();
	virtual ~Dialog(void);
	int execute();
protected:
	int EndState;
private:
	Calc c;
	void enterOp1();
	void enterOp2();
	void enterAction();
	void enterForm();
	void printCalc();
	void calculate();
	void GetEvent (TEvent& event);
	void HandleEvent (TEvent& event);
	void ClearEvent (TEvent& event);
	int Valid();
	void EndExec();
};

#endif /* DIALOG_H_ */
