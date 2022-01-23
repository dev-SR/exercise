fun main() {
    //Function Types
    var f0: () -> Unit
    var f1: (Int, Int) -> Int
    var f2: (Int, Int) -> Boolean
    //nullable
    var f3: ((String) -> Int)?


    //Assignment
    //Declaration
    f0 = fun() {
        println("Hello")
    }
    f1 = fun(a: Int, b: Int): Int {
        return a + b
    }
    f2 = fun(a: Int, b: Int): Boolean {
        return a > b
    }
    f3 = fun(s: String): Int {
        return s.length
    }

    // Function Call
    println(f3("Hello"))
    println(f3.invoke("Hello"))//using invoke
    f3 = null
    f3?.invoke("Hello")



    // Other type of Function Declarations
    //Function references
    f1 = ::addInt
    //Function literal - lambda
    f2 = { a: Int, b: Int -> a > b }
    //Function literal - anonymous function
    f3 = fun(s: String): Int { return s.length }
}

fun addInt(a: Int, b: Int): Int {
    return a + b
}