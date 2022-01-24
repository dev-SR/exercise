open class Person2 {
    fun walk() {
        println("Person is walking")
    }

    fun sleep() {
        println("Person is sleeping")
    }

    open fun talk() {
        println("Person is talking")
    }

}

fun startTalking(person: Person2) {
    person.talk()
}

fun main() {
    startTalking(object : Person2() { //not new Person()
        override fun talk() {
            println("I am talking")
        }
    })

}