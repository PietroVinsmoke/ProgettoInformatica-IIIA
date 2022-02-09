/*
 * Operazioni.h
 *
 *  Created on: 29 gen 2022
 *      Author: pietr
 */

#ifndef OPERAZIONI_H_
#define OPERAZIONI_H_

#include <map>
#include <memory>

#include "ScalvinoCamuno.h"


//classe per la gestione del gioco e delle liste dei personaggi
class Operazioni {
	Operazioni();			//costruttore privato per non essere chiamato dall'esterno
	static Operazioni *operazioni;	//singola istanza per le operazioni

	//liste per i tipi di personaggi
	//map per gestire le liste dei personaggi di varie tipologie
	map<int, shared_ptr<Scalvino>> listaScalvini;
	map<int, shared_ptr<Camuno>> listaCamuni;
	map<int, shared_ptr<ScalvinoCamuno>> listaScalvinoCamuni;

	void creaPersonaggio();			//per inserire un personaggio in una specifica lista
	void stampaPersonaggi() const;	//stampa i personaggi delle liste
	void rimuoviPersonaggioID(int);	//rimuove un personaggio dalla lista specifica in base all'id passato
	shared_ptr<Persona> cercaPersonaggioID() const;	//ricerca nelle liste un personaggio in base all'ID

	template<class T> void stampaLista(map<int, shared_ptr<T>>) const;	//stampa i personaggi nella lista
	template<class T> void stampaScheda(shared_ptr<T>) const;	//stampa la scheda del personaggio (inline)

public:

	void inizio();		//per l'inizio del gioco
	void partita();		//gestisce le azioni di una partita

	static Operazioni *getOperazioni();	//restituisce l'istanza (unica) per le operazioni
	virtual ~Operazioni();
};

#endif /* OPERAZIONI_H_ */
