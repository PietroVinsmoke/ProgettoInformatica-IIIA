//Personaggio di classe Elfo

class Elfo (override val nick: String, override var forza: Int = 20) extends Personaggio {
  
  //classe del personaggio
  override val classe = "Elfo"
  
  //specialità dell'elfo
  private def medita: Unit = {
    println("--- " + nick + " sta meditando! Forza incrementata di 2!")
    println
    forza += 2
  }
  
  //chiama la specialita specifica della persona
  override def specialita = medita

}



//companion per l'istanziamento di un elfo
object Elfo{
  
  //nel caso siano specificati sia nick che forza
  def apply(nick: String, forza: Int): Elfo = {
    var o = new Elfo(nick, forza);
    o
  }
  
  //nel caso sia specificato solo il nick
  def apply(nick: String): Elfo = {
    var o = new Elfo(nick);
    o
  }
}