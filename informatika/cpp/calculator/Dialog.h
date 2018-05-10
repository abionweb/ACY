/*
 * Dialog.h
 *
 *  Created on: 20 но€б. 2017 г.
 *      Author: Pavel.Bogdanov
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include <iostream>
#include "Event.h"
using namespace std;

class Dialog {
public:
	Dialog();
	virtual ~Dialog();
	//Calc c;
	void menu();
	int execute();
	void GetEvent (TEvent &event);
	void HandleEvent (TEvent& event);
	void ClearEvent (TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

#endif /* DIALOG_H_ */
