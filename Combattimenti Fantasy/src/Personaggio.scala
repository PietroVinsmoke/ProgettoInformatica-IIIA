//classe astratta per la definizione di un personaggio
abstract class Personaggio extends Specialita{
  
  //ID univoco del personaggio
  private val _ID = Personaggio.getID
  //nickname personaggio
  private val _nick = ""
  //classe del personaggio
  private val _classe = ""
  //forza personaggio
  private var _forza = 0
  
  //getters
  def ID = _ID
  def nick = _nick
  def classe = _classe
  def forza = _forza
  
  //setter forza
  def forza_= (newForza: Int) = _forza += newForza
  
  //stampa le info del personaggio
	def printP: Unit = println("ID: " + ID + "\t|   " 
	    + nick + ", " + classe + ", punti forza: " + forza)
  
}


object Personaggio{
  //riferimento per assegnare un ID univoco ai personaggi
  var ID_ref = 0
  
  //incrementa il riferimento per l'ID e lo restituisce per l'assegnamento al personaggio
  def getID: Int = {
    ID_ref += 1
    ID_ref
  }
}