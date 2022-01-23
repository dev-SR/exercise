fun printNext(): () -> Unit {
    var counter = 0
    return fun() {
        counter++
        println(counter)
    }
}

fun main() {
    /*
    * The following closure function(`forEach`) is a high order function that
    * calculates the sum of all elements of the list and updates a property
    * defined outside the closure(`main`).
    * */
    var res = 0
    var myList = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    myList.forEach { res += it }
    println(res) //

    val fn = printNext()
    fn()
    fn()
    fn()
}