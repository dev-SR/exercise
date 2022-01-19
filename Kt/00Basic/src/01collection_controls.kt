fun Arr() {
    Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Arrays")
    val numbers = arrayOf(1, 2, 3, 4)
    val numInt = intArrayOf(1, 2, 3, 4)
    val nullArray = arrayOfNulls<Int>(5)
    val numbersZero = Array(4) { 0 }
    val numberSquared = Array(5, { i -> i * i })

    val anyType = arrayOf("A", "B", "C", 4) // we haven't defined the type
    //val StringType = arrayOf<String>("A","B","C",4) //error
    val StringType = arrayOf<String>("A", "B", "C")

    println(numbers.joinToString(","))
    println(numInt.joinToString(","))
    println(nullArray.joinToString(","))
    println(numbersZero.joinToString(","))
    println(numberSquared.joinToString(","))
    println(anyType.joinToString(","))
    println(StringType.joinToString(","))

    Color.printMsg(Color.GREEN_BRIGHT, "access:")
    println("numbers[0] = ${numbers[0]}")
    println("numbers[1] = ${numbers.get(1)}")

    Color.printMsg(Color.GREEN_BRIGHT, "set value:")
    numbers.set(3, 10)
    numbers[1] = 20
    println("ar.set(i,v) ; ar[i] = v")
    println(numbers.joinToString(","))//1,20,3,10,10


    Color.printMsg(Color.GREEN_BRIGHT, "indexOf:")
    println("indexOf(x) = ${numbers.indexOf(10)}")//3


    Color.printMsg(Color.GREEN_BRIGHT, "plus")
    val newArrPlusX = numbers.plus(10)
    println(newArrPlusX.joinToString(",")) //1,20,3,10,10

}

fun conditions() {
    Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Conditions")
    var discount = 0
    val price = 100
    // if - else
    if (price > 100) {
        discount = 10
    } else {
        discount = 3
    }
    //
    discount = if (price > 100) 10 else 3
    println("discount = $discount")

    // Switch  -> when
    Color.printMsg(Color.GREEN_BRIGHT, "when:")
    val result = when (7) {
        in 7..10 -> "Excellent"//7≤𝑥≥10
        5, 6 -> "Good"
        3, 4 -> "Pass"
        1, 2, 0 -> "Fail"
        else -> {
            println("Invalid Rating")
            "Invalid"
        }
    }
    println("result = $result")
}

fun Loops() {
    Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Loops")
    Color.printMsg(Color.GREEN_BRIGHT, "for:")
    val items = arrayOf("A", "B", "C", "D", "E")

    //For loop
    for (item in items) {
        print("$item, ")//A, B, C, D, E,
    }
    println()
    for (i in items.indices) {
        print("${items[i]}, ")//A, B, C, D, E,
    }
    println()


    //forEach
    Color.printMsg(Color.GREEN_BRIGHT, "forEach:")
    items.forEach { item -> print("$item, ") } //A, B, C, D, E,
    println()
    items.forEach { print("$it, ") }//A, B, C, D, E,
    println()
    items.forEachIndexed { index, value -> print("$index:$value|${items[index]}, ") }
    //0:A|A, 1:B|B, 2:C|C, 3:D|D, 4:E|E,
    println()


    //Range
    Color.printMsg(Color.GREEN_BRIGHT, "range:")
    for (i in 1..5) {//1<=..<=5  ; 5 is inclusive
        print("$i, ") //1, 2, 3, 4, 5
    }
    println()
    for (i in 1 until 5) {//1<=until<5 ; 5 is exclusive
        print("$i, ") //1, 3, 5, 7, 9
    }
    println()
    if (4 !in 5..10) {
        println("Not there..")
    }
    for (i in 1..10 step 2) {//1<=..<=10 step 2
        print("$i, ") //1, 3, 5, 7, 9,
    }
    println()
    for (i in 10 downTo 1 step 2) {//10>=..>=1 step 2
        print("$i, ") //10, 8, 6, 4, 2,
    }
    println()


    //While
    Color.printMsg(Color.GREEN_BRIGHT, "while:")
    var i = 0
    while (i < 5) {
        print("$i, ") //1, 3, 5, 7, 9,
        i++
    }
    println()
//    Color.printMsg(Color.CYAN_BRIGHT, "take input:")
    var name: String?
    do {
//        name = readLine()
        name = "Soikat"
        println("name = $name")
    } while (name == null)
}

