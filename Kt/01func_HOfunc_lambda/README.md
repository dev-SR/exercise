# Kotlin Function, Higher-Order Function, Lambda

- [Kotlin Function, Higher-Order Function, Lambda](#kotlin-function-higher-order-function-lambda)
  - [Function](#function)
    - [Function Argument and Return Type](#function-argument-and-return-type)
    - [`Default` and `Named` argument](#default-and-named-argument)
      - [`Default Arguments` Functions](#default-arguments-functions)
      - [`Named Arguments` Functions](#named-arguments-functions)
    - [`Varargs` parameters](#varargs-parameters)
    - [Unit-returning Functions](#unit-returning-functions)
  - [HIGHER ORDER FUNCTIONS](#higher-order-functions)
    - [Function Types In Kotlin](#function-types-in-kotlin)
      - [Overview](#overview)
      - [Passing and returning functions](#passing-and-returning-functions)
      - [Type Alias🌟](#type-alias)
    - [Lambdas Expressions and Anonymous Functions](#lambdas-expressions-and-anonymous-functions)
    - [Lambda Expression](#lambda-expression)

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

## HIGHER ORDER FUNCTIONS

Kotlin language has a fantastic support for functional programming. Kotlin functions can be stored in variables and data structures, passed as arguments to and returned from other higher-order functions. Kotlin functions are first-class, which means that they can be stored in variables and data structures, passed as arguments to and returned from other higher-order functions. You can operate with functions in any way that is possible for other non-function values.

### Function Types In Kotlin

#### Overview

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

#### Passing and returning functions

Passing a `Callback` functions:

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
    // by :: function reference
    performOperation(2, 4, ::getSum)
    // by lambda
    performOperation(2, 4, { x, y -> y - x })
    // lambda - can be moved outside of parameter
    performOperation(2, 5) { x, y -> y - x }
    // by anonymous
    performOperation(2, 4, fun(x: Int, y: Int): Int = x * x)
}
```

Returning a functions:

```kotlin
// higher order function
fun getLength(): (String) -> Int {
    return fun(s: String): Int {
        return s.length
    }
    // return {s:String -> s.length}
    // return ::fn
}
```

```kotlin
val f: (String) -> Int = getLength()
println("Length is : ${f("Mark")}")
```

#### Type Alias🌟

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

### Lambda Expression

As we know, syntax of Kotlin lambdas is similar to Java Lambdas. A function without name is called anonymous function. Lambdas Expressions are essentially anonymous functions that we can treat as values – we can, for example, pass them as arguments to functions, return them, or do any other thing we could do with a normal object.

Syntax of Lambda expression:

```kotlin
val lambda_name : Data_type = { argument_List -> code_body }
```

