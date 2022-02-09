/*
 * Persona.cpp
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include "Camuno.h"

#include <iostream>
#include <string>

using namespace std;

Camuno::Camuno(const string n, const string c, const int f):
			Persona(n, c, f){ }

//fare un giro per la Boario Bene punisce il camuno togliendogli 2 punti forza
void Camuno::giroBoarioBene(){
	cout << "________________________________________________________" << endl << endl;
	cout << "--- " << toString() << " ha fatto un giro per la Boario Bene!" << endl;
	cout << "--- Forza decrementata di 2 punti!" << endl;
	modForza( -2);
}

//azione del camuno
void Camuno::azione() { giroBoarioBene(); }
