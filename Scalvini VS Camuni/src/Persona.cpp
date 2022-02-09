

#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

int Persona::ID_ref = 1;

//Costruttore della persona
// n->nome, c->cognome
// f->forza, se non settata è posta a 5
//incrementa di 1 il riferimento statico per gli ID
Persona::Persona(const string n, const string c, const int f):
			nome(n), cognome(c), forza(f) { ++ID_ref; }

//azione specifica svolta da una persona
void Persona::azione() { }

//distruttore
Persona::~Persona() { cout << "--- " << toString() << " eliminato! ---" << endl;}

