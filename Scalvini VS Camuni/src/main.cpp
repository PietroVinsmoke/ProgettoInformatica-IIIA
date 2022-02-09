//============================================================================
// Name        : Scalvini_VS_Camuni.cpp
// Author      : Pietro Boni
// Version     :
// Copyright   : W i simolares
// Description :
//============================================================================

#include <iostream>
#include <string>
#include <memory>

#include "Operazioni.h"

using namespace std;


int main() {

	//gestisce la partita
	unique_ptr<Operazioni> operazioni(Operazioni::getOperazioni());

	operazioni->inizio();	//inizio partita -> creazione di due personaggi
	operazioni->partita();	//turni della partita

	return 0;
}
