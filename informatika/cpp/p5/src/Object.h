/*
 * Object.h
 *
 *  Created on: 15 янв. 2018 г.
 *      Author: Павел
 */

#ifndef OBJECT_H
#define OBJECT_H

class Object {
public:
	Object();
	~Object();
	virtual void show() = 0;
};

#endif
