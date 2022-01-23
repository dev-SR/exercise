//Passing a Callback functions:

// higher order function
fun performOperation(x: Int, y: Int, cbFn: (Int, Int) -> Int) {
    val result = cbFn(x, y)
    println("Result of $x and $y is : $result")
}

fun getSum(x: Int, y: Int): Int {
    return x + y
}

//returning a functions:
fun getLength(): (String) -> Int {
    return fun(s: String): Int {
        return s.length
    }
    // return {s:String -> s.length}
    // return ::fn
}


// Using Type Alias
typealias addFunctionType = (Int, Int) -> Int
typealias sumResult = Int
//fun printSum(x: Int, y: Int, fn: (Int, Int) -> Int) {
fun printSum(x: Int, y: Int, fn: addFunctionType) {
    val sum: sumResult = fn(x, y)
    println("Sum of $x and $y is: $sum")
}

fun main() {
    //pass function as parameter:
    // by :: function reference
    performOperation(2, 4, ::getSum)
    // by lambda
    performOperation(2, 4, { x, y -> y - x })
    // lambda - can be moved outside of parameter
    performOperation(2, 5) { x, y -> y - x }
    // by anonymous
    performOperation(2, 4, fun(x: Int, y: Int): Int = x * x)


    val f: (String) -> Int = getLength()
    println("Length is : ${f("Mark")}")

    printSum(2, 4) { x, y -> x + y }
}