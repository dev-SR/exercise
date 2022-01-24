class Employee {
    var firstName: String? = null
    var age: Int = 0
}


fun main(args: Array<String>) {
    var str = "Hello World"
    str.let { println("$it!!") }//Hello World!!

    val employee: Employee? = Employee()
    employee?.firstName = "Suneet"
    employee?.age = 27

    employee?.let {
        println(it.age)
    }
    employee?.let { person ->
        person.firstName?.let { name ->
            println(name)
        }
    }
    employee?.firstName?.let (::println)
    var list = mutableListOf(6, 1, 5, 2, 4, 3)
    list.filter { it % 2 == 0 }.sortedBy { it }.let {
        println("Sorted even numbers are : $it")
    }

    var strLength = str.let {
        println("$it!!")//Hello World!!
        "$it function".length
    }
    println("strLength is $strLength") //prints strLength is 25


    var a = 1
    var b = 2

    a = a.let { it + 2 }.let {
        val i = it + b
        i//returns
    }
    println(a) //5


    var x = "X"
    x.let { outer ->
        outer.let { inner ->
            println("Inner is $inner and outer is $outer")
            //Inner is X and outer is X
        }
    }
    var y = "Y"
    y = y.let { outer ->
        outer.let { inner ->
            println("Inner is $inner and outer is $outer")//Inner is Y and outer is Y
            "Kotlin Tutorials Inner let"
        }
        "Kotlin Tutorials Outer let"
    }
    println(y) //prints Kotlin Tutorials Outer let


    var name : String? = "Kotlin let null check"
    name?.let { println(it) } //prints Kotlin let null check
    name = null
//    name?.let { println(it) }

}
