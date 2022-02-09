//arena di combattimento
object Arena {
  
  //combattimento tra due personaggi
  def combattimento(id1: Int, id2: Int): Unit = {
    
    var p1 = Gestore.getPersonaggio(id1)
    var p2 = Gestore.getPersonaggio(id2)
    
    //se almeno uno dei personaggi non esiste
    if(p1 == null || p2 == null){
      println("--- Combattimento non possibile, almeno uno dei due personaggi non esiste!")
      println
      return
    }
    
    //se i due personaggi coincidono
    if(p1.ID == p2.ID){
      println("--- " + p1.nick + " non è così ubriaco da combattere contro se stesso!")
      println("--- Ancora in gioco!")
      println
      return
    }
    
    //se vince il personaggio 1
    if(p1.forza > p2.forza){
      
      println("--- " + p1.nick + " ha sconfitto " + p2.nick + "!")
      println("--- La forza di " + p1.nick + " è incrementata di 5 punti!")
      
      Gestore.delPersonaggio(p2.ID)  //elimino il personaggio 2 dalla lista
      p1.forza_=(p1.forza + 5)       //incremento la forza del personaggio 1 di 5 punti
     
      return
    }
    
    //se vince il personaggio 2
    if(p2.forza > p1.forza){
     
      println("--- " + p2.nick + " ha sconfitto " + p1.nick + "!")
      println("--- La forza di " + p2.nick + " è incrementata di 5 punti!")
      
      Gestore.delPersonaggio(p1.ID)  //elimino il personaggio 1 dalla lista
      p2.forza_=(p2.forza + 5)       //incremento la forza del personaggio 2 di 5 punti
      
      return
    }
    
    //pareggio
    println("--- " + p1.nick + " e " + p2.nick + " hanno pareggiato!")
    println("--- Entrambi ancora in gioco!")
    println
     
  }
  
}