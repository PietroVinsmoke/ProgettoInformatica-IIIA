/*
 * ScalvinoCamuno.h
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include "Camuno.h"
#include "Scalvino.h"

#ifndef SCALVINOCAMUNO_H_
#define SCALVINOCAMUNO_H_

//ibrido scalvino-camuno -> eredita tutti i pregi di uno scalvino ed i difetti di un camuno
class ScalvinoCamuno: public Scalvino, public Camuno{

public:
	//essendo un ibrido tra uno scalvino ed un camuno, la forza
	//se non settata avrà di default valore 6
	ScalvinoCamuno(const string, const string, const int = 6);

	virtual void azione();
};



#endif /* SCALVINOCAMUNO_H_ */
