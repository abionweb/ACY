/*
 * Dialog.h
 *
 *  Created on: 20 ����. 2017 �.
 *      Author: Pavel.Bogdanov
 */

#ifndef DIALOG_H_
#define DIALOG_H_

namespace std {

class Dialog {
public:
	Dialog();

	void Menu();
	void doing();
	void main();
	virtual ~Dialog();
};

} /* namespace std */

#endif /* DIALOG_H_ */
