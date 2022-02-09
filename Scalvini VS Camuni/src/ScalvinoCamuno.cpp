/*
 * Persona.cpp
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include "ScalvinoCamuno.h"

ScalvinoCamuno::ScalvinoCamuno(const string n, const string c, const int f):
	Persona(n, c, f), Scalvino(n, c, f), Camuno(n, c, f) { }


//ereditando pregi e difetti di scalvino e camuno, lo scalvinocamuno svolgerà entrambe le azioni dei suddetti
void ScalvinoCamuno::azione() {
	Scalvino::azione();
	Camuno::azione();
}
