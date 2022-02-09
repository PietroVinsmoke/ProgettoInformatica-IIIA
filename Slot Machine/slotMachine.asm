//custom slot machine

//tris di figure -> puntata x20
//tris di wild -> 300€
//tris di jackpot -> 3000€

//doppio frutto o spin + wild -> puntata x15
//doppio wild + frutto o spin -> 150€
//doppio wild + jackpot  o wild + doppio jackpot -> puntata*50
//
//per ogni spin uscito si ha uno spin omaggio alla puntata massima

asm slotMachine

import StandardLibrary

signature:

	//simboli sui rulli
	enum domain Simbolo = {UVA | MELA | PERA | RIBES | KIWI | SPIN | WILD | JACKPOT}
	
	domain Puntata subsetof Integer		//dominio per i valori delle puntate
	domain SlotRullo subsetof Integer	//dominio per il numero di slot di un rullo 
	domain Spin subsetof Integer		//dominio per il numero di spin (turni) disponibili
	domain SimboloAss subsetof Prod(SlotRullo, Simbolo)	//Simbolo associato ad uno slot del rullo
	
	//rappresentano la fila orizzontale dei simboli ottenuti dallo spin dei tre rulli
	controlled rullo1: Simbolo
	controlled rullo2: Simbolo
	controlled rullo3: Simbolo
	
	controlled cassaSlot: Integer		//soldi nella cassa della slot
	controlled portafoglio: Integer		//soldi nel portafoglio del giocatore
	controlled guadagno: Integer		//se positivo il giocatore vince, se negativo perde
										//se nullo -> nulla di fatto
	controlled risultato: String		//risultato della partita
	controlled spin: Spin				//numero di spin giocati
	controlled spinOmaggio: Natural		//spin omaggio alla massima puntata (uscito spin)
	
	monitored puntata: Puntata			//puntata fatta dal giocatore		
	controlled puntataS: Puntata		//valore della puntata controllato dalla slot
	
	static getRisultato: String			//per visualizzare il risultato della partita
	

definitions:

	//-> puntate possibili: 1€, 2€, 5€, 10€
	//-> ogni rullo è composto da 11 slot per i simboli
	//-> massimo numero di spin giocabili: 50
	//-> corrispondenza tra slot di un rullo e simboli: ogni rullo ha
	//	 tre frutti ripetuti, un simbolo wild e un simbolo jackpot
	domain Puntata = {1, 2, 5, 10, 20}
	domain SlotRullo = {1:13}	
	domain Spin = {0:30}
	domain SimboloAss = { (1, UVA), (2, MELA), (3, PERA), (4, RIBES), (5, KIWI),
						  (6, UVA), (7, MELA), (8, PERA), (9, RIBES), (10, KIWI),
						  (11, SPIN), (12, WILD), (13, JACKPOT) } 
						 
						 
	//visualizzazione risultato di fine partita					 
	function getRisultato =
		if guadagno > 0 then
			"Hai sbancato!"
		else
			if guadagno < 0 then
				"Sara' per un'altra volta!"
			else
				"Ci hai almeno provato?"
			endif
		endif
			
	
	//aggiorna i saldi in caso di vittoria (o puntata) del giocatore
	macro rule r_updateVincita ($win in Integer) =
		par 
			cassaSlot := cassaSlot - $win
			guadagno := guadagno + $win
			portafoglio := portafoglio + $win
		endpar
	
	
	//gestione tris				  
	macro rule r_tris($r in Simbolo) =
		switch($r)
			case JACKPOT:		
				r_updateVincita[3000]			//tris jackpot -> 3000€				
			case WILD:
				r_updateVincita[300]			//tris wildcard -> 300€
			otherwise							
				r_updateVincita[puntataS*20]	//tris figure -> puntata*20 
		endswitch
		
		
	//gestione doppio wild + simbolo
	macro rule r_doppioWild($r in Simbolo) =
		switch($r)
			case JACKPOT:
				r_updateVincita[puntataS*50]		//tris doppio wild + jackpot -> puntata*50
			otherwise
				r_updateVincita[150]				//tris doppio wild + frutto -> 150 €
		endswitch
		
		
		
	//gestione wild + doppio simbolo
	macro rule r_wildDoppioSimbolo($r in Simbolo) =
		switch($r)
			case JACKPOT:
				r_updateVincita[puntataS*50]		//tris wild + doppio jackpot -> puntata*50
			otherwise
				r_updateVincita[puntataS*15]		//tris wild + doppio frutto -> puntata*15
		endswitch
				

	//verifica di altri wild eventuali
	macro rule r_wild($r1 in Simbolo, $r2 in Simbolo) =
		//wild con doppio simbolo
		if $r1=$r2 then
			r_wildDoppioSimbolo[$r1]
		else
			//doppio wild
			if $r1=WILD then
				r_doppioWild[$r2]
			else
				if $r2=WILD then
					r_doppioWild[$r1]
				endif
			endif	
		endif
		
		
	//gestione spin
	macro rule r_spin($r1 in Simbolo, $r2 in Simbolo) =
		if $r1 = $r2 and $r1 = SPIN then		//tris di spin
			spinOmaggio := spinOmaggio + 3n
		else
			if $r1 = SPIN or $r2 = SPIN then	//coppia di spin
				spinOmaggio := spinOmaggio + 2n
			else
				spinOmaggio := spinOmaggio + 1n	//unico spin
			endif
		endif
		
	
	//verifica se uno dei simboli è uno spin o uno wild
	macro rule r_checkSpecial($sp in Simbolo) =
		if rullo1 = $sp then
			switch($sp)
				case WILD:
					r_wild[rullo2, rullo3]
				case SPIN:
					r_spin[rullo2, rullo3]
			endswitch
		else
			if rullo2 = $sp then
				switch($sp)
					case WILD:
						r_wild[rullo1, rullo3]
					case SPIN:
						r_spin[rullo1, rullo3]
				endswitch
			else
				if rullo3 = $sp then
					switch($sp)
						case WILD:
							r_wild[rullo1, rullo2]
						case SPIN:
							spinOmaggio := spinOmaggio + 1n	//unico spin
					endswitch
				endif
			endif
		endif

	
	//main rule, blocco principale di gestione
	main rule r_Main =
	
		if(spin=30 or portafoglio<=0 or cassaSlot<=0) then
			risultato := getRisultato
		else
			seq
				spin := spin + 1
				
				if spinOmaggio > 0n then
					seq
						spinOmaggio := iton(spinOmaggio - 1n)	
						puntataS := 20
					endseq
				else
					seq
						r_updateVincita[-puntata]
						puntataS := puntata
					endseq
				endif
		
				choose $sa1 in SimboloAss, $sa2 in SimboloAss, $sa3 in SimboloAss with true do
					par
						rullo1 := second($sa1)
						rullo2 := second($sa2)
						rullo3 := second($sa3)
					endpar
	
				if rullo1 = rullo2 and rullo2 = rullo3 then
					r_tris[rullo1]
				else
					if rullo1 = WILD or rullo2 = WILD or rullo3 = WILD then
						r_checkSpecial[WILD]
					endif
				endif

				if rullo1 = SPIN or rullo2 = SPIN or rullo3 = SPIN then
					r_checkSpecial[SPIN]
				endif
			endseq
		endif


default init s0:
	
	function portafoglio = 100	//il giocatore parte con 300€
	function cassaSlot = 3000	//la slot parte da 3000€ (massima somma in vincita)
	function guadagno = 0	
	function spin = 0
	function spinOmaggio = 0n