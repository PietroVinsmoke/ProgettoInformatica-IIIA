//Personaggio di classe: Umano
class Umano (override val nick: String, override var forza: Int = 10) extends Personaggio{
 
  //classe del personaggio
  override val classe = "Umano"
  
  //specialità dell'umano
  private def allenamento: Unit = {
    println("--- " + nick + " si allena! Forza incrementata di 4!")
    println
    forza += 4
  }
  
  //chiama la specialità del personaggio
  override def specialita = allenamento

}

//Personaggio di classe: Guerriero
class Guerriero (nick: String, f: Int = 13) extends Umano (nick, f) {
  
  //classe del personaggio
  override val classe = "Guerriero"
  
  //specialità del guerriero
  private def allenamento = {
    println("--- " + nick + " si allena con la spada! Forza incrementata di 6!")
    println
    forza += 6
  }
  
  //chiama la specialità del personaggio
  override def specialita = allenamento
  
}


//Personaggio di classe: Stregone
class Stregone (nick: String, f: Int = 2) extends Umano (nick, f) {
  
  //classe del personaggio
  override val classe = "Stregone"
  
  //specialità dello stregone
  private def allenamento = {
    println("--- " + nick + " usa una stregoneria! Forza incrementata di 10!")
    println
    forza += 10
  }
  
  //chiama la specialità del personaggio
  override def specialita = allenamento
  
}


//companion per l'istanziamento di un umano
object Umano{
  
  //nel caso siano specificati sia nick che forza
  def apply(nick: String, forza: Int): Umano = {
    var u = new Umano(nick, forza);
    u
  }
  
  //nel caso sia specificato solo il nick
  def apply(nick: String): Umano = {
    var u = new Umano(nick);
    u
  }
}


//companion per l'istanziamento di un guerriero
object Guerriero{
  
  //nel caso siano specificati sia nick che forza
  def apply(nick: String, forza: Int): Guerriero = {
    var g = new Guerriero(nick, forza);
    g
  }
  
  //nel caso sia specificato solo il nick
  def apply(nick: String): Guerriero = {
    var g = new Guerriero(nick);
    g
  }
}


//companion per l'istanziamento di uno stregone
object Stregone{
  
  //nel caso siano specificati sia nick che forza
  def apply(nick: String, forza: Int): Stregone = {
    var m = new Stregone(nick, forza);
    m
  }
  
  //nel caso sia specificato solo il nick
  def apply(nick: String): Stregone = {
    var m = new Stregone(nick);
    m
  }
}
