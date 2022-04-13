# Kotlin Fundamental

- [Kotlin Fundamental](#kotlin-fundamental)
  - [Creating new project with Intellij](#creating-new-project-with-intellij)
  - [String Concatenation using `+`, `$x` and `${x.y/y()}`](#string-concatenation-using--x-and-xyy)
  - [Declaring Variables in Kotlin](#declaring-variables-in-kotlin)
    - [`val` : cannot be reassigned](#val--cannot-be-reassigned)
    - [`var` : can be reassigned](#var--can-be-reassigned)
  - [Late initialization](#late-initialization)
  - [Null Safety in Kotlin](#null-safety-in-kotlin)
    - [Nullable References Types (`Type?`)](#nullable-references-types-type)
    - [Checking for `null` in conditions](#checking-for-null-in-conditions)
      - [Safe Call operator(`a?.b/b()`) : `If(!null)`, use it, otherwise **return null**](#safe-call-operatorabb--ifnull-use-it-otherwise-return-null)
      - [Elvis Operator(`x=a?:b`) : `if(!null)`, use `a`, else use `b`](#elvis-operatorxab--ifnull-use-a-else-use-b)
      - [Not null assertion (`!!`) Operator : `if(null)`, Throws `NullPointerException`](#not-null-assertion--operator--ifnull-throws-nullpointerexception)
  - [Array](#array)
  - [Conditions](#conditions)
    - [if condition](#if-condition)
    - [`when` in replacement of `switch`](#when-in-replacement-of-switch)
    - [Loops](#loops)
      - [`for` loop](#for-loop)
      - [`forEach` loop](#foreach-loop)
      - [`Range`-based for Loop](#range-based-for-loop)
      - [`while` loop](#while-loop)
  - [Collection](#collection)
    - [`listOf` - Immutable List](#listof---immutable-list)
    - [`mutableListOf`](#mutablelistof)
    - [`Set` - Immutable Set](#set---immutable-set)
    - [`mutableSetOf:`](#mutablesetof)
    - [`mapOf` - Immutable Map](#mapof---immutable-map)
    - [`mutableMapOf`](#mutablemapof)
  - [Collection Operations](#collection-operations)
    - [Ex1: map,find](#ex1-mapfind)

In Kotlin, Everything is an `Object`

In Java we have primitive data types and their counterpart `Wrapper` class. For example: `int` and `Integer`. We can't call functions on an `int` variable. In Kotlin we only have objects.**Although Primitive types are used but internally.**

## Creating new project with Intellij

- File > New > Project > Select `Java` and Check `Kotlin` as additional L&F. Or,
- File > New > Project > Select `Kotlin` and Console Application

## String Concatenation using `+`, `$x` and `${x.y/y()}`

```kotlin
    var n = "soikat"
    println("This is " + n.capitalize() + ", len: $n = ${n.length}")
    //This is Soikat, len: soikat = 6
```

## Declaring Variables in Kotlin

### `val` : cannot be reassigned

```kotlin
    val a: String = "Hello World"
    val b: Int = 10
    val c: Boolean = true
    val d: Float = 10.0F
    val e: Double = 10.9
    println(a)
```

reassigning `val` is not allowed:

```kotlin
 val a: String = "Hello World"
    a = "Hello Kotlin"
    println(a)
```

> Error: Val cannot be reassigned!!

### `var` : can be reassigned

```kotlin
 var v: String = "Hello World"
    println(v)
    v = "Hello Kotlin"
    println(v)
```

## Late initialization

There are many cases when you need to create a variable but you don't want to initialize it at the time of declaration/creation of the variable because you are sure that the variable will be initialized before its access/usage.

```kotlin
var v: String
fun main() {
 v = "Hello Kotlin"
}
```

In Kotlin Property must be initialized before being used.

> error: Property must be initialized

One way of achieving this is by assigning a `dummy value` to the variable like this:

```kotlin
var v: String = ""
fun main() {
 v = "Hello Kotlin"
 println(v)
}
```

One way of achieving this is by making the variable `nullable` like this:

```kotlin
var v: String? = null
fun main() {
 v = "Hello Kotlin"
 println(v)
}
```

The `lateinit` keyword is used for late initialization of variables.

```kotlin
lateinit var v: String
fun main() {
 v = "Hello Kotlin"
 println(v)
}
```

> NOTE: To use a `lateinit` variable, your variable should use `var` and NOT `val`. Lateinit is allowed for `non-primitive` data types only and the variable can't be of `null` type. Also, `lateinit` variable can be declared either inside the class or it can be a top-level property.

Usage of `lateinit`

- For late initialization of variables.
- For injecting an object using Dagger.

## Null Safety in Kotlin

Kotlin type system has distinguish two types of references that can hold `null` (`nullable` references) and those that can not (`non-null` references). A variable of type `String` **can not hold** `null`. If we try to assign `null` to the variable, it gives compiler error.

```kotlin
var s1: String = "Hello World"
    s1 = null // compilation error
```

### Nullable References Types (`Type?`)

To allow a variable to hold `null`, we can declare a variable as nullable string, written `String?`:

```kotlin
 var s2: String? = "Hello World"
    s2 = null
    println(s2)
```

But if we want to access the `length` of the string `s2`, that would not be safe, and the compiler reports an error:

```kotlin
 var s2: String? = null
    var s = s2.length //  compiler error because string can be null
```

### Checking for `null` in conditions

The most common way of checking null reference is using if-else expression. We can explicitly check if variable is null, and handle the two options separately.

```kotlin
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
```

#### Safe Call operator(`a?.b/b()`) : `If(!null)`, use it, otherwise **return null**

> WatchOut: `Safe Call Operator` is not same as Nullable Reference Types(`Type?`). see  [Nullable References Types (`Type?`)](#nullable-references-types-type)


Null Comparisons are simple but number of nested `if-else` expression could be burdensome. So, Kotlin has a Safe call operator, `?.` that reduces this complexity and execute an action only when the specific reference holds a `non-null` value. It allows us to combine a `null-check` and a method call in a single expression.

The following expression:

```kotlin
a?.b()
```

is equivalent to:

```kotlin
if(a != null){
    a.b()
}
else{
    return null
}
```

examples:

```kotlin
    var name: String? = "Soikat"
    println(name?.toUpperCase()) //SOIKAT

    var name: String? = null
    println(name?.toUpperCase()) //null
```

#### Elvis Operator(`x=a?:b`) : `if(!null)`, use `a`, else use `b`

The Elvis operator is used to return

- a `non-null` value or
- a `default value` when the original variable is null.

In other words, if left expression is not null then elvis operator returns it, otherwise it returns the right expression. The right-hand side expression is evaluated only if the left-hand side found to be null.
The following expression:

 The following expression:

```kotlin
x = a ?: b //b works as default value
```

is equivalent to:

```kotlin
x = if(a !== null) a else b
```

```kotlin
 var s:String? = null
    var size: Int = s?.length ?: 0
    println(size)//0
    s = "Hello World"
    size = s?.length ?: 0
    println(size)//11
```

#### Not null assertion (`!!`) Operator : `if(null)`, Throws `NullPointerException`

The not null assertion (`!!`) operator converts **`any` value to a `non-null` type** and **throws an exception** if the value is `null`. If anyone want `NullPointerException` then he can ask explicitly using this operator.

The following expression:

```kotlin
a!!.b()
```

is equivalent to:

```kotlin
if (a == null){
    throw NullPointerException()
}
else{
    a.b()
}
```

```kotlin
    /**
     * Not null assertion : `!!` Operator
     * **/
    var s3:String? = null
    var size1 = s3?.length
    println("size: any $size1")

    // var size2: Int = s3?.length // [error]
    /**
     * Type mismatch.
     * Required: Int
     * Found: Int?
     * **/
 // non-null asserted call
    var size2: Int = s3?.length!!
    //Exception in thread "main" kotlin.KotlinNullPointerException
```

## Array

```kotlin
    val numbers = arrayOf(1, 2, 3, 4)
    val numInt = intArrayOf(1, 2, 3, 4)
    val nullArray = arrayOfNulls<Int>(5)
    val numbersZero = Array(4) { 0 }
    val numberSquared = Array(5, { i -> i * i })

    val anyType = arrayOf("A", "B", "C", 4) // we haven't defined the type
    //val StringType = arrayOf<String>("A","B","C",4) //error
    val StringType = arrayOf<String>("A", "B", "C")

    println(numbers.joinToString(","))
    //..

    //access:
    println("numbers[0] = ${numbers[0]}")
    println("numbers[1] = ${numbers.get(1)}")

    //set value:
    numbers.set(3, 10)
    numbers[1] = 20
    println("ar.set(i,v) ; ar[i] = v")
    println(numbers.joinToString(","))//1,20,3,10,10


    //"indexOf:"
    println("indexOf(x) = ${numbers.indexOf(10)}")//3


    // "plus"
    val newArrPlusX = numbers.plus(10)
    println(newArrPlusX.joinToString(",")) //1,20,3,10,10

    // more...
```

## Conditions

### if condition

```kotlin
    var discount = 0
    val price  = 100
    // if - else
    if(price>100){
        discount = 10
    }else {
        discount = 3
    }
    //
    discount = if(price>100) 10 else 3
```

### `when` in replacement of `switch`

```kotlin
    val result = when(7){
        in 7..10 -> "Excellent" //7≤𝑥≥10
        5,6 -> "Good"
        3,4 -> "Pass"
        1,2,0 -> "Fail"
        else -> {
            println("Invalid Rating")
            "Invalid"
        }
    }
    println("result = $result")
```

### Loops

#### `for` loop

```kotlin
    val items = arrayOf("A", "B", "C", "D", "E")
    for (item in items) {
        print("$item, ")//A, B, C, D, E,
    }
    println()
    for (i in items.indices) {
        print("${items[i]}, ")//A, B, C, D, E,
    }
    println()
```

#### `forEach` loop

```kotlin
    val items = arrayOf("A", "B", "C", "D", "E")
    items.forEach { item -> print("$item, ") } //A, B, C, D, E,
    println()
    items.forEach { print("$it, ") }//A, B, C, D, E,
    println()
    items.forEachIndexed { index, value -> print("$index:$value|${items[index]}, ")}
    //0:A|A, 1:B|B, 2:C|C, 3:D|D, 4:E|E,
    println()
```

#### `Range`-based for Loop

```kotlin
    val items = arrayOf("A", "B", "C", "D", "E")
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
```

#### `while` loop

```kotlin
    val items = arrayOf("A", "B", "C", "D", "E")
    var i = 0
    while (i < 5) {
        print("$i, ") //1, 3, 5, 7, 9,
        i++
    }
    println()
    println("take input:")
    var name: String?
    do {
        name = readLine()
        println("name = $name")
    } while (name == null)
```

## Collection

### `listOf` - Immutable List

```kotlin
    var items = listOf("A", "B", "C", "D")
    println(items)
    println("1. The size of item = ${items.size}")
    println("2. items[1] = ${items[1]}")
    println("3. items.get(1) = ${items.get(1)}")
    println("4. indexOf('A') = ${items.indexOf("A")}")
    //[error]: items.add("X")// listOf is by default immutable
```

### `mutableListOf`

```kotlin
    items = mutableListOf("A", "B", "C", "D")
    println(items)//[A, B, C, D]

    //add:
    items.add("E")
    println(items)//[A, B, C, D, E]

    //removeAt(index):
    items.removeAt(1)
    println(items)//[A, C, D, E]

    //remove(val):
    var removed = items.remove("A")
    println(items)//[C, D, E]
    println("A removed?: $removed")//true
    removed = items.remove("Z")
    println(items)//[C, D, E]
    println("Z removed?: $removed")//false

    //set value:
    Color.printMsg(Color.CYAN_BRIGHT, "set(i,v):")
    items.set(1, "Y")
    items[0] = "X"
    println(items)//[X, Y, E]
```

### `Set` - Immutable Set

```kotlin
    var sets = setOf("A", "B", "C", "D", "D")
    println(sets)//[A, B, C, D]
    println("size: ${sets.size}")
    println("contains A?: ${sets.contains("A")}")//A
    //sets.add("ABC") [error] by default immutable
```

### `mutableSetOf:`

```kotlin
    sets = mutableSetOf("A", "B", "C", "D", "D")
    println(sets)//[A, B, C, D]

    //add()
    sets.add("E")
    println(sets)

    //remove()
    sets.remove("E")
    println(sets)
```

### `mapOf` - Immutable Map

```kotlin
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
```

### `mutableMapOf`

```kotlin
    map = mutableMapOf(1 to "A", 2 to "B", 3 to "C")

    //put(key,value)
    map.put(4,"E")
    println(map)//{1=A, 2=B, 3=C, 4=E}

    //remove(key)
    map.remove(2)
    println(map)//{1=A, 3=C, 4=E}
```

## Collection Operations

### Ex1: map,find

```kotlin
data class User(var id: String, var name: String)
data class Product(var id: String, var name: String)
data class CartItem(var productId: String, var qty: Int)
data class CartInfo(var userid: String, var cartItems: List<CartItem>)

val user = User("1", "John")

val products = listOf(
    Product("1", "iPhone"),
    Product("2", "iPad")
)

val cartItems = listOf(
    CartItem(productId = products[0].id, qty = 2),
    CartItem(productId = products[1].id, qty = 1)
)

var cartInfo = CartInfo(user.id, cartItems)

fun main() {
    println("CartInfo: $cartInfo")
    addToCart(user, products[1], 3)
    addToCart(user, Product("10", "Book"), 2)

}

fun addToCart(user: User, product: Product, qty: Int) {
    //find if product already exists in cart
    val cartItem = cartInfo.cartItems.find { it.productId == product.id }
    if (cartItem != null) {
        //update existing cart item
        val updatedCartItems = cartInfo.cartItems.map {
            if (it.productId == product.id) {
                it.copy(qty = it.qty + qty)
            } else {
                it
            }
        }
        cartInfo = cartInfo.copy(cartItems = updatedCartItems)
        println("Updated CartInfo: $cartInfo")
    } else {
        //add new cart item
        val newCartItem = CartItem(product.id, qty)
        val newCartItems = cartInfo.cartItems + newCartItem
        cartInfo = cartInfo.copy(cartItems = newCartItems)
        println("New CartInfo: $cartInfo")
    }
}
```
