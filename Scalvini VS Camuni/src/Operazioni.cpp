/*
 * Operazioni.cpp
 *
 *  Created on: 29 gen 2022
 *      Author: pietr
 */

#include <iostream>
#include <iterator>

#include "Operazioni.h"
#include "Arena.h"
#include "Persona.h"

using namespace std;

//costruttore vuoto per le operazioni
Operazioni::Operazioni() { }

//inizializzazione del singleton a NULL
Operazioni* Operazioni::operazioni = NULL;


//metodo di supporto per il singleton
//se l'istanza delle operazioni non esiste, la crea e la restituisce
//altrimenti restituisce l'istanza già esistente
Operazioni* Operazioni::getOperazioni() {
	if(operazioni == NULL)
		operazioni = new Operazioni();
	return operazioni;
}


//gestisce l'inizio del gioco permettendo la creazione di due personaggi
void Operazioni::inizio(){
	cout << "INIZIO" << endl;
	cout << "--------------------------------------------------------" << endl;
	cout << "Creazione primi due personaggi" << endl;
	cout << "--------------------------------------------------------" << endl;

	creaPersonaggio();
	creaPersonaggio();

}


//permette la creazione di un nuovo personaggio (scalvino, camuno o scalvinocamuno)
void Operazioni::creaPersonaggio(){
	char scelta;
	string nome;
	string cognome;
	int forza;

	//ciclo per la scelta della tipologia di personaggio
	do{
		cout << "Scalvino (s), Camuno (c) o ScalvinoCamuno (i)? ";
		cin >> scelta;

		if(scelta != 's' && scelta != 'S' && scelta != 'c' && scelta != 'C' && scelta != 'i' && scelta != 'I')
			cout << "--- ERRORE, inserire un carattere valido tra quelli proposti ---" << endl;

	}while(scelta != 's' && scelta != 'S' && scelta != 'c' && scelta != 'C' && scelta != 'i' && scelta != 'I');

	//inserimento dati personaggio
	cout << "Inserire nome: ";
	cin >> nome;
	cout << "Inserire cognome: ";
	cin >> cognome;
	cout << "Inserire punti forza (<=0 per default): ";
	cin >> forza;

	//aggiunta personaggio nella lista specifica in base alla scelta fatta
	switch(scelta){
	//SCALVINO
	case 's':
	case 'S':
	{
		shared_ptr<Scalvino> s;
		//differenzio il costruttore in base alla scelta fatta sulla forza del personaggio
		if(forza>0)
			s = shared_ptr<Scalvino>(new Scalvino(nome, cognome, forza));
		else
			s = shared_ptr<Scalvino>(new Scalvino(nome, cognome));
		//accoppio lo scalvino creato (value) al suo ID (key) nella lista
		listaScalvini.insert(make_pair(s->getID(), s));
		break;
	}
	//CAMUNO
	case 'c':
	case 'C':
	{
		shared_ptr<Camuno> c;
		//differenzio il costruttore in base alla scelta fatta sulla forza del camuno
		if(forza>0)
			c = shared_ptr<Camuno>(new Camuno(nome, cognome, forza));
		else
			c = shared_ptr<Camuno>(new Camuno(nome, cognome));
		//accoppio il camuno creato (value) al suo ID (key) nella lista
		listaCamuni.insert(make_pair(c->getID(), c));
		break;
	}
	//SCALVINOCAMUNO
	case 'i':
	case 'I':
	{
		shared_ptr<ScalvinoCamuno> sc;
		//differenzio il costruttore in base alla scelta fatta sulla forza dello scalvinocamuno
		if(forza>0)
			sc = shared_ptr<ScalvinoCamuno>(new ScalvinoCamuno(nome, cognome, forza));
		else
			sc = shared_ptr<ScalvinoCamuno>(new ScalvinoCamuno(nome, cognome));
		//accoppio lo scalvinocamuno creato (value) al suo ID (key) nella lista
		listaScalvinoCamuni.insert(make_pair(sc->getID(), sc));
		break;
	}
	}

	cout << "--------------------------------------------------------" << endl;
}


//stampa i personaggi delle liste
void Operazioni::stampaPersonaggi() const {
	cout << "________________________________________________________" << endl;
	cout << "SCALVINI" << endl;
	stampaLista(listaScalvini);
	cout << "________________________________________________________" << endl;
	cout << "CAMUNI" << endl;
	stampaLista(listaCamuni);
	cout << "________________________________________________________" << endl;
	cout << "SCALVINOCAMUNI" << endl;
	stampaLista(listaScalvinoCamuni);
	cout << "________________________________________________________" << endl;
}


//stampa le schede dei personaggi nella lista
template<class T> void Operazioni::stampaLista(map<int, shared_ptr<T>> lista) const {

	//iterator per scorrere la lista
	for(auto i = lista.begin(); i != lista.end(); ++i)
		stampaScheda(i->second);
}

