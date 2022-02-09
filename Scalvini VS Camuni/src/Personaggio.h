/*
 * Personaggio.h
 *
 *  Created on: 9 feb 2022
 *      Author: pietr
 */


#ifndef PERSONAGGIO_H_
#define PERSONAGGIO_H_

#include <string>
using namespace std;

class Personaggio{

public:
	virtual void azione() = 0;

	virtual ~Personaggio() {}
};



#endif /* PERSONAGGIO_H_ */
