//Function Argument and Return Type
fun square(number: Int): Int {
    return number * number
}

fun square1(n: Int): Int = n * n
fun square2(n: Int): Int = if (n > 0) n * n else -1

//Default argument
fun displayTitleAndName(name: String = "John", title: String = "Dr.") {
    println("$title $name")
}

// Named argument
fun student( name: String="Rahim", student_id: Int=191902061) {
    println("$name $student_id")
}

// functions with varargs parameters
fun varargExample(vararg names: Int) {
    print("Argument has ${names.size} elements: ")
    names.forEach { print("$it, ") }
    println()
}
fun main() {
    println(square(2))
    println(square1(2))
    println(square2(0))
    // passing no arguments while calling student
    displayTitleAndName()//Dr. John
    //passing Partial arguments
    displayTitleAndName("Karim")//Dr. Karim
    ///passing all the arguments
    displayTitleAndName("Karim", "Mr.")//Mr. Karim

    // calling student() by passing arguments in random order-
//    student(191, "Rahim")
    //Kotlin: The integer literal does not conform to the expected type String
    student(student_id = 191, name = "Karim")//Karim 191

    // functions with varargs parameters
    varargExample() // => Argument has 0 elements:
    varargExample(1) // => Argument has 1 elements:1,
    varargExample(1, 2, 3) // => Argument has 3 elements: 1, 2, 3
}