fun collections() {
    Color.printStartWithMsg(20, Color.YELLOW_BRIGHT, "Collections")
    Color.printMsg(Color.GREEN_BRIGHT, "listOf:")
    //listOf
    var items = listOf("A", "B", "C", "D")
    println(items)
    println("1. The size of item = ${items.size}")
    println("2. items[1] = ${items[1]}")
    println("3. items.get(1) = ${items.get(1)}")
    println("4. indexOf('A') = ${items.indexOf("A")}")
    //[error]: items.add("X")// listOf is by default immutable

    Color.printMsg(Color.GREEN_BRIGHT, "mutableListOf:")
    items = mutableListOf("A", "B", "C", "D")
    println(items)//[A, B, C, D]
    Color.printMsg(Color.CYAN_BRIGHT, "     add")
    items.add("E")
    println(items)//[A, B, C, D, E]
    Color.printMsg(Color.CYAN_BRIGHT, "     removeAt(index)")
    items.removeAt(1)
    println(items)//[A, C, D, E]
    Color.printMsg(Color.CYAN_BRIGHT, "     remove(val)")
    var removed = items.remove("A")
    println(items)//[C, D, E]
    println("A removed?: $removed")//true
    removed = items.remove("Z")
    println(items)//[C, D, E]
    println("Z removed?: $removed")//false

    Color.printMsg(Color.CYAN_BRIGHT, "     set(i,v)")
    items.set(1, "Y")
    items[0] = "X"
    println(items)//[X, Y, E]


    Color.printMsg(Color.GREEN_BRIGHT, "Set:")
    var sets = setOf("A", "B", "C", "D", "D")
    println(sets)//[A, B, C, D]
    println("size: ${sets.size}")
    println("contains A?: ${sets.contains("A")}")//A
    //sets.add("ABC") [error]

    Color.printMsg(Color.GREEN_BRIGHT, "mutableSetOf:")
    sets = mutableSetOf("A", "B", "C", "D", "D")
    println(sets)//[A, B, C, D]
    Color.printMsg(Color.CYAN_BRIGHT, "     add()")
    sets.add("E")
    println(sets)
    Color.printMsg(Color.CYAN_BRIGHT, "     remove()")
    sets.remove("E")
    println(sets)


    Color.printMsg(Color.GREEN_BRIGHT, "HashMap:")
    var map = mapOf(1 to "A", 2 to "B", 3 to "C")
    //var map = hashMapOf(1 to "A", 2 to "B", 3 to "C")
    println(map)//{1=A, 2=B, 3=C}
    println("1. values: ${map.values}")//[A, B, C]
    println("2. keys: ${map.keys}")//[1, 2, 3]
    println("3. map.get(1) = ${map.get(1)}")//A
    println("4. map.getOrDefault(4, 'D') = ${map.getOrDefault(4, "D")}")//D
    println("5. map.getOrElse(4, {'D'}) = ${map.getOrElse(4) { 'D' }}")//D
    println("6. containsKey(1): ${map.containsKey(1)}")//true
    println("7. containsValue('A'): ${map.containsValue("A")}")//true
    //error:
    //   map.put(4, "D")

    Color.printMsg(Color.GREEN_BRIGHT, "mutableMapOf:")
    map = mutableMapOf(1 to "A", 2 to "B", 3 to "C")
    Color.printMsg(Color.CYAN_BRIGHT, "     put(key,value)")
    map.put(4,"E")
    println(map)//{1=A, 2=B, 3=C, 4=E}
    Color.printMsg(Color.CYAN_BRIGHT, "     remove(key)")
    map.remove(2)
    println(map)//{1=A, 3=C, 4=E}

}

fun main() {
    Arr()
    conditions()
    Loops()
    collections()
}