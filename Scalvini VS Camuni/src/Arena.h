/*
 * Arena.h
 *
 *  Created on: 28 gen 2022
 *      Author: pietr
 */

#include "Operazioni.h"
#include "Persona.h"

#ifndef ARENA_H_
#define ARENA_H_

//classe (gestita con singleton) per gestire il combattimento tra persone
class Arena {
	Arena();				//costruttore privato per non essere chiamato dall'esterno
	static Arena *arena;	//singola istanza per l'arena
	void eliminaSconfitto(shared_ptr<Persona>);						//elimina un combattente sconfitto
	int combattimento(shared_ptr<Persona>, shared_ptr<Persona>);	//gestisce lo scontro tra due persone
																	//restituisce l'id dello sconfitto
	friend void Operazioni::partita();								//metodo friend di Operazioni per l'accesso al
																	//metodo privato combattimento
public:

	static Arena *getArena();	//restituisce l'istanza (unica) dell'arena
	virtual ~Arena();
};

#endif /* ARENA_H_ */
