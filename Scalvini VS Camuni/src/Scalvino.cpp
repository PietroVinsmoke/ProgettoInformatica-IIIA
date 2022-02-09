/*
 * Scalvino.cpp
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include "Scalvino.h"

#include <iostream>

Scalvino::Scalvino(const string n, const string c, const int f): Persona(n, c, f) { } // @suppress("Ambiguous problem")

//spaccare la legna dona 5 punti forza allo scalvino
void Scalvino::spaccaLaLegna() {
	cout << "________________________________________________________" << endl << endl;
	cout << "--- " << toString() << " è andato a spaccare la legna!" << endl;
	cout << "--- Forza incrementata di 5 punti!" << endl;
	modForza(5);
}

//azione dello scalvino
void Scalvino::azione() { spaccaLaLegna(); }
