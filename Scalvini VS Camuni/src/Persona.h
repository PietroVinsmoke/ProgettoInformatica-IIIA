/*
 * Persona.h
 *
 *  Created on: 26 gen 2022
 *      Author: pietr
 */

#include <string>
#include "Personaggio.h"
using namespace std;

#ifndef PERSONA_H_
#define PERSONA_H_

//classe base per tutte le persone
class Persona: public Personaggio{

	static int ID_ref;		//riferimento statico per l'assegnazione dell'ID ad un personaggio
	const int id = ID_ref;

	const string nome;
	const string cognome;
	int forza;

public:
	//costruttore
	//default values -> se non speicifcata forza = 5
	Persona(const string, const string, const int = 5);

	//azione specifica svolta da una persona
	virtual void azione();

	//dichiarazioni inline
	//restituisce la stringa nome+cognome della persona
	inline virtual string toString() const { return nome + " " + cognome; }

	inline int getID() const { return id; }	//restituisce l'id della persona
	inline int getForza() const { return forza; }	//restituisce la forza della persona
	inline void modForza(int delta) { forza += delta; }	//incrementa/decrementa la forza della persona in base al valore delta
	virtual ~Persona();
};



#endif /* PERSONA_H_ */
