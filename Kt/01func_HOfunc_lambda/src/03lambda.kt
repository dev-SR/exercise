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
    OnlyCallback({ x -> println(x) })
    OnlyCallback({ println(it) })
    OnlyCallback { println(it) }

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

    //custom sorting using lambda
    val names = arrayOf("ZZZZZZ", "BB", "A", "CCCC", "EEEEE")
    println(names.sorted())  // [A, BB, CCCC, EEEEE, ZZZZZZ]

    val sortByName = names.sortedWith(compareBy({ -it.length }))
    println(sortByName)

    // Working with Collections
    val values = listOf(1, 2, 3, 4, 5, 6)
    values.forEach {
        println("$it: ${it * it}")
    }
//    values.forEach({ i: Int ->
//        println("$i: ${i * i}")
//    })
/*
1: 1
2: 4
3: 9
4: 16
5: 25
6: 36
*/

    var prices = listOf(1.5, 10.0, 4.99, 2.30, 8.19)
    val largePrices = prices.filter {
        it > 5.0
    }
    println(largePrices)//[10.0, 8.19]

    val salePrices = prices.map {
        it * 0.9
    }
    println(salePrices)//[1.35, 9.0, 4.4910000000000005, 2.07, 7.3709999999999996]

    prices = listOf(1.0, 2.0, 3.0, 4.0)
    var sum = prices.fold(5.0) { a, b ->
        a + b
    }
    println(sum) // 15.0

    var sum2 = prices.reduce { a, b ->
        a + b
    }
    println(sum2) // 10.0
    

}

fun Callback(x: Int, fn: (Int) -> Unit) {
    fn(x + 1)
}

fun OnlyCallback(fn: (Int) -> Unit) {
    fn(10)
}