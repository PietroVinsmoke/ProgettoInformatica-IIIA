/*
 * Scalvino.h
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include "Persona.h"
using namespace std;

#ifndef SCALVINO_H_
#define SCALVINO_H_

//abitante della Valle di Scalve
class Scalvino: virtual public Persona{

	void spaccaLaLegna();

public:

	//lo scalvino ha di default più punti forza perché sì
	Scalvino(const string, const string, const int = 7);
	virtual void azione();

};

#endif /* SCALVINO_H_ */
