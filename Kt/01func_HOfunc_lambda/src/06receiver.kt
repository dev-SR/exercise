import java.util.*

/**
 * Extension function. Here, String is known as receiver type.
 * That means, we can call this function on any String.
 * The extension function can be called only from the
 * class where it is defined.
 */
fun String.thankYou() {
    //We can access an instance of the receiver type using `this` keyword inside the business logic.
    println("Thank You $this")
}


fun ReceiverEx(init: String, fn: StringBuilder.() -> Unit) {
    var receiver: StringBuilder = StringBuilder(init)
    var res = receiver.fn()
    println(res.toString())
}

class Robot(val name: String) {
    private var strength: Int = 0
    private var health: Int = 100
    var isAlive: Boolean = true

    init {
        strength = Random().nextInt(100) + 10
        report("Created (strength $strength)")
    }

    fun report(message: String) {
        println("$name: \t$message")
    }
}

class Dummy(val name: String) {
    fun print(message: String) {
        println("$name: \t$message")
    }
}

fun testReceiver(fn: (Dummy) -> Unit) {
    var dummy: Dummy = Dummy("A")
    fn(dummy)
}

fun callback(receives: Dummy) {
    receives.print("Hello")
}
// How Can We define(Type) this callback function?
// -> that it takes a Dummy(Dummy is a receiver type) and returns nothing!!
// -> Dummy.() -> Unit

fun callback1(receives: Dummy, x: String) {
    receives.print("Hello")
    println(x)
}
// How Can We define(Type) this callback function?
// -> that it takes a Dummy(Dummy is receiver type),and String as parameter and returns nothing!!
// -> Dummy.() -> Unit

fun testReceiver1(fn: Dummy.() -> Unit) {
    var dummy: Dummy = Dummy("A")
    // Now I know Dummy is a receiver type......and fn is a function that can be called on Dummy
    // So, I can call fn on dummy instead of fn(dummy)
    //fn(dummy)
    dummy.fn()
}
fun testReceiver2(fn: Dummy.(String) -> Unit) {
    var dummy: Dummy = Dummy("A")
    dummy.fn("More")
}



fun main() {
    "Soikat".thankYou()//Thank You Soikat

    testReceiver(::callback)
    testReceiver1(::callback)

    testReceiver2(::callback1)


    ReceiverEx("Hello") {
        this.append(" World")
    }

    val appendS: StringBuilder.() -> StringBuilder = { this.append("s") }
    val s = StringBuilder("The Boy").appendS()
    // StringBuilder.appendS() >> this.append("s") -> StringBuilder
    println(s.toString())//The Boys
//    Again, this refers to the StringBuilder object, so we omit it:
    val appendS1: StringBuilder.() -> StringBuilder = { append("s") }
    val ss = StringBuilder("The Boy").appendS1()
    println(ss.toString())


    val appendX: StringBuilder.(String) -> StringBuilder = { this.append(it) }
    val x = StringBuilder("The Boy").appendX("x")
    //StringBuilder.appendX(String) >> this.append("s") -> StringBuilder
    println(x.toString())//The Boyx

    val extendInt: Int.() -> Double = { (this).toDouble() }
    val a = 10
    println(a.extendInt())//10.0
    // Int.extendInt() >> this.toDouble() -> Double

    val printSum: Int.(Int) -> Unit = { println("The sum of $this and $it is ${this.plus(it)}") }
    val b: Int = 6
    b.printSum(7)//The sum of 6 and 7 is 13
    // Int.printSum(Int) >> println("The sum of $this and $it is ${this.plus(it)}") -> Unit

    // with Anonymous function and without `this` keyword
    val printSum1: Int.(Int) -> Unit =
        fun Int.(num: Int): Unit { println("The sum of $this and $num is ${plus(num)}") }
//        fun Int.(num: Int): Unit = println("The sum of $this and $$num is ${plus(num)}")
    val y = 6
    y.printSum1(5)//The sum of 6 and 5 is 11

}