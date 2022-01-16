fun var_val() {
    val a: String = "Hello World"
    val b: Int = 10
    val c: Boolean = true
    val d: Float = 10.0F
    val e: Double = 10.9

    println(a)

    // [01] Changing value of variables declared by `val`:

    // [01.1] !!Val cannot be reassigned!!
    // a = "Hello Kotlin" [error]
    // println(a)

    // [01.2] !!Val can be reassigned
    var v: String = "Hello World"
    println(v)
    v = "Hello Kotlin"
    println(v)
}


// Late Initialization:
//var l: String //  [error]: Property must be initialized
// 1. One way of achieving this is by assigning a `dummy value` to the variable like this:
var l1: String = ""

// 2. One way of achieving this is by making the variable `nullable` like this:
var l2: String? = null

// 3. The `lateinit` keyword is used for late initialization of variables.
lateinit var l3: String


fun lateInit() {
    l1 = "Hello World"
    println(l1)
    l2 = "Hello"
    println(l2)
    l3 = "Hello World"
    println(l3)

    var l4: String
    //Can be joined with assignment
    //var l4:String = "Hello World"
    println("..........")
    l4 = "Hello World"
    println(l4)

    lateinit var l5: String
    l5 = "Hello World"
    //Can be joined with assignment
    //var l5:String = "Hello World"
    println(l5)

}

// Null Safety:
fun NullSafety() {
    // Nullable Types: Type?
    var s1: String = "Hello World"
    //s1 = null // compilation error
    var s2: String? = "Hello World"
    s2 = null // compiler error because string can be null
    println(s2)


    /**
     * Not null assertion : `!!` Operator
     * **/
    var s3: String? = null
    var size1 = s3?.length
    println("size: any $size1")

    // var size2: Int = s3?.length // [error]
    /**
     * Type mismatch.
     * Required:
     * Int
     * Found:
     * Int?
     * **/
//    var size2: Int = s3?.length!! // non-null asserted call
    //Exception in thread "main" kotlin.KotlinNullPointerException
}

fun checkNullSafety() {
    var s: String? = "Hello World"
    if (s != null) {
        println("String of length ${s.length}")//String of length 11
    } else {
        println("Null string")
    }
    // assign null
    s = null
    println(s)//null
    if (s != null) {
        println("String of length ${s.length}")
    } else {
        println("Null String") //Null String
    }

    // Using Safe Call operator(?.)
    var name: String? = null
    println("Null call:...")
    println(name?.toUpperCase())
    /*  is equivalent to:
        if(name != null)
            name.toUpperCase()
        else
            null
    */



}

fun Elvis() {
    var s: String? = null
    var size: Int = s?.length ?: 0
    println(size)//0
    s = "Hello World"
    size = s?.length ?: 0
    println(size)//11


}

fun main() {
    var n = "Soikat"
    println("This is " + n.capitalize() + ", len: ${n.length}")
    var_val()
    lateInit()
    NullSafety()
    println()
    checkNullSafety()
    println()
    Elvis()
}