fun main() {
    val f0: (Int, Int) -> Int = { x: Int, y: Int -> x + y }
    println(f0(1, 2))
    val f1 = { x: Int, y: Int -> x + y }
    // val f2 = { x, y-> x + y }
    // [error] Cannot infer a type for this parameter. Please specify it explicitly.
    val f: (Int, Int) -> Int = { x, y -> x + y }

    //minimal lambda expression
    val f2 = { 2 }
    println(f2())//2

    // last line is return value
    val f3 = { x: Int ->
        println(x)

        x * 2 //return value
    }
    println(f3(3))

    // `it` for single parameter
    //val f4 : (String) -> Int = { s: String -> s.length }
    val f4: (String) -> Int = { it.length }
    println(f4("abc"))

    // passing lambda as argument
    Callback(10, { x -> println(x) })
    Callback(10) { x -> println(x) }
    //same as above; Lambda argument should be moved out of parentheses

    //ex
    val calculateGrade = { grade: Int ->
        when (grade) {
            in 0..40 -> "Fail"
            !is Int -> "Just a grade"
            in 41..70 -> "Pass"
            in 71..100 -> "Distinction"
            else -> false
        }
    }
    println(calculateGrade(57))

}

fun Callback(x: Int, fn: (Int) -> Unit) {
    fn(x + 1)
}