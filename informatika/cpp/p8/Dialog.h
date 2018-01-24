#ifndef DIALOG_H_
#define DIALOG_H_

#include "Vector.h"
#include "Event.h"
using namespace std;

class Dialog :
	public Vector {
public:
	Dialog(void);
	virtual ~Dialog(void);
	virtual void GetEvent (TEvent &event);
	virtual int Execute();
	virtual void HandleEvent (TEvent& event);
	virtual void ClearEvent (TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};

#endif /* DIALOG_H_ */
