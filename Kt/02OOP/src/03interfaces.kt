interface Footballer {
    val pos: String
    fun dribble()
    fun kick() {
        println("Kick the football")
    }
}

open class Person1(val name: String)

class Student1(name: String, override val pos: String) : Person1(name), Footballer {
    override fun dribble() {
        println("Dribble the ball")
    }
}

fun playFootball(footballer: Footballer){
    footballer.dribble()
    footballer.kick()
}
fun printName(person: Person1){
    println("Person name is: ${person.name}")
}

fun main() {
    val student = Student1("Jhon", "Sticker")
    playFootball(student)
    printName(student)
}

//Dribble the ball
//Kick the football
//Person name is: Jhon