//stampa la scheda del personaggio passato come argomento
template<class T> void Operazioni::stampaScheda(shared_ptr<T> p) const {
	cout << "ID: " << p->getID() << "\t|   " << p->toString() << ", " << p->getForza() << " punti forza" << endl;
}


//gestisce le azioni di una partita
void Operazioni::partita(){
	//istanza dell'arena per la partita
	unique_ptr<Arena> arena(Arena::getArena());

	char s;		//variabile per scegliere la continuazione o meno della partita
	char a;		//variabile per la scelta dell'azione da parte del giocatore
	int idSconfitto;	//per la rimozione dello sconfitto dalla lista

	cout << "--------------------------------------------------------" << endl;

	//ciclo per lo svolgimento dei turni della partita
	do{

		//ciclo per gestire la scelta del giocatore sul turno da fare
		do{
			cout << "Azione (a), crea personaggio(p) o combattimento (c)? ";
			cin >> a;

			if(a != 'a' && a != 'A' && a != 'p' && a != 'P' && a != 'c' && a != 'C')
				cout << "--- ERRORE, inserire un carattere valido tra quelli proposti ---" << endl;
		}while(a != 'a' && a != 'A' && a != 'p' && a != 'P' && a != 'c' && a != 'C');

		switch(a){
		//AZIONE
		case 'a':
		case 'A':
		{
			stampaPersonaggi();
			cercaPersonaggioID()->azione();
			stampaPersonaggi();
			break;
		}
		//CREAZIONE NUOVO PERSONAGGIO
		case 'p':
		case 'P':
		{
			creaPersonaggio();
			stampaPersonaggi();
			break;
		}
		//COMBATTIMENTO TRA DUE PERSONAGGI
		case 'c':
		case 'C':
		{
			stampaPersonaggi();
			idSconfitto = arena->combattimento(cercaPersonaggioID(), cercaPersonaggioID());
			rimuoviPersonaggioID(idSconfitto);
			stampaPersonaggi();
		}
		}

		cout << "--------------------------------------------------------" << endl;

		//ciclo per la richiesta all'utente sulla continuazione della partita
		do{
			cout << "Continuare la partita (s/S=sì, n/N=no)? ";
			cin >> s;

			if(s != 's' && s != 'S' && s != 'n' && s != 'N')
				cout << "--- ERRORE, inserire un carattere valido ---" << endl;

		}while(s != 's' && s != 'S' && s != 'n' && s != 'N');

		cout << "--------------------------------------------------------" << endl;

	}while(s == 's' || s=='S');

	cout << "________________________________________________________" << endl << endl;

}



//rimuove un personaggio dalla lista in base all'id passato come parametro
//se l'id è negativo non succede nulla
void Operazioni::rimuoviPersonaggioID(int id){
	if(id>0){
		listaScalvini.erase(id);
		listaCamuni.erase(id);
		listaScalvinoCamuni.erase(id);
	}
}


//cerca nelle liste un personaggio in base all'ID e lo restituisce
shared_ptr<Persona> Operazioni::cercaPersonaggioID() const {
	int id;
	//si cerca il personaggio finché non si inserisce un id valido
	while(true){
		cout << "Scegliere un personaggio in base all'ID: ";
		cin >> id;

		//scorro la lista degli scalvini
		for(auto i = listaScalvini.begin(); i != listaScalvini.end(); ++i)
			if(i->first == id)
				return i->second;


		//scorro la lista dei camuni
		for(auto i = listaCamuni.begin(); i != listaCamuni.end(); ++i)
			if(i->first == id)
				return i->second;

		//scorro la lista degli scalvinocamuni
		for(auto i = listaScalvinoCamuni.begin(); i != listaScalvinoCamuni.end(); ++i)
			if(i->first == id)
				return i->second;

		cout << "--- ERRORE: inserire un ID valido ---" << endl;
	}
}


//definizioni per il template del metodo stampaLista
template void Operazioni::stampaLista<Scalvino>(map<int, shared_ptr<Scalvino>>) const;
template void Operazioni::stampaLista<Camuno>(map<int, shared_ptr<Camuno>>) const;
template void Operazioni::stampaLista<ScalvinoCamuno>(map<int, shared_ptr<ScalvinoCamuno>>) const;

//definizioni per il template del metodo stampaScheda
template void Operazioni::stampaScheda<Scalvino>(shared_ptr<Scalvino>) const;
template void Operazioni::stampaScheda<Camuno>(shared_ptr<Camuno>) const;
template void Operazioni::stampaScheda<ScalvinoCamuno>(shared_ptr<ScalvinoCamuno>) const;


//distruttore per l'istanza delle operazioni
Operazioni::~Operazioni() { cout << "--- Operazioni archiviate ---" << endl << endl; }

