/*
 * Dialog.h
 *
 *  Created on: 20 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include <iostream>
#include "Event.h"
#include "Calc.h"
#include "Fraction.h"
using namespace std;

class Dialog {
public:
	Dialog();
	virtual ~Dialog();
//	void menu();
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
