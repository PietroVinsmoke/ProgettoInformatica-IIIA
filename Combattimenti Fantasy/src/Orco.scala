//Personaggio di classe Orco

class Orco (override val nick: String, override var forza: Int = 15) extends Personaggio{
  
  //classe del personaggio
  override val classe = "Orco"
  
  //specialità dell'orco
  private def caccia: Unit = {
    println("--- " + nick + " va a caccia! Forza incrementata di 3!")
    println
    forza += 3
  }
  
  //chiama la specialità del personaggio
  override def specialita = caccia

}



//companion per l'istanziamento di un orco
object Orco{
  
  //nel caso siano specificati sia nick che forza
  def apply(nick: String, forza: Int): Orco = {
    var o = new Orco(nick, forza);
    o
  }
  
  //nel caso sia specificato solo il nick
  def apply(nick: String): Orco = {
    var o = new Orco(nick);
    o
  }
}