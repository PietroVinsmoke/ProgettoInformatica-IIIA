/*
 * Arena.cpp
 *
 *  Created on: 28 gen 2022
 *      Author: pietr
 */



#include <iostream>

#include "Arena.h"
#include "Camuno.h"
#include "Scalvino.h"
#include "ScalvinoCamuno.h"

//costruttore vuoto per l'arena
Arena::Arena() { }

//inizializzazione del singleton a NULL
Arena* Arena::arena = NULL;

//metodo di supporto per il singleton
//se l'istanza di arena non esiste, la crea e la restituisce
//altrimenti restituisce l'istanza già esistente
Arena* Arena::getArena() {
	if(arena == NULL)
		arena = new Arena();
	return arena;
}

//elimina dall'esistenza un concorrente sconfitto
void Arena::eliminaSconfitto(shared_ptr<Persona> p) { p.reset(); }

//gestisce i combattimenti fra persone basandosi sui loro punti forza
int Arena::combattimento(shared_ptr<Persona> p1, shared_ptr<Persona> p2){
	int idSconfitto;

	cout << "________________________________________________________" << endl << endl;

	//se si è scelto lo stesso personaggio
	if(p1->getID() == p2->getID()){
		cout << "--- " << p1->toString() << " non è ancora abbastanza ubriaco per combattere contro se stesso!" << endl;
		return -1;
	}else{
		//se i due personaggi hanno gli stessi punti forza
		if(p1->getForza() == p2->getForza()){
			cout << "--- " << p1->toString() << " e " << p2->toString() << " hanno pareggiato! -> Ancora in gioco!" << endl;
			return 0;
		}
		else{
			//p1 vincente, p2 perdente
			if(p1->getForza() > p2->getForza()){
				cout << "--- " << p1->toString() << " ha sconfitto " << p2->toString() << " ---" << endl;

				p1->modForza(2);		//la forza del vincente aumenta di 2 punti
				idSconfitto = p2->getID();
				eliminaSconfitto(p2);	//delete dello sconfitto
			}
			else	//p2 vincente, p1 perdente
			{
				cout << "--- " << p2->toString() << " ha sconfitto " << p1->toString() << " ---" << endl;

				p2->modForza(2);		//la forza del vincente aumenta di 2 punti
				idSconfitto = p1->getID();
				eliminaSconfitto(p1);	//delete dello sconfitto
			}
		}
	}

	return idSconfitto;	//restituisce l'id del personaggio sconfitto per la rimozione dalle liste
}


//distruttore
Arena::~Arena() { cout << "--- Arena smantellata ---" << endl << endl; }

