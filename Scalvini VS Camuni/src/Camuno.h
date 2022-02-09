/*
 * Camuno.h
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include <string>

#include "Persona.h"
using namespace std;

#ifndef CAMUNO_H_
#define CAMUNO_H_

//abitante della Valle Camonica
class Camuno: virtual public Persona{

	void giroBoarioBene();

public:
	//se non specificata, la forza è quella di default di Persona
	Camuno(const string, const string, const int = 5);
	virtual void azione();
};


#endif /* CAMUNO_H_ */
