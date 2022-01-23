fun performOperations(a: Int, b: Int, operation: (Int, Int) -> Int) {
    val result = operation(a, b)
    println("Result is: $result")
}

fun sum2(a: Int, b: Int): Int {
    return a + b
}

fun main() {
    //has a explicit return type
    //the 'return' works normally
    val sum = fun(a: Int, b: Int): Int = a + b
    performOperations(1, 2, sum)
    //vs "::sum"
    performOperation(1, 2, ::sum2)
    /*
        Watch Out!! `sum` is a `variable` that store anonymous function,
        which is not a function itself.
        whereas, `sum2` is a `function` which is passed as reference by `::' operator
    */

    //passed inside the parameter
    performOperation(1, 2, fun(x, y) = x - y)
}