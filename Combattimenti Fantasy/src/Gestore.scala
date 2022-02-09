import scala.collection.mutable.LinkedHashMap

//gestisce i personaggi in gioco tramite una lista
object Gestore {
  
  //lista dei personaggi
  private var listaPersonaggi: LinkedHashMap[Int, Personaggio] = LinkedHashMap()
  
  //aggiunge un personaggio a listaPersonaggi
  def addPersonaggio(p: Personaggio) = listaPersonaggi.put(p.ID, p)
  
  //aggiunge una lista di personaggi a listaPersonaggi
  def addListaPersonaggi(lista: List[Personaggio]) = lista.foreach(p => addPersonaggio(p))
  
  //restituisce il personaggio corrispondente all'ID passato
  def getPersonaggio(id: Int): Personaggio = listaPersonaggi.getOrElse(id, null)
  
  //elimina un personaggio da listaPersonaggi in base all'ID
  def delPersonaggio(id: Int) = {
    //se il personagio non esiste
    if(getPersonaggio(id) == null){
      println("--- Personaggio con ID " + id + " inesistente, impossibile eliminare!")
      println
    }
    //altrimenti
    else{
      println("--- " + getPersonaggio(id).nick + " eliminato dal gioco!")
      println
      //elimino il personaggio dalla lista
      listaPersonaggi = listaPersonaggi - id  
    }
  }
  
  //stampa listaPersonaggi
  def stampaLista = {
    println("___________________________________________________________")
    println
    listaPersonaggi.foreach{case (id, p) => p.printP}
    println("___________________________________________________________")
    println
  }
  
  
}