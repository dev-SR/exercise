# Kotlin Fundamental

- [Kotlin Fundamental](#kotlin-fundamental)
	- [String Concatenation using `+` and `${}`](#string-concatenation-using--and-)
	- [Declaring Variables in Kotlin](#declaring-variables-in-kotlin)
		- [`val` : cannot be reassigned](#val--cannot-be-reassigned)
		- [`var` : can be reassigned](#var--can-be-reassigned)
	- [Late initialization](#late-initialization)
	- [Null Safety in Kotlin](#null-safety-in-kotlin)
		- [Safe Call Operator (`?.`)](#safe-call-operator-)
		- [Not null assertion : `!!` Operator](#not-null-assertion---operator)
		- [Checking for `null` in conditions](#checking-for-null-in-conditions)
			- [Using Safe Call operator(`?.`)](#using-safe-call-operator)
			- [Elvis Operator(`?:`)](#elvis-operator)

## String Concatenation using `+` and `${}`

```kotlin
 var n = "Soikat"
    println("This is " + n.capitalize() + ", len: ${n.length}")
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

>> Error: Val cannot be reassigned!!

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
var v: String = "
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

Kotlin type system has distinguish two types of references that can hold `null` (nullable references) and those that can not (non-null references). A variable of type `String` **can not hold** `null`. If we try to assign `null` to the variable, it gives compiler error.

```kotlin
var s1: String = "Hello World"
    s1 = null // compilation error
```

### Safe Call Operator (`?.`)

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

### Not null assertion : `!!` Operator

The not null assertion (`!!`) operator converts **`any` value to a `non-null` type** and **throws an exception** if the value is `null`. If anyone want `NullPointerException` then he can ask explicitly using this operator.

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

#### Using Safe Call operator(`?.`)

Null Comparisons are simple but number of nested `if-else` expression could be burdensome. So, Kotlin has a Safe call operator, `?.` that reduces this complexity and execute an action only when the specific reference holds a `non-null` value. It allows us to combine a `null-check` and a method call in a single expression.

The following expression:

```kotlin
name?.toUpperCase()
```

is equivalent to:

```kotlin
if(name != null)
    name.toUpperCase()
else
    null
```

```kotlin
 // Using Safe Call operator(?.)
    var name: String? = "Soikat"
    println(name?.toUpperCase())
    /*  is equivalent to:
        if(name != null)
            name.toUpperCase()
        else
            null
    */
```

#### Elvis Operator(`?:`)

The Elvis operator is used to return

- a `non-null` value or
- a `default value` when the original variable is null.

In other words, if left expression is not null then elvis operator returns it, otherwise it returns the right expression. The right-hand side expression is evaluated only if the left-hand side found to be null.
The following expression:

 The following expression:

```kotlin
val name = firstName ?: "Unknown"
```

is equivalent to:

```kotlin
val name = if(firstName!= null)
         firstName
      else
         "Unknown"
```

```kotlin
 var s:String? = null
    var size: Int = s?.length ?: 0
    println(size)//0
    s = "Hello World"
    size = s?.length ?: 0
    println(size)//11
```
