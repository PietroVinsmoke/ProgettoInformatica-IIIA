object Main {
  def main(args: Array[String]): Unit = {
    
    //aggiungo personaggi alla lista del gestore del gioco
    Gestore.addPersonaggio( Umano("Pietro", 13) )
    Gestore.addPersonaggio( Guerriero("Aragorn") )  //con forza default
    Gestore.addPersonaggio( Stregone("Gandalf", 7) )   
    Gestore.addPersonaggio( Orco("Rubio", 10) )
    Gestore.addPersonaggio( Elfo("Legolas") )       //con forza default
    
    //lista di personaggi tramite companion e anche forza default
    val lista: List[Personaggio] = 
      List(Stregone("Saruman"), Elfo("Elrond", 26), Guerriero("Boromir"))
      
    //aggiungo i personaggi della lista alla lista del gestore del gioco
    Gestore.addListaPersonaggi(lista)
    
    //visualizzo la lista
    Gestore.stampaLista
    
    //faccio combattere qualcuno
    Arena.combattimento(3, 6)
    Arena.combattimento(4, 2)
    Arena.combattimento(7, 8)
    
    //visualizzo la lista aggiornata
    Gestore.stampaLista
    
    //attivo le specialità dei personaggi rimanenti
    Gestore.getPersonaggio(1).specialita
    Gestore.getPersonaggio(2).specialita
    Gestore.getPersonaggio(3).specialita
    Gestore.getPersonaggio(5).specialita
    Gestore.getPersonaggio(7).specialita
    
    //visualizzo la lista aggiornata
    Gestore.stampaLista
    
    //faccio combattere qualcuno (anche con se stesso e anche pareggiando)
    Arena.combattimento(1, 1)
    Arena.combattimento(3, 5)
    Arena.combattimento(2, 1)
    Arena.combattimento(5, 7)
    
    //visualizzo la lista aggiornata
    Gestore.stampaLista
    
    //ultimi combattimenti + specialità
    Gestore.getPersonaggio(2).specialita
    Arena.combattimento(2, 7)
    Gestore.getPersonaggio(3).specialita
    Gestore.getPersonaggio(3).specialita
    
    Gestore.stampaLista
    
    //sbaglio apposta
    Arena.combattimento(7, 1)
    
    Gestore.stampaLista
    
    //ultimo scontro
    Arena.combattimento(7, 3)
    
    Gestore.stampaLista
    
  }
}