#ifndef DIALOG_H_
#define DIALOG_H_
using namespace std;

#include "Event.h"
#include "Calc.h"
#include <string>
#include <iostream>

class Dialog {
public:
	Dialog(void);
	virtual ~Dialog(void);
	virtual void GetEvent (TEvent& event);
	virtual int Execute();
	virtual void HandleEvent (TEvent& event);
	virtual void ClearEvent (TEvent& event);
	int Valid();
	void EndExec();
	void CalcDialog(void);
protected:
	int EndState;
};

#endif /* DIALOG_H_ */


/*
class Dialog {
public:
	Dialog(void);

	void Menu();
	void doing();
	void main();
	virtual ~Dialog();
};
*/
//} /* namespace std */

//#endif /* DIALOG_H_ */
