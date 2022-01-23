//Passing functions:a Callback
fun performOperation(x: Int, y: Int, cbFn: (Int, Int) -> Int) {
    val result = cbFn(x, y)
    println("Result of $x and $y is : $result")
}

fun getSum(x: Int, y: Int): Int {
    return x + y
}

//Returning a functions: Higher order function
// high order function = fun with fun or fun returns a fun
fun add(a: Int, b: Int): Int {
    return a + b
}

fun returnAddFunction(): ((Int, Int) -> Int) {
    return ::add
//    return fun(a: Int, b: Int): Int {
//        return a + b
//    }
//    return { a, b -> a + b }

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
    // by lambda
    performOperation(2, 4, { x, y -> y - x })
    // lambda - can be moved outside of parameter
    performOperation(2, 5) { x, y -> y - x }
    // by anonymous
    performOperation(2, 4, fun(x: Int, y: Int): Int = x * x)
    // by :: function reference
    performOperation(2, 4, ::getSum)
    // Watch Out the difference between getSum2 and ::getSum
    val getSum2 = { x: Int, y: Int -> x + y }
    performOperation(2,4,getSum2)
    // getSum is a function - that is passed as function reference
    // getSum2 is a variable that holds a function
    // Also
    val getSum3 = fun (x: Int, y: Int): Int {
        return x + y
    }
    performOperation(2,4,getSum3)
    val f: ((Int, Int) -> Int) = returnAddFunction()
    println("Result is : ${f(2, 3)}")

    printSum(2, 4) { x, y -> x + y }
}
