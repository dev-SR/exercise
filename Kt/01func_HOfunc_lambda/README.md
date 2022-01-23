# Kotlin Function, Higher-Order Function, Lambda

- [Kotlin Function, Higher-Order Function, Lambda](#kotlin-function-higher-order-function-lambda)
  - [Function](#function)
    - [Function Argument and Return Type](#function-argument-and-return-type)
    - [`Default` and `Named` argument](#default-and-named-argument)
      - [`Default Arguments` Functions](#default-arguments-functions)
      - [`Named Arguments` Functions](#named-arguments-functions)
    - [`Varargs` parameters](#varargs-parameters)
    - [Unit-returning Functions](#unit-returning-functions)
  - [Functional Programming](#functional-programming)
    - [Function Types](#function-types)
    - [Function Types for High Order Functions](#function-types-for-high-order-functions)
      - [Passing function as a parameter to Higher-Order function:`Callbacks`](#passing-function-as-a-parameter-to-higher-order-functioncallbacks)
      - [Returning a function from Higher-Order function](#returning-a-function-from-higher-order-function)
    - [🌟Type Alias🌟 for Function Types](#type-alias-for-function-types)
    - [Lambdas Expressions and Anonymous Functions](#lambdas-expressions-and-anonymous-functions)
    - [Lambda Expression](#lambda-expression)
      - [Type declaration in lambdas](#type-declaration-in-lambdas)
      - [`it`: implicit name of a single parameter](#it-implicit-name-of-a-single-parameter)
      - [Lambda argument should be moved out of parentheses](#lambda-argument-should-be-moved-out-of-parentheses)
    - [Anonymous Function](#anonymous-function)
    - [Closures](#closures)
  - [Extension function and Receiver type](#extension-function-and-receiver-type)
    - [Extension Function](#extension-function)
    - [Receiver](#receiver)
      - [Defining A function type with receiver](#defining-a-function-type-with-receiver)

## Function

### Function Argument and Return Type

```kotlin
fun square(number: Int): Int {
    return number * number
}

fun square1(n: Int): Int = n * n

fun square2(n: Int): Int = if (n > 0) n * n else -1

fun main() {
    println(square(2))
    println(square1(2))
    println(square2(0))
}
```

### `Default` and `Named` argument

In most of the programming languages, we need to specify all the arguments that a function accepts while calling that function but in Kotlin, we need not specify all the arguments that a function accepts while calling that function so it is one of the most important features. We can get rid of this constraint and make parameter optional i.e pass an argument or not while calling a function.

There are two types of arguments in Kotlin –

- Default arguments
- Named arguments

#### `Default Arguments` Functions

The arguments which need not specify explicitly while calling a function are called **default** arguments. If the function is called without passing arguments then the default arguments are used as function parameters. In other cases, if arguments are passed during a function call then passed arguments are used as function parameters.

There are three cases for default arguments:

- No arguments are passed while calling a function
- Partial arguments are passed while calling a function
- All arguments are passed while calling a function

```kotlin
fun displayTitleAndName(name: String, title: String = "Dr." ) {
    println("$title $name")
}
//passing no arguments while calling student
displayTitleAndName()//Dr. John
//passing partial arguments
displayTitleAndName("Karim")//Dr. Karim
//passing all the arguments
displayTitleAndName("Karim", "Mr.")//Mr. Karim
```

#### `Named Arguments` Functions

While working with the default arguments we face a problem. If we jumble the arguments then it will give compilation error so we have to pass the actual arguments to formal arguments in the same order as defined during function declaration.

```kotlin
fun student( name: String="Rahim", student_id: Int=191902061) {
    println("$name $student_id")
}

// calling student() by passing arguments in random order-
student(191, "Rahim")
```

```bash
ERROR: The integer literal does not conform to the expected type String
```

In the above program, we have not passed the arguments in the order as these were defined in the function. So, it gives compilation error.

The arguments that are passed using name while calling a function are called **named arguments**. While calling the function we must use the name of the formal argument to which we are passing the actual argument value.

Kotlin program for calling student() with name of arguments –

```kotlin
student(student_id = 191, name = "Karim")//Karim 191
```

### `Varargs` parameters

Varargs allow you to pass any number of arguments by separating them with commas.

```kotlin
fun varargExample(vararg names: Int) {
    print("Argument has ${names.size} elements: ")
    names.forEach { print("$it, ") }
    println()
}

    varargExample() // => Argument has 0 elements:
    varargExample(1) // => Argument has 1 elements:1,
    varargExample(1, 2, 3) // => Argument has 3 elements: 1, 2, 3
```

### Unit-returning Functions

If a function **does not return** a useful value, its return type is `Unit`. Unit is a type with only one value which is `Unit`.

```kotlin
fun sumTwo(a:Int, b:Int):Unit{
   val x = a + b

   println( x )
}
//The `Unit` return type declaration is also optional. The above code is equivalent to:

fun sumTwo(a:Int, b:Int){
   val x = a + b

   println( x )
}
```

## Functional Programming

Kotlin language has a fantastic support for functional programming. Kotlin functions can be stored in variables and data structures, passed as arguments to and returned from other higher-order functions. Kotlin functions are first-class, which means that they can be stored in variables and data structures, passed as arguments to and returned from other higher-order functions. You can operate with functions in any way that is possible for other non-function values.

`High Order Functions` = A `function` that can **accept a function as a parameter** or can **return a function**.

### Function Types

We know data types. Similarly, we have function type too in kotlin.

Signature / Syntax

```bash
    Name: (only comma separated data types) -> return data type
    ft: (Int, Int) -> Int
```

```kotlin
fun main() {
    //Function Types 1️⃣
    var f0: () -> Unit
    var f1: (Int, Int) -> Int
    var f2: (Int, Int) -> Boolean
    //nullable
    var f3: ((String) -> Int)?


    //Assignment 2️⃣
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

    // Function Call 3️⃣
    println(f3("Hello"))
    println(f3.invoke("Hello"))//using invoke
    f3 = null
    f3?.invoke("Hello")

    // Other type of Function Declarations ✔️
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
```

### Function Types for High Order Functions

#### Passing function as a parameter to Higher-Order function:`Callbacks`

```kotlin
// higher order function
fun performOperation(x: Int, y: Int, cbFn: (Int, Int) -> Int) {
    val result = cbFn(x, y)
    println("Result of $x and $y is : $result")
}

fun getSum(x: Int, y: Int): Int {
    return x + y
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
    // Also,
    val getSum3 = fun (x: Int, y: Int): Int {
        return x + y
    }
    performOperation(2,4,getSum3)
}
```

#### Returning a function from Higher-Order function

```kotlin
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
```

```kotlin
val f: ((Int, Int) -> Int) = returnAddFunction()
println("Result is : ${f(2, 3)}")
```

### 🌟Type Alias🌟 for Function Types

- Need to be declared at top level
- The don't create a new type
- Not only for function type but also for any type

```kotlin
typealias addFunctionType = (Int, Int) -> Int
typealias sumResult = Int
//fun printSum(x: Int, y: Int, fn: (Int, Int) -> Int) {
fun printSum(x: Int, y: Int, fn: addFunctionType) {
    val sum: sumResult = fn(x, y)
    println("Sum of $x and $y is: $sum")
}


printSum(2, 4) { x, y -> x + y }
```

### Lambdas Expressions and Anonymous Functions

Lambdas expression and Anonymous function both are **function literals** means these functions are not declared but passed immediately as an expression.

`Function literal`:

Signature / Syntax: 1

```kotlin
{ comma separated pascal parameters -> business logic }
```

Example:

```kotlin
{ x: Int, y: Int -> x + y }
```

### Lambda Expression

As we know, syntax of Kotlin lambdas is similar to Java Lambdas. A function without name is called anonymous function. Lambdas Expressions are essentially anonymous functions that we can treat as values – we can, for example, pass them as arguments to functions, return them, or do any other thing we could do with a normal object.

Syntax of Lambda expression:

```kotlin
val lambda_name : Data_type = { argument_List -> code_body }
```

- A lambda expression or an `anonymous` function is a `“function literal”`,
  - i.e. **a function that is not declared, but passed immediately as an expression**
- A lambda expression is always surrounded by curly braces `{}`
- Its `parameters` (if any) are declared before `->` (parameter types may be omitted)
- The `body` goes after `->` (when present)

```kotlin
fun main() {
    val f0: (Int, Int) -> Int = { x: Int, y: Int -> x + y }
    println(f0(1, 2))
    val f1 = { x: Int, y: Int -> x + y }
    // val f2 = { x, y-> x + y } [error] Cannot infer a type for this parameter. Please specify it explicitly.

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
    val calculateGrade = { grade : Int ->
        when(grade) {
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
```

#### Type declaration in lambdas

We must explicitly declare the type of our lambda expression.

- If lambda returns no value then we can use: `Unit`
- Pattern: `(Input) -> Output`

```kotlin
    val f = { x: Int, y: Int -> x + y } //OK
    val f = { x, y-> x + y } // [error] Cannot infer a type for this parameter. Please specify it explicitly.
    val f: (Int, Int) -> Int = { x, y -> x + y } //OK
```

#### `it`: implicit name of a single parameter

In most of cases lambdas contains the single parameter. Here, it is used to represent the single parameter we pass to lambda expression.

```kotlin
    val f: (String) -> Int = { s: String -> s.length }
    val f: (String) -> Int = { it.length }
    f("abc") // 3
```

#### Lambda argument should be moved out of parentheses

```kotlin
fun Callback(x: Int, fn: (Int) -> Unit) {
    fn(x + 1)
}

// passing lambda as argument
Callback(10, { x -> println(x) })
Callback(10) { x -> println(x) }
```

### Anonymous Function

An anonymous function is very similar to regular function except for the name of the function which is omitted from the declaration. The body of the anonymous function can be either an `expression` or `block`.

Example 1: Function body as an `expression`

```kotlin
fun(a: Int, b: Int) : Int = a * b
```

Example 2: Function body as a `block`

```kotlin
fun(a: Int, b: Int): Int {
    val mul = a * b
    return mul
}
```

Return type and parameters:

- The return type and parameters are also specified in same way as for regular function but we can omit the parameters if they can be inferred from the context.
- The return type of the function can be inferred automatically from the function if it is an expression and has to be specified explicitly for the anonymous function if it is body block.

```kotlin
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
```

### Closures

Closures are functions that can access and modify properties defined outside the scope of the function.

The following closure function(`fn`) is a high order function and updates a property (`counter`) defined outside it's scope (inside `printNext` fn).

```kotlin
fun printNext(): () -> Unit {
    var counter = 0
    return fun() {
        counter++
        println(counter)
    }
}

    val fn = printNext()
    fn()//1
    fn()//2
    fn()//3
```

The following closure function(`forEach`) is a high order function that calculates the sum of all elements of the list and updates a property defined outside the closure (inside `main` fn).

```kotlin
fun main() {
    var res = 0
    var myList = listOf(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
    myList.forEach { res += it }
    println(res) //
}
```

## Extension function and Receiver type

In Kotlin it is possible to add a method (called member function in Kotlin) to an existing class. This is called an **extension function**.

It is also possible to access a member function from a class inside a function literal. This is called a **function literal with receiver**.

### Extension Function


Syntax:

In order to create an extension function, we write the class name (also known as a receiver type) followed by a dot, followed by our function as below:

```kotlin
//Here, OurClassName is called a receiver type
fun OurClassName.ourExtensionFunction
```



Say you want to add a new member function to the `String` class, e.g. `thankYou()` that prints thank you massage. Because `String` is in the Java SDK, we cannot modify it. In Kotlin we can define an extension function that extends an existing class like `String` with a new member function.

We define the `thankYou()` extension function as follows:

For example:

```kotlin
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

fun main() {
    "Soikat".thankYou()//Thank You Soikat
}
```

### Receiver

We have seen a receiver type in an extension function. Similarly, a **function type, function literal, lambda expression** and an **anonymous function** can also have a receiver type.

#### Defining A function type with receiver

Where with extension functions you can add a new member function to an existing class, with a function literal with receiver you can access the **member functions of an existing class inside** (`append` from `StringBuilder` class) the lambda block (inside the curly braces `{}`) by defining a A Function Type - by which compiler knows which class you are refereeing to.

Syntax/Signature of a function type with receiver:

```kotlin
ft: Int.(Int) -> Int // Here, the receiver type is: Int
```

Let's create a function literal with receiver that adds the string "s" to a string using the `StringBuilder` class.

```kotlin
    val appendS: StringBuilder.() -> StringBuilder = { this.append("s") }
    val s = StringBuilder("The Boy").appendS()
    println(s.toString())//The Boys
```

Function `Type` for the following expression:

`val s = StringBuilder("The Boy").appendS()`

is:

`StringBuilder.() -> StringBuilder`

because we are extending `StringBuilder` class with `appendS` function that takes No parameter - `()`.
So, as a whole the function type is `StringBuilder.()`

And it returns object of `StringBuilder`, denoted by `-> StringBuilder`

So after defining the function type, we can use it (i.e `append` function) in the lambda expression.

Again, `this` refers to the `StringBuilder` object, so we **omit** it:

```kotlin
    val appendS1: StringBuilder.() -> StringBuilder = { append("s") }
    val ss = StringBuilder("The Boy").appendS1()
    println(ss.toString())
```

More Example:

```kotlin
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
        // fun Int.(num: Int): Unit = println("The sum of $this and $$num is ${plus(num)}")
    val y = 6
    y.printSum1(5)//The sum of 6 and 5 is 11
```
