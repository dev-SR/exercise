import java.util.*

//data class User(var name: String, var address: String)
fun asExtension() {
    var user:User? = null
    user?.run {
        name = "John"
        name
    }
    println(user)//null
    user = User("a","London")
    val username = user?.run {
        name = name.uppercase(Locale.getDefault())
        name
    }
    println(username)//A
}

fun asFunction() {
    val alphaNumeric = run {
        val digits = "0-9"
        val aplhabets = "A-Za-z"

        Regex("[$digits$aplhabets]+")
    }
    //digits = ".."//error

    for (match in alphaNumeric.findAll("+1234 -FFFF I-am?-a!string?!")) {
        println(match.value)
    }
}
fun main() {
    asExtension()
    asFunction()


    var p : String? = null
    p?.let { println("p is $p") } ?: run {
        println("p was null. Setting default value to: ")
        p = "Kotlin"
    }

    println(p) //Kotlin

